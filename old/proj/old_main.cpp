#include <iostream>
#include <string>
#include <adder.h>

#include <iostream>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <conio.h>  // Windows-specific key detection
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// Function to set terminal to non-blocking mode
void setNonBlockingInput(bool enable) {
    termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if (enable) {
        tty.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echo
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);  // Non-blocking read
    } else {
        tty.c_lflag |= (ICANON | ECHO);  // Enable canonical mode and echo
        fcntl(STDIN_FILENO, F_SETFL, 0);  // Blocking read
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

// Function to check if a key has been pressed (Linux version)
bool _kbhit() {
    char ch;
    int n = read(STDIN_FILENO, &ch, 1);
    if (n > 0) {
        return true;  // A key was pressed
    }
    return false;  // No key was pressed
}
#endif

void LoopPress() {
    const int targetFPS = 60;
    const std::chrono::milliseconds frameDuration(1000 / targetFPS);
    
    int counter = 0;

#ifdef __linux__
    setNonBlockingInput(true);  // Enable non-blocking input on Linux
#endif

    while (true) {
        // Check for keypress
        if (_kbhit()) {
            break;
        }

        // Loop body
        std::cout << "Iteration: " << ++counter << std::endl;

        // Sleep for the remaining time to maintain 60 FPS
        std::this_thread::sleep_for(frameDuration);
    }

    std::cout << "Exiting program..." << std::endl;

#ifdef __linux__
    setNonBlockingInput(false);  // Restore terminal settings
#endif

}

void Trim(int argc, char** argv) {

    int count = 1;

    std::string name;

    while(count < argc) {
        name += argv[count++];
    }

    name.erase(0, name.find_first_not_of(' \t\n\r\f\v'));
    name.erase(name.find_last_not_of(' \t\n\r\f\v') + 1);
    std::cout << name << std::endl;
}

int Adder() {
    return israelmath::add(2, 3);
}

int main(int argc, char** argv) {
    //std::cout << "Hello!" << std::endl;
    //Trim(argc, argv);
    std::cout << Adder() << std::endl;
    LoopPress();
    return 0;
}