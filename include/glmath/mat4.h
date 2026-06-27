#pragma once

#include "glmath/glmath.h"


namespace glm{
    struct vec4;


    struct mat4
    {
        float entries[16];

        // Constructors
        mat4();
        mat4(const mat4& other);

        // Operators
        mat4 operator+(const mat4& other) const;
        mat4 operator-(const mat4& other) const;

        mat4 operator*(const float num) const;
        vec4 operator*(const vec4& v) const;
        mat4 operator*(const mat4& m) const;

        mat4& operator*=(const float num);
        mat4& operator*=(const mat4& m);

        // Methods
        void print() const;
        void print_gl() const;
    };
}