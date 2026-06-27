#include "glmath/vec4.h"


// -------------------- Constructors --------------------
glm::vec4::vec4()
{
    for(int i = 0; i < 4; i++) entries[i] = 0.0f;
}
glm::vec4::vec4(float nx, float ny, float nz, float nw)
{
    x = nx; y = ny; z = nz; w = nw;
}
glm::vec4::vec4(const vec2& v)
{
    x = v.x;
    y = v.y;
    z = 0.0f;
    w = 0.0f;
}
glm::vec4::vec4(const vec3& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = 0.0f;
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
glm::vec4& glm::vec4::operator+=(const vec4& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;

    return *this;
}
glm::vec4& glm::vec4::operator-=(const vec4& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;

    return *this;
}
glm::vec4& glm::vec4::operator*=(const float num) {
    x *= num;
    y *= num;
    z *= num;
    w *= num;

    return *this;
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
