#include "Model/transform.h"


transform::transform() {}

transform::transform(const glm::vec3& trans, const glm::vec3& rot){
    translation = trans; 
    rotation = rot;
}

transform::transform(const glm::vec3& trans, const glm::vec3& rot, const glm::vec3& scl){
    translation = trans; 
    rotation = rot;
    scale = scl;
}

transform::~transform(){

}



glm::mat4 transform::getMatrix() const {
    glm::mat4 m;

    return m;
}