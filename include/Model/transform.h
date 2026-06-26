#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "config.h"

struct transform
{
    glm::vec3 translation;
    glm::vec3 rotation;
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

    transform();
    transform(const glm::vec3& trans, const glm::vec3& rot);
    transform(const glm::vec3& trans, const glm::vec3& rot, const glm::vec3& scl);
    ~transform();


    /*
        Function creates matrix of RotationM * TranslationM * Scale
    */
    glm::mat4 getMatrix() const;
};


#endif 