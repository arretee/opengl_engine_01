// Include libs
#include "config.h"

unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath);
unsigned int make_module(const std::string& filepath, unsigned int module_type);


int main()
{
    // window data 
    GLFWwindow* window = nullptr;

    unsigned int window_w = 1280;
    unsigned int window_h = 720;
    float aspect_ratio = (float) window_w / (float) window_h;    


    // Translation data
    glm::vec3 trans_pos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 trans_move_dir = glm::vec3(0.0f, 0.0f, 1.0f);
    float speed = 0.0 / 1000;


    // Rotation data
    float rotation_speed = 10; 


    // View Data
    glm::vec3 cam_pos = glm::vec3(-20.0f, 0.0f, 10.0f);
    glm::vec3 cam_target = trans_pos;


    // Projection
    float pov = 45; 
    float near = 0.01f;
    float far = 100.0f;


    // Init OpenGL 
    if (!glfwInit())
    {
        std::cout << "Failed to Init GLFW - main.cpp" << std::endl;
        return -1;
    }

    // Create window 
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


    // Create triangle
    TriangleMesh* triangle = new TriangleMesh();    


    // translation
    glm::mat4 translation = glm::create_traslation_matrix(trans_pos);
    unsigned int translation_location = glGetUniformLocation(shader, "translation");
    glUniformMatrix4fv(translation_location, 1, GL_FALSE, translation.entries);
    std::cout << "translation "; translation.print_gl(); std::cout << std::endl;

    
    // rotation
    glm::mat4 rotation = glm::create_rotation_z_matrix(rotation_speed * glfwGetTime());
    unsigned int rotation_location = glGetUniformLocation(shader, "rotation");
    glUniformMatrix4fv(rotation_location, 1, GL_FALSE, rotation.entries);
    std::cout << "rotation "; rotation.print_gl(); std::cout << std::endl;


    // View
    glm::mat4 view = glm::create_view_transform_matrix(cam_pos, cam_target);
    unsigned int view_location = glGetUniformLocation(shader, "view");
    glUniformMatrix4fv(view_location, 1, GL_FALSE, view.entries);
    std::cout << "view "; view.print_gl(); std::cout << std::endl;


    // View
    glm::mat4 projection = glm::create_projection_matrix(aspect_ratio, pov, near, far);
    unsigned int projection_location = glGetUniformLocation(shader, "projection");
    glUniformMatrix4fv(projection_location, 1, GL_FALSE, projection.entries);
    std::cout << "projection "; projection.print_gl(); std::cout << std::endl;


    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        glUseProgram(shader);   

        // poll the events
        glfwPollEvents();

        // Move the triangle
        trans_pos = trans_pos + (trans_move_dir * speed * glfwGetTime());
        cam_target = trans_pos;

        // Clear window
        glClearColor(0.25f, 0.5f, 0.75f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Update translation 
        translation = glm::create_traslation_matrix(trans_pos);
        glUniformMatrix4fv(translation_location, 1, GL_FALSE, translation.entries);

        // Update rotation
        rotation = glm::create_rotation_z_matrix(rotation_speed * glfwGetTime());
        glUniformMatrix4fv(rotation_location, 1, GL_FALSE, rotation.entries);

        // Update View 
        view = glm::create_view_transform_matrix(cam_pos, cam_target);
        glUniformMatrix4fv(view_location, 1, GL_FALSE, view.entries);

        // update projection
        projection = glm::create_projection_matrix(aspect_ratio, pov, near, far);
        glUniformMatrix4fv(projection_location, 1, GL_FALSE, projection.entries);


        // Draw
        triangle->draw();

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