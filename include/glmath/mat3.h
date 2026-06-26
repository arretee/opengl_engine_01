#pragma once

#include "glmath/glmath.h"


namespace glm{
    struct mat3
    {
        float entries[9];
        mat3();

        mat3(const mat3& other);

        void print() const;
        void print_gl() const;
    };
}