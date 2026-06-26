#pragma once

#include "glmath/glmath.h"

namespace glm{
    struct vec3;
    struct vec4;

    struct vec2
    {
        union{
            float entries[2];
            struct {float x, y; };
        };
        
        // Constructors
        vec2();
        vec2(float x, float y);
        vec2(const vec3& v);
        vec2(const vec4& v);
        vec2(const vec2& other);

        // Operators
        vec2& operator=(const vec2& other);

        vec2 operator+(const vec2& other) const;
        vec2 operator-(const vec2& other) const;
        vec2 operator*(float num) const;

        vec2 operator+=(const vec2& other);
        vec2 operator-=(const vec2& other);
        vec2 operator*=(const vec2& other);



        // Methods
        float length() const;
        void print() const;
    };
}