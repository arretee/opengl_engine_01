#pragma once

#include "glmath/glmath.h"


namespace glm{
    struct mat2
    {
        float entries[4];
        
        // Constructors
        mat2();
        mat2(const mat2& other);

        // Operators
        mat2 operator+(const mat2& other) const;
        mat2 operator-(const mat2& other) const;

        mat2 operator*(const float num) const;
        vec2 operator*(const vec2& v) const;
        mat2 operator*(const mat2& m) const;

        mat2& operator*=(const float num);
        mat2& operator*=(const mat2& m);

        // Methods
        void print() const;
        void print_gl() const;
    };
}