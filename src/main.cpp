// Include libs
#include "config.h"
#include <View/render.h>

GLFWwindow* init_opengl(float window_w, float window_h);


std::vector<float> get_positions()
{
    return std::vector<float>{
        -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,  // TOP LEFT BACK       0     RED
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,  // TOP LEFT FRONT       1     RED

        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,   // TOP RIGHT BACK      2     GREEN
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,   // TOP RIGHT FRONT      3     GREEN


        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  // BOTTOM LEFT BACK   4     BLUE
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  // BOTTOM LEFT FRONT   5     BLUE

        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f,   // BOTTOM RIGHT BACK  6     BLACK
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f,   // BOTTOM RIGHT FRONT  7     BLACK
    };
}
std::vector<uint32_t> get_elements()
{
    return std::vector<uint32_t>{
        // Front
        0, 1, 3,
        3, 2, 0, 
        
        // Back
        5, 4, 6, 
        6, 7, 5,

        // Left
        4, 0, 2,
        2, 6, 4,

        // Right
        1, 5, 7,
        7, 3, 1,

        // Top
        2, 3, 7,
        7, 6, 2,

        // Bottom
        4, 5, 1,
        1, 0, 4,
    };
}

int main()
{
    // data 
    unsigned int window_w = 1280;
    unsigned int window_h = 720;
    float aspect_ratio = (float) window_w / (float) window_h;    
    float pov = 45; 
    float near = 0.01f;
    float far = 100.0f;

    GLFWwindow* window = init_opengl(window_w, window_h);

    // Meneger
    MeshesManager manager;
    manager.create_mesh("Cube", get_positions(), get_elements());
    manager.get_mesh("Cube")->upload();

    // Scene
        // Create object data

    Scene scene;
    scene.add_object(
        std::make_shared<Object>(
            manager.get_mesh("Cube"),
            Transform(glm::vec3(-1.5f, -1.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)), 
            std::make_shared<Shader>("../src/shaders/vertex.txt", "../src/shaders/fragment.txt")
        )
    );

        scene.add_object(
        std::make_shared<Object>(
            manager.get_mesh("Cube"),
            Transform(glm::vec3(1.5f, 1.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)), 
            std::make_shared<Shader>("../src/shaders/vertex.txt", "../src/shaders/fragment.txt")
        )
    );


    

    // Render
    Render render(aspect_ratio, pov, near, far);
    render.camera.set_camera_pos(glm::vec3(30.0f, 30.0f, 30.0f));
    render.camera.set_camera_target(glm::vec3(0.0f, 0.0f, 0.0f));


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        // poll the events
        glfwPollEvents();

        // Clear window
        glClearColor(0.25f, 0.5f, 0.75f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        scene.get_object(0)->transform.rotation = glm::vec3(1.0f, 1.0f, 0.0f) * 5.0f * glfwGetTime();
        scene.get_object(1)->transform.rotation = glm::vec3(1.0f, 1.0f, 0.0f) * 5.0f * glfwGetTime();



        render.render(scene);


        // Update the window 
        glfwSwapBuffers(window);
    }


    // Delete stuff

    // Terminate glfw
    glfwTerminate();
    return 0;
}

GLFWwindow* init_opengl(float window_w, float window_h){
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