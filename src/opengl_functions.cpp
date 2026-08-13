#include "opengl_functions.h"

GLFWwindow *init_opengl(float window_w, float window_h)
{
    GLFWwindow* window = nullptr;

    // Init OpenGL 
    if (!glfwInit())
    {
        std::cout << "Failed to Init GLFW - main.cpp" << std::endl;
        return nullptr;
    }

    // Create window 
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    window = glfwCreateWindow(window_w, window_h, "OpenGL", nullptr, nullptr);

    // Check that window created
    if (!window)
    {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return nullptr;
    }

    // Set context
    glfwMakeContextCurrent(window);

    // Load OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return nullptr;
    }

    return window;
}


