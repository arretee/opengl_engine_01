#include "View/shader.h"


// -------------------- Constructor Destructor --------------------
Shader::Shader(const std::string& vertex_filepath, const std::string& fragment_filepath) {

    // Create shader and load it into a GPU
    std::vector<uint32_t> modules;

    modules.push_back(compile_shader(GL_VERTEX_SHADER, load_file(vertex_filepath)));
    modules.push_back(compile_shader(GL_FRAGMENT_SHADER, load_file(fragment_filepath)));

    uint32_t shader = glCreateProgram();
    for (uint32_t shaderModule : modules)
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

        glDeleteProgram(shader);
        throw std::runtime_error(errorLog);
    }


    // Deleting the modules
    for (unsigned int shaderModule : modules)
    {
        glDeleteShader(shaderModule);
    }


    program_id = shader;    // Save the shader ID
}

Shader::~Shader() { 
    glDeleteProgram(program_id);
}


// -------------------- Methods --------------------
void Shader::use() const {
    glUseProgram(program_id);
}


// -------------------- Uniforms --------------------
GLint Shader::get_uniform_location(const std::string& name) {
    GLint location = 0;

    auto it = uniform_cache.find(name);

    if(it == uniform_cache.end())
    {   
        location = glGetUniformLocation(program_id, name.c_str());
        if (location == -1) {
            std::cout << "Shader error: uniform not found - " << name << std::endl;
            return -1;
        }

        uniform_cache[name] = location;
    }
    else
    {
        location = it->second;
    }


    return location;
}


void Shader::set_bool(const std::string& name, bool value) {
    GLint location = get_uniform_location(name);
    glUniform1i(location, value);
}
void Shader::set_int(const std::string& name, int value) {
    GLint location = get_uniform_location(name);
    glUniform1i(location, value);
}
void Shader::set_float(const std::string& name, float value) { 
    GLint location = get_uniform_location(name);
    glUniform1f(location, value);
}
void Shader::set_mat4(const std::string& name, const glm::mat4& mat) {
    GLint location = get_uniform_location(name);
    glUniformMatrix4fv(location, 1, GL_FALSE, mat.entries);
}
void Shader::set_vec3(const std::string& name, const glm::vec3& vec) { 
    GLint location = get_uniform_location(name);
    glUniform3fv(location, 1, vec.entries);
}



// -------------------- Load and Complile --------------------
std::string Shader::load_file(const std::string& path) {
    std::ifstream file;
    std::stringstream bufferLines;
    std::string line;


    file.open(path);

    // Open and read a file
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open shader file: " + path);
    }
    
    while (std::getline(file, line)) {
        bufferLines << line << "\n";
    }

    file.close();


    return bufferLines.str();
}

GLuint Shader::compile_shader(GLuint type, const std::string& source) { 
    // Convert CPP string into a C string 
    const char* shaderSrc = source.c_str();

    
    // Create  shader module and attach it and compile it 
    GLuint shaderModule = glCreateShader(type);
    glShaderSource(shaderModule, 1, &shaderSrc, nullptr);
    glCompileShader(shaderModule);

    // Check if shader compiled
    int status;
    glGetShaderiv(shaderModule,GL_COMPILE_STATUS, &status);

    if (!status){
        char errorLog[1024];
        glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);

        glDeleteShader(shaderModule);
        throw std::runtime_error(errorLog);
    }

    return shaderModule;
}