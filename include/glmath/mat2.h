#pragma once

#include "glmath/glmath.h"


namespace glm{
    struct mat2
    {
        float entries[4];
        mat2();

        mat2(const mat2& other);

        void print() const;
        void print_gl() const;
    };
}