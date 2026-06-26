#pragma once

#include "glmath/glmath.h"


namespace glm{
    struct mat4
    {
        float entries[16];
        mat4();

        mat4(const mat4& other);

        void print() const;
        void print_gl() const;
    };
}