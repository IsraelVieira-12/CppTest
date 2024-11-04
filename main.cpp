#include <iostream>
#include "Adder/adder.h"
#include <GLFW/glfw3.h>

int main(){
    std::cout << "Hello world!\n";

    std::cout << israelmath::add(72.1f, 73.8f) << "\n";

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