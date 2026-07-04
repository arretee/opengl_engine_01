#include "glmath/vec2.h"


// -------------------- Constructors --------------------
glm::vec2::vec2() {
    x = 0.0f; y = 0.0f;
}
glm::vec2::vec2(float nx, float ny) {
    x = nx; y = ny;
}
glm::vec2::vec2(const vec3& v) {
    x = v.x;
    y = v.y;
}
glm::vec2::vec2(const vec4& v) {
    x = v.x;
    y = v.y;
}
glm::vec2::vec2(const vec2 &other) {
    x = other.x;
    y = other.y;
}


// -------------------- Operators --------------------
glm::vec2 &glm::vec2::operator=(const vec2 &other) {
    x = other.x;
    y = other.y;

    return *this;
}
glm::vec2 glm::vec2::operator+(const vec2 &other) const {
    return vec2(x + other.x, y + other.y);
}
glm::vec2 glm::vec2::operator-(const vec2 &other) const {
    return vec2(x - other.x, y - other.y);
}
glm::vec2 glm::vec2::operator*(const float num) const {
    return vec2(x * num, y * num);
}
glm::vec2& glm::vec2::operator+=(const vec2& other) {
    x += other.x;
    y += other.y;

    return *this;
}
glm::vec2& glm::vec2::operator-=(const vec2& other) {
    x -= other.x;
    y -= other.y;

    return *this;
}
glm::vec2& glm::vec2::operator*=(const float num) {
    x *= num;
    y *= num;

    return *this;
}

bool glm::vec2::operator==(const vec2& other) const{
    return x == other.x && y == other.y;
}

// -------------------- Methods --------------------
float glm::vec2::length() const {
    return sqrtf(x * x + y * y);
}
void glm::vec2::print() const {
    std::cout << "vec2: x -> " << x << "\t|\ty->" << y << std::endl; 
}
