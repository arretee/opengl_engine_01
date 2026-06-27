#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "glmath/glmath.h"

struct Transform
{
    glm::vec3 translation;
    glm::vec3 rotation;
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

    Transform();
    Transform(const glm::vec3& trans, const glm::vec3& rot);
    Transform(const glm::vec3& trans, const glm::vec3& rot, const glm::vec3& scl);
    ~Transform();


    /*
        Function creates matrix of RotationM * TranslationM * Scale
    */
    glm::mat4 get_matrix() const;
};


#endif 