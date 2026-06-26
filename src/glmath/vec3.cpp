#include "glmath/vec3.h"


// -------------------- Constructors --------------------
glm::vec3::vec3()
{
    for(int i = 0; i < 3; i++) entries[i] = 0.0f;

}
glm::vec3::vec3(float x, float y, float z)
{
    entries[0] = x; entries[1] = y; entries[2] = z;
}
glm::vec3::vec3(const vec2& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
    entries[2] = 0.0f;
}
glm::vec3::vec3(const vec4& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
    entries[2] = v.entries[2];
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


// -------------------- Methods --------------------
float glm::vec3::length() const
{
    return sqrtf( x * x + y * y + z * z);
}
void glm::vec3::print() const
{
    std::cout << "vec2: x -> " << x << "\t|\ty->" << y << "\t|\tz->" << z << std::endl; 
}