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
        Function crteates Y rotation matrix.

        input: angle to rotate the shape counterclockwise.
        output: mat4 Y rotation matrix. 
    */
    mat4 create_rotation_y_matrix(float angle);

    /*
        Function crteates X rotation matrix.

        input: angle to rotate the shape counterclockwise.
        output: mat4 X rotation matrix. 
    */
    mat4 create_rotation_x_matrix(float angle);

    /*
        Function creates rotation matrix.

        input: vector of angles to roatate the shape in every scope
        output: mat4 rotation matrix.
    */
    mat4 create_rotation_matrix(glm::vec3 v);


    /*
        Function crteates View Transform matrix.

        input: cam pos vec3, direction of the camera vec.
        output: mat4 View Transform matrix. 
    */
    mat4 create_view_transform_matrix(const vec3& from, const vec3& to);
    /*
        Function crteates View Transform matrix.

        input: cam pos vec3, forward vector, right vector, up vector.
        output: mat4 View Transform matrix. 
    */
    mat4 create_view_transform_matrix(const vec3& from, const vec3& f, const vec3& r, const vec3& u);



    /*
        Function crteates Projection Transform matrix.

        input: aspect ratio, pow of camera, nearest(>0), farest.
        output: mat4 View Transform matrix. 
    */
    mat4 create_projection_matrix(float aspect, float pov, float n, float f);

    /*
        Function creates scale matrix.
        input: vec3 scale
        output: mat4 scale matrix.
    */
    mat4 create_scale_matrix(const glm::vec3& scale);
}