#include "glmath/vec2.h"


// -------------------- Constructors --------------------
glm::vec2::vec2()
{
    for(int i = 0; i < 2; i++) entries[i] = 0.0f;
}
glm::vec2::vec2(float x, float y)
{
    entries[0] = x; entries[1] = y;
}
glm::vec2::vec2(const vec3& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
}
glm::vec2::vec2(const vec4& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
}
glm::vec2::vec2(const vec2 &other)
{
    x = other.x;
    y = other.y;
}


// -------------------- Operators --------------------
glm::vec2 &glm::vec2::operator=(const vec2 &other)
{
    x = other.x;
    y = other.y;

    return *this;
}
glm::vec2 glm::vec2::operator+(const vec2 &other) const
{
    return vec2(x + other.x, y + other.y);
}
glm::vec2 glm::vec2::operator-(const vec2 &other) const
{
    return vec2(x - other.x, y - other.y);
}
glm::vec2 glm::vec2::operator*(const float num) const
{
    return vec2(x * num, y * num);
}


// -------------------- Methods --------------------
float glm::vec2::length() const
{
    return sqrtf(x * x + y * y);
}
void glm::vec2::print() const
{
    std::cout << "vec2: x -> " << x << "\t|\ty->" << y << std::endl; 
}
