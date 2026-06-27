#include "Model/object.h"

Object::Object(std::shared_ptr<Mesh> mesh_ptr){
    mesh = mesh_ptr;
}

Object::Object(std::shared_ptr<Mesh> mesh_ptr, Transform &trans) {
    mesh = mesh_ptr;
    transform = trans;
}


void Object::update(float dt) {}