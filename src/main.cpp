// Include libs
#include "config.h"

unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath);
unsigned int make_module(const std::string& filepath, unsigned int module_type);

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
    // window data 
    GLFWwindow* window = nullptr;

    unsigned int window_w = 1280;
    unsigned int window_h = 720;
    float aspect_ratio = (float) window_w / (float) window_h;    


    // Init OpenGL 
    if (!glfwInit())
    {
        std::cout << "Failed to Init GLFW - main.cpp" << std::endl;
        return -1;
    }

    // Create window 
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    window = glfwCreateWindow(window_w, window_h, "OpenGL", nullptr, nullptr);

    // Check that window created
    if (!window)
    {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }

    // Set context
    glfwMakeContextCurrent(window);

    // Load OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }


    // Create shader
    unsigned int shader = make_shader(
        "../src/shaders/vertex.txt",
        "../src/shaders/fragment.txt"
    );

    // Use correct shader
    glUseProgram(shader);



    // Translation data
    MeshesManager manager;

    // Create object
    manager.create_mesh("Cube", get_positions(), get_elements());
    manager.get_mesh("Cube")->upload();
    Transform t = Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    t.scale = glm::vec3(0.5f, 0.5f, 0.5f);
    Object cube = Object(
        manager.get_mesh("Cube"),
        t, 
        std::make_shared<Shader>("../src/shaders/vertex.txt", "../src/shaders/fragment.txt")
    );

    // View Data
    Camera camera;
    camera.set_camera_pos(glm::vec3(10.0f, 5.0f, 20.0f));
    camera.set_camera_target(glm::vec3(0.0f, 0.0f, 0.0f));

    // Projection
    float pov = 45; 
    float near = 0.01f;
    float far = 100.0f;


    // translation + rotation + view matrix
    glm::mat4 vrt = cube.transform.get_matrix() * camera.get_view_matrix();
    unsigned int vrt_location = glGetUniformLocation(shader, "vrt");


    // Projection
    glm::mat4 projection = glm::create_projection_matrix(aspect_ratio, pov, near, far);
    unsigned int projection_location = glGetUniformLocation(shader, "projection");
    glUniformMatrix4fv(projection_location, 1, GL_FALSE, projection.entries);
    std::cout << "projection "; projection.print_gl(); std::cout << std::endl;


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        glUseProgram(shader);   

        // poll the events
        glfwPollEvents();


        // Clear window
        glClearColor(0.25f, 0.5f, 0.75f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update cube.transform
        cube.transform.rotation = glm::vec3(20.0f, 5.0f, 5.0f) * 5 * glfwGetTime();


        // Update vrt 
        vrt = camera.get_view_matrix() * cube.transform.get_matrix();
        glUniformMatrix4fv(vrt_location, 1, GL_FALSE, vrt.entries);

        // update projection
        projection = glm::create_projection_matrix(aspect_ratio, pov, near, far);
        glUniformMatrix4fv(projection_location, 1, GL_FALSE, projection.entries);


        // Draw
        cube.mesh->draw(GL_TRIANGLES);

        // Update the window 
        glfwSwapBuffers(window);
    }


    // Delete stuff
    glDeleteProgram(shader);

    // Terminate glfw
    glfwTerminate();
    return 0;
}

/*
    Function is linking shaders

    input: vertext_filepath, fragment_filepath
    output: shader
*/
unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath) {

    std::vector<unsigned int> modules;

    modules.push_back(make_module(vertex_filepath, GL_VERTEX_SHADER));
    modules.push_back(make_module(fragment_filepath, GL_FRAGMENT_SHADER));

    unsigned int shader = glCreateProgram();
    for (unsigned int shaderModule : modules)
    {
        glAttachShader(shader, shaderModule);
    }
    glLinkProgram(shader);


    // Check for errors on linking
    int status;
    glGetProgramiv(shader, GL_LINK_STATUS, &status);

    if (!status){
        char errorLog[1024];
        glGetProgramInfoLog(shader, 1024, NULL, errorLog);
        std::cout << "Shader Linking error:\n" << errorLog << std::endl;
    }


    // Deleting 
    for (unsigned int shaderModule : modules)
    {
        glDeleteShader(shaderModule);
    }

    return shader;
 }

/*
    Function is making a module from a file

    input: file path(string ref), file type(int)
    output: module
*/
unsigned int make_module(const std::string& filepath, unsigned int module_type){
    std::ifstream file;
    std::stringstream bufferLines;
    std::string line;

    // Open and read a file
    file.open(filepath);
    
    while (std::getline(file, line)) {
        bufferLines << line << "\n";
    }

    file.close();

    // Convert buffer to string and eraise the buffer
    std::string shaderSource = bufferLines.str();
    bufferLines.str("");

    // Convert CPP string into a C string 
    const char* shaderSrc = shaderSource.c_str();

    
    // Create  shader module and attach it and compile it 
    unsigned int shaderModule = glCreateShader(module_type);
    glShaderSource(shaderModule, 1, &shaderSrc, NULL);
    glCompileShader(shaderModule);

    // Check if shader compiled
    int status;
    glGetShaderiv(shaderModule,GL_COMPILE_STATUS, &status);

    if (!status){
        char errorLog[1024];
        glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);
        std::cout << "Shader Module compilation error:\n" << errorLog << std::endl;
    }

    return shaderModule;
}