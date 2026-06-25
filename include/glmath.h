#ifndef GLMATH_H
#define GLMATH_H

#include <iostream>
#include <cmath>

// -------------------- Structs defines --------------------
namespace glm{
    // Struct decloration
    struct mat2;
    struct mat3;
    struct mat4;
    struct vec2;
    struct vec3;
    struct vec4;


    struct mat2
    {
        float entries[4];
        mat2();

        mat2(const mat2& other);

        void print() const;
        void print_gl() const;
    };

    struct mat3
    {
        float entries[9];
        mat3();

        mat3(const mat3& other);

        void print() const;
        void print_gl() const;
    };

    struct mat4
    {
        float entries[16];
        mat4();

        mat4(const mat4& other);

        void print() const;
        void print_gl() const;
    };


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

        // Methods
        float length() const;
        void print() const;
    };

    struct vec3
    {
        union{
            float entries[3];
            struct {float x, y, z; };
        };

        // Constructors
        vec3();
        vec3(float x, float y, float z);
        vec3(const vec2& v);
        vec3(const vec4& v);
        vec3(const vec3& other);

        // Operators
        vec3& operator=(const vec3& other);

        vec3 operator+(const vec3& other) const;
        vec3 operator-(const vec3& other) const;
        vec3 operator*(const float num) const;

        // Methods
        float length() const;
        void print() const;

    };

    struct vec4
    {
        union{
            float entries[4];
            struct {float x, y, z, w; };
        };

        vec4();
        vec4(float x, float y, float z, float w);
        vec4(const vec2& v);
        vec4(const vec3& v);
        vec4(const vec4& other);


        // Operators
        vec4& operator=(const vec4& other);
        vec4 operator+(const vec4& other) const;
        vec4 operator-(const vec4& other) const;
        vec4 operator*(const float num) const;

        // Methods
        float length() const;
        void print() const;
    };




    // -------------------- Vector Math Functions --------------------

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
#endif