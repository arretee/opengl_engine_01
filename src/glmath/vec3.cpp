#include "glmath/vec3.h"


// -------------------- Constructors --------------------
glm::vec3::vec3()
{
    x = 0.0f; y = 0.0f; z = 0.0f;
}
glm::vec3::vec3(float nx, float ny, float nz)
{
    x = nx; y = ny; z = nz;
}
glm::vec3::vec3(const vec2& v)
{
    x = v.x;
    y = v.y;
    z = 0.0f;
}
glm::vec3::vec3(const vec4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}
glm::vec3::vec3(const vec3 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
}


// -------------------- Operators --------------------
glm::vec3 &glm::vec3::operator=(const vec3 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    
    return *this;
}
glm::vec3 glm::vec3::operator+(const vec3 &other) const
{
    return vec3(x + other.x, y + other.y, z + other.z);
}
glm::vec3 glm::vec3::operator-(const vec3 &other) const
{
    return vec3(x - other.x, y - other.y, z - other.z);
}
glm::vec3 glm::vec3::operator*(const float num) const
{
    return vec3(x * num, y * num, z * num);
}
glm::vec3& glm::vec3::operator+=(const vec3& other) {
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}
glm::vec3& glm::vec3::operator-=(const vec3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}
glm::vec3& glm::vec3::operator*=(const float num) {
    x *= num;
    y *= num;
    z *= num;

    return *this;
}

bool glm::vec3::operator==(const vec3& other) const{
    return x == other.x && y == other.y && z == other.z;
}

// -------------------- Methods --------------------
float glm::vec3::length() const
{
    return sqrtf( x * x + y * y + z * z);
}
void glm::vec3::print() const
{
    std::cout << "vec2: x -> " << x << "\t|\ty->" << y << "\t|\tz->" << z << std::endl; 
}