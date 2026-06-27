#pragma once

#include "glmath/glmath.h"


namespace glm{
    struct mat3
    {
        float entries[9];
        // Constructors
        mat3();
        mat3(const mat3& other);

        // Operators
        mat3 operator+(const mat3& other) const;
        mat3 operator-(const mat3& other) const;

        mat3 operator*(const float num) const;
        vec3 operator*(const vec3& v) const;
        mat3 operator*(const mat3& m) const;

        mat3& operator*=(const float num);
        mat3& operator*=(const mat3& m);

        // Methods
        void print() const;
        void print_gl() const;
    };
}