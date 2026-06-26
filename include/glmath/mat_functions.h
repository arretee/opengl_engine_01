#pragma once

#include "glmath/glmath.h"


namespace glm{ 
    struct mat2;
    struct mat3;
    struct mat4;


    // -------------------- OpenGL Create Matrices Functions --------------------

    /*
        Function crteates translation matrix.

        input: vector of translation matrix move.
        output: mat4 translation matrix. 
    */
    mat4 create_traslation_matrix(const vec3& translation);


    /*
        Function crteates Z rotation matrix.

        input: angle to rotate the shape counterclockwise.
        output: mat4 Z rotation matrix. 
    */
    mat4 create_rotation_z_matrix(float angle);


    /*
        Function crteates View Transform matrix.

        input: cam pos vec3, direction of the camera vec.
        output: mat4 View Transform matrix. 
    */
    mat4 create_view_transform_matrix(const vec3& from, const vec3& to);


    /*
        Function crteates Projection Transform matrix.

        input: aspect ratio, pow of camera, nearest(>0), farest.
        output: mat4 View Transform matrix. 
    */
    mat4 create_projection_matrix(float aspect, float pov, float n, float f);
}