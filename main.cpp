#include <iostream>
#include <adder.h>
#include <GLFW/glfw3.h>
#include <CPPTESTConfig.h>

int main(int argc, char *argv[]){

    std::cout << "Hello world!\n";
    std::cout << israelmath::add(72.1f, 73.8f) << "\n";

    std::cout << argv[0] << " Version" << CPPTEST_VERSION_MAJOR << "." << CPPTEST_VERSION_MINOR << std::endl;

    GLFWwindow *window;

    if(!glfwInit()){
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE);
    }

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    while( !glfwWindowShouldClose(window) )
    {

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
}