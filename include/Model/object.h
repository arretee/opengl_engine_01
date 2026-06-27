#pragma once

#include "Model/transform.h"
#include <memory>

struct Mesh;


class Object{
    public:
        std::shared_ptr<Mesh> mesh;
        Transform transform;

        Object(std::shared_ptr<Mesh> mesh_ptr);
        Object(std::shared_ptr<Mesh> mesh_ptr, Transform& trans);


        virtual ~Object() = default;
        
        virtual void update(float dt);       

};


