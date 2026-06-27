#include "Model/transform.h"


Transform::Transform() {
    translation = glm::vec3(0.0f, 0.0f, 0.0f);
    rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

Transform::Transform(const glm::vec3& trans, const glm::vec3& rot){
    translation = trans; 
    rotation = rot;
}

Transform::Transform(const glm::vec3& trans, const glm::vec3& rot, const glm::vec3& scl){
    translation = trans; 
    rotation = rot;
    scale = scl;
}

Transform::~Transform(){

}



glm::mat4 Transform::get_matrix() const {

    return  glm::create_rotation_matrix(rotation) * 
            glm::create_traslation_matrix(translation) * 
            glm::create_scale_matrix(scale);
}