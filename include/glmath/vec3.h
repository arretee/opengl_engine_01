#pragma once

#include "glmath/glmath.h"


namespace glm{
    struct vec2;
    struct vec4;

    struct vec3
    {
        union{
            float entries[3];
            struct {float x, y, z; };
        };

        // Constructors
        vec3();
        vec3(float nx, float ny, float nz);
        vec3(const vec2& v);
        vec3(const vec4& v);
        vec3(const vec3& other);

        // Operators
        vec3& operator=(const vec3& other);

        vec3 operator+(const vec3& other) const;
        vec3 operator-(const vec3& other) const;
        vec3 operator*(const float num) const;

        vec3& operator+=(const vec3& other);
        vec3& operator-=(const vec3& other);
        vec3& operator*=(const float num);


        // Methods
        float length() const;
        void print() const;

    };
}