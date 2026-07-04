// Include libs
#include "config.h"
#include <View/render.h>

GLFWwindow* init_opengl(float window_w, float window_h);

/*Temp*/
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

void create_object(Scene* scene, std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader, glm::vec3 pos){
    scene -> add_object(
        std::make_shared<Object>(
            mesh,
            Transform(pos, glm::vec3(1.0f, 1.0f, 1.0f)), 
            shader)
        );
}
/*Temp*/

int main()
{
    // data 
    unsigned int window_w = 1280;
    unsigned int window_h = 720;
    float aspect_ratio = (float) window_w / (float) window_h;    
    
    float pov = 45; 
    float near = 0.01f;
    float far = 10000.0f;

    // FPS Count 
    unsigned int frames_num = 0;
    unsigned int time = 0;

    GLFWwindow* window = init_opengl(window_w, window_h);
    
    MeshesManager manager;
    std::shared_ptr<Shader> shader = std::make_shared<Shader>("../src/shaders/vertex.txt", "../src/shaders/fragment.txt");
    
    Scene scene;
    Render render(aspect_ratio, pov, near, far);





    // Meneger
    manager.create_mesh("Cube", get_positions(), get_elements());
    manager.get_mesh("Cube")->upload();


    // Create temp scene, sphere of cubes 
    for (int i = -50; i < 51; i++)
    {
        // x z
        create_object(&scene, manager.get_mesh("Cube"), shader, glm::vec3(i * 10.0f, 0.0f, (50 - abs(i)) * 10.0f));
        create_object(&scene, manager.get_mesh("Cube"), shader, glm::vec3(i * 10.0f, 0.0f, (50 - abs(i)) * -10.0f));

        // x y
        create_object(&scene, manager.get_mesh("Cube"), shader, glm::vec3(i * 10.0f, (50 - abs(i)) * 10.0f, 0.0f));
        create_object(&scene, manager.get_mesh("Cube"), shader, glm::vec3(i * 10.0f, (50 - abs(i)) * -10.0f, 0.0f));

        // z y
        create_object(&scene, manager.get_mesh("Cube"), shader, glm::vec3(0.0f, i * 10.0f, (50 - abs(i)) * 10.0f));
        create_object(&scene, manager.get_mesh("Cube"), shader, glm::vec3(0.0f, i * 10.0f, (50 - abs(i)) * -10.0f));
    }
    

    // Render -> configure camera start pos and direction
    render.camera.set_camera_pos(glm::vec3(1500.0f, 0.0f, 1500.0f));
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

        // Get user input
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }

        // Camera rotation
        if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            render.camera.process_mouse(-1, 0, 0.0015);
        }
        if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            render.camera.process_mouse(0, 1, 0.0015);
        }
        if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            render.camera.process_mouse(0, -1, 0.0015);
        }
        if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            render.camera.process_mouse(1, 0, 0.0015);
        }

        // Camera move

        

        // Clear window
        glClearColor(0.25f, 0.5f, 0.75f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        
        // rotate objects
        for(int i = 0; i < scene.get_objects().size(); i++)
            scene.get_object(i)->transform.rotation = glm::vec3(1.0f, 1.0f, 0.0f) * 15.0f * glfwGetTime();


        // Render the scene
        render.render(scene);


        // Update the window 
        glfwSwapBuffers(window);



        // FPS Counter
        frames_num++;
        if (time != (int)glfwGetTime())
        {
            std::cout << "FPS: " << frames_num << std::endl;

            time = glfwGetTime();
            frames_num = 0;
        }
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