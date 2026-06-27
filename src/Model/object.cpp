#include "Model/object.h"

Object::Object(std::shared_ptr<Mesh> mesh_ptr){
    mesh = mesh_ptr;
}

Object::Object(std::shared_ptr<Mesh> mesh_ptr, const Transform &trans) {
    mesh = mesh_ptr;
    transform = trans;
}

Object::Object(std::shared_ptr<Mesh> mesh_ptr, const Transform &trans, std::shared_ptr<Shader> shader_ptr) {
    mesh = mesh_ptr;
    transform = trans;
    shader = shader_ptr;
}

void Object::update(float dt) {}
