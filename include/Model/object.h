#pragma once

#include <memory>

#include "Model/transform.h"
#include "View/shader.h"


struct Mesh;


class Object{
    public:
        std::shared_ptr<Mesh> mesh;
        Transform transform;
        std::shared_ptr<Shader> shader;

        Object(std::shared_ptr<Mesh> mesh_ptr);
        Object(std::shared_ptr<Mesh> mesh_ptr, const Transform& trans);
        Object(std::shared_ptr<Mesh> mesh_ptr, const Transform& trans, std::shared_ptr<Shader> shader_ptr);


        virtual ~Object() = default;
        
        virtual void update(float dt);     
};


