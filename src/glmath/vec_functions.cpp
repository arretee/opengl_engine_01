#include "glmath/vec_functions.h"



float glm::dot_product(const vec3 &v1, const vec3 &v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

glm::vec3 glm::cross_product(const vec3 &v1, const vec3 &v2)
{
    glm::vec3 result;

    result.x = (v1.y * v2.z) - (v1.z * v2.y);
    result.y = (v1.z * v2.x) - (v1.x * v2.z);
    result.z = (v1.x * v2.y) - (v1.y * v2.x);

    return result;
}

glm::vec2 glm::normalize(const vec2 &v)
{
    float magnitude = v.length();

    if (magnitude == 0) throw std::runtime_error("Devide by zero in glmath.cpp -> glm::normalize");

    return vec2(v.x / magnitude, v.y / magnitude);
}
glm::vec3 glm::normalize(const vec3 &v)
{
    float magnitude = v.length();

    if (magnitude == 0) throw std::runtime_error("Devide by zero in glmath.cpp -> glm::normalize");

    return vec3(v.x / magnitude, v.y / magnitude, v.z / magnitude);
}
glm::vec4 glm::normalize(const vec4 &v)
{
    float magnitude = v.length();

    if (magnitude == 0) throw std::runtime_error("Devide by zero in glmath.cpp -> glm::normalize");

    return vec4(v.x / magnitude, v.y / magnitude, v.z / magnitude, v.w / magnitude);
}
