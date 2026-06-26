#include "glmath/vec4.h"


// -------------------- Constructors --------------------
glm::vec4::vec4()
{
    for(int i = 0; i < 4; i++) entries[i] = 0.0f;
}
glm::vec4::vec4(float x, float y, float z, float w)
{
    entries[0] = x; entries[1] = y; entries[2] = z; entries[3] = w;
}
glm::vec4::vec4(const vec2& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
    entries[2] = 0.0f;
    entries[3] = 0.0f;
}
glm::vec4::vec4(const vec3& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
    entries[2] = v.entries[2];
    entries[3] = 0.0f;
}
glm::vec4::vec4(const vec4 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
}


// -------------------- Operators --------------------
glm::vec4 &glm::vec4::operator=(const vec4 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;

    return *this;
}
glm::vec4 glm::vec4::operator+(const vec4 &other) const
{
    return vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}
glm::vec4 glm::vec4::operator-(const vec4 &other) const
{
    return vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}
glm::vec4 glm::vec4::operator*(const float num) const
{
    return vec4(x * num, y * num, z * num, w * num);
}


// -------------------- Methods --------------------
float glm::vec4::length() const
{
    return sqrtf(x * x + y * y + z * z + w * w);
}
void glm::vec4::print() const
{
    std::cout << "vec2: x -> " << x << "\t|\ty->" << y << "\t|\tz->" << z << "\t|\tw->" << w << std::endl; 
}
