#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <unordered_map>

#include "glmath/mat4.h"
#include "glmath/vec3.h"


class Shader{
    private:
        uint32_t program_id;
        std::unordered_map<std::string, GLint> uniform_cache;

        GLint get_uniform_location(const std::string& name);

        /*
            Function loads file to memory into a std::string var

            input: path of the file
            output: file content in std::string
        */
        std::string load_file(const std::string& path);
        
        /*
            Fucntion creates shader module from file content
            
            input: shader type, file content
            output: module id
        */
        GLuint compile_shader(GLuint type, const std::string& source);


    public:
        Shader(const std::string& vertex_filepath, const std::string& fragment_filepath);
        ~Shader();

        Shader(const Shader&) = delete;
        Shader& operator=(const Shader&) = delete;

        void use() const;

        // Uniforms 
        void set_bool(const std::string& name, bool value);
        void set_int(const std::string& name, int value);
        void set_float(const std::string& name, float value);

        void set_mat4(const std::string& name, const glm::mat4& mat);
        void set_vec3(const std::string& name, const glm::vec3& vec);
};