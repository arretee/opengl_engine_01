#pragma once

#include "glmath/glmath.h"


namespace glm{
    /*
        Function calculates dot product of 2 vectors

        input: 2 vec3 vectors
        output: dot product of vectors
    */
    float dot_product(const vec3& v1, const vec3& v2);

    /*
        Function creates cross product of 2 vectors
        V1 X V2

        input: vec3 first vector, vec3 second vector.
        output: vec3 result of cross product.
    */
    vec3 cross_product(const vec3& v1, const vec3& v2);


    /*
        Function creates normalized vector.

        input: vec2 to normalize
        output: normalized vec2.
    */
    vec2 normalize(const vec2& v);
    /*
        Function creates normalized vector.

        input: vec3 to normalize
        output: normalized vec3.
    */
    vec3 normalize(const vec3& v);
    /*
        Function creates normalized vector.

        input: vec4 to normalize
        output: normalized vec4.
    */
    vec4 normalize(const vec4& v);
}