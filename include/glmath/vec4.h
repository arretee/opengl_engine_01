#pragma once

#include "glmath/glmath.h"


namespace glm{
    struct vec2;
    struct vec3;

    struct vec4
    {
        union{
            float entries[4];
            struct {float x, y, z, w; };
        };

        vec4();
        vec4(float nx, float ny, float nz, float nw);
        vec4(const vec2& v);
        vec4(const vec3& v);
        vec4(const vec4& other);


        // Operators
        vec4& operator=(const vec4& other);

        vec4 operator+(const vec4& other) const;
        vec4 operator-(const vec4& other) const;
        vec4 operator*(const float num) const;

        vec4& operator+=(const vec4& other);
        vec4& operator-=(const vec4& other);
        vec4& operator*=(const float num);

        // Methods
        float length() const;
        void print() const;
    };
}