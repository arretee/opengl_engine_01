#include <gtest/gtest.h>

#include "../../include/glmath/glmath.h"


// -------------------- Constructors Tests --------------------
TEST(vec3Constructors, DefaultConstructorTest){
    glm::vec3 v;

    ASSERT_FLOAT_EQ(v.x, 0.0f);
    ASSERT_FLOAT_EQ(v.y, 0.0f);
    ASSERT_FLOAT_EQ(v.z, 0.0f);
}

TEST(vec3Constructors, ValueConstructorTest){
    float x = 0.5f;
    float y = -4.0f;
    float z = 0.213215f;
    
    glm::vec3 v(x, y, z);

    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
    ASSERT_FLOAT_EQ(v.z, z);
}

TEST(vec3Constructors, vec4_to_vec3ConstructorTest){
    float x = 0.5f;
    float y = -4.0f;
    float z = 7.0f;
    float w = 2.0f;

    glm::vec4 v4(x, y, z, w);
    
    glm::vec3 v(v4);

    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
    ASSERT_FLOAT_EQ(v.z, z);
}

TEST(vec3Constructors, vec2_to_vec3ConstructorTest){
    float x = 0.5f;
    float y = -4.0f;

    glm::vec2 v2(x, y);
    
    glm::vec3 v(v2);

    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
    ASSERT_FLOAT_EQ(v.z, 0.0f);
}

TEST(vec3Constructors, CopyConstructorTest){
    glm::vec3 v3;
    v3.x = 5.0f;
    v3.y = 2.1f;
    v3.z = 0.2f;

    glm::vec3 v(v3);


    ASSERT_FLOAT_EQ(v.x, v3.x);
    ASSERT_FLOAT_EQ(v.y, v3.y);
    ASSERT_FLOAT_EQ(v.z, v3.z);
}


// -------------------- Operators Tests --------------------
TEST(vec3Operators, OperatorEqual){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;


    glm::vec3 v1(x1, y1, z1);
    glm::vec3 v2(x2, y2, z2);

    glm::vec3 v3 = v1;
    ASSERT_FLOAT_EQ(v3.x == x1, true) << "1. Check that v3.x is copied from v1.x";
    ASSERT_FLOAT_EQ(v3.y == y1, true) << "2. Check that v3.y is copied from v1.y";
    ASSERT_FLOAT_EQ(v3.z == z1, true) << "1. Check that v3.z is copied from v1.z";

    v3 = v2;
    ASSERT_FLOAT_EQ(v3.x == x2, true) << "1. Check that v3.x is copied from v2.x";
    ASSERT_FLOAT_EQ(v3.y == y2, true) << "2. Check that v3.y is copied from v2.y";
    ASSERT_FLOAT_EQ(v3.z == z2, true) << "1. Check that v3.z is copied from v2.z";
}

TEST(vec3Operators, OperatorAddition){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;



    glm::vec3 v1(x1, y1, z1);
    glm::vec3 v2(x2, y2, z2);
    glm::vec3 v3(x3, y3, z3);


    glm::vec3 v = v1 + v2; 
    ASSERT_FLOAT_EQ(v.x, x1 + x2) << "Check that v.x is equal to v1.x + v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 + y2) << "Check that v.y is equal to v1.y + v2.y";
    ASSERT_FLOAT_EQ(v.z, z1 + z2) << "Check that v.z is equal to v1.z + v2.z";


    v = v + v3;
    ASSERT_FLOAT_EQ(v.x, x1 + x2 + x3) << "Check that v.x is equal to v1.x + v2.x + v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 + y2 + y3) << "Check that v.y is equal to v1.y + v2.y + v2.y";
    ASSERT_FLOAT_EQ(v.z, z1 + z2 + z3) << "Check that v.z is equal to v1.z + v2.z + v2.z";
}

TEST(vec3Operators, OperatorMinus){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;



    glm::vec3 v1(x1, y1, z1);
    glm::vec3 v2(x2, y2, z2);
    glm::vec3 v3(x3, y3, z3);


    glm::vec3 v = v1 - v2; 
    ASSERT_FLOAT_EQ(v.x, x1 - x2) << "Check that v.x is equal to v1.x - v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 - y2) << "Check that v.y is equal to v1.y - v2.y";
    ASSERT_FLOAT_EQ(v.z, z1 - z2) << "Check that v.z is equal to v1.z - v2.z";


    v = v - v3;
    ASSERT_FLOAT_EQ(v.x, x1 - x2 - x3) << "Check that v.x is equal to v1.x - v2.x - v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 - y2 - y3) << "Check that v.y is equal to v1.y - v2.y - v2.y";
    ASSERT_FLOAT_EQ(v.z, z1 - z2 - z3) << "Check that v.z is equal to v1.z - v2.z - v2.z";
}

TEST(vec3Operators, OperatorMultiplication){

    float x1 = 0.5f;
    float y1 = 0.7f;
    float z1 = 0.3f;
    float n = 5;


    glm::vec3 v1(x1, y1, z1);


    glm::vec3 v = v1 * n; 
    ASSERT_FLOAT_EQ(v.x, x1 * n) << "Check that v.x is equal to v1.x * n";
    ASSERT_FLOAT_EQ(v.y, y1 * n) << "Check that v.y is equal to v1.y * n";
    ASSERT_FLOAT_EQ(v.z, z1 * n) << "Check that v.z is equal to v1.z * n";

    v = v * n;
    ASSERT_FLOAT_EQ(v.x, x1 * n * n) << "Check that v.x is equal to v1.x * n * n";
    ASSERT_FLOAT_EQ(v.y, y1 * n * n) << "Check that v.y is equal to v1.y * n * n";
    ASSERT_FLOAT_EQ(v.z, z1 * n * n) << "Check that v.z is equal to v1.z * n * n";

}

TEST(vec3Operators, OperatorPlusEqual){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;



    glm::vec3 v1(x1, y1, z1);
    glm::vec3 v2(x2, y2, z2);
    glm::vec3 v3(x3, y3, z3);


    v1 += v2;
    ASSERT_FLOAT_EQ(v1.x, x1 + x2) << "Check that v1.x is equal to x1 + x2";
    ASSERT_FLOAT_EQ(v1.y, y1 + y2) << "Check that v1.y is equal to y1 + y2";
    ASSERT_FLOAT_EQ(v1.z, z1 + z2) << "Check that v1.z is equal to z1 + z2";

    v1 += v3;
    ASSERT_FLOAT_EQ(v1.x, x1 + x2 + x3) << "Check that v1.x is equal to x1 + x2 + x3";
    ASSERT_FLOAT_EQ(v1.y, y1 + y2 + y3) << "Check that v1.y is equal to y1 + y2 + y3";
    ASSERT_FLOAT_EQ(v1.z, z1 + z2 + z3) << "Check that v1.z is equal to z1 + z2 + z3";
}

TEST(vec3Operators, OperatorMinusEqual){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;



    glm::vec3 v1(x1, y1, z1);
    glm::vec3 v2(x2, y2, z2);
    glm::vec3 v3(x3, y3, z3);

    v1 -= v2;
    ASSERT_FLOAT_EQ(v1.x, x1 - x2) << "Check that v1.x is equal to x1 - x2";
    ASSERT_FLOAT_EQ(v1.y, y1 - y2) << "Check that v1.y is equal to y1 - y2";
    ASSERT_FLOAT_EQ(v1.z, z1 - z2) << "Check that v1.z is equal to z1 - z2";

    v1 -= v3;
    ASSERT_FLOAT_EQ(v1.x, x1 - x2 - x3) << "Check that v1.x is equal to x1 - x2 - x3";
    ASSERT_FLOAT_EQ(v1.y, y1 - y2 - y3) << "Check that v1.y is equal to y1 - y2 - y3";
    ASSERT_FLOAT_EQ(v1.z, z1 - z2 - z3) << "Check that v1.z is equal to z1 - z2 - z3";
}

TEST(vec3Operators, OperatorMultiplicationEqual){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;


    x1 = 0.5f;
    y1 = 0.7f;
    z1 = 02.7f;



    glm::vec3 v1(x1, y1, z1);



    v1 *= 2.0f;
    ASSERT_FLOAT_EQ(v1.x, x1 * 2.0f) << "Check that v1.x is equal to x1 2.0f";
    ASSERT_FLOAT_EQ(v1.y, y1 * 2.0f) << "Check that v1.y is equal to y1 2.0f";
    ASSERT_FLOAT_EQ(v1.z, z1 * 2.0f) << "Check that v1.z is equal to z1 2.0f";

    v1 *= 3.0f;
    ASSERT_FLOAT_EQ(v1.x, x1 * 2.0f * 3.0f) << "Check that v1.x is equal to x1 * 2.0f * 3.0f";
    ASSERT_FLOAT_EQ(v1.y, y1 * 2.0f * 3.0f) << "Check that v1.y is equal to y1 * 2.0f * 3.0f";
    ASSERT_FLOAT_EQ(v1.z, z1 * 2.0f * 3.0f) << "Check that v1.z is equal to z1 * 2.0f * 3.0f";
}

TEST(vec3Operators, OperatorEquation){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 0.5f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 0.7f;
    z1 = 02.7f; z2 = 12.5f; z3 = 2.7f;



    glm::vec3 v1(x1, y1, z1);
    glm::vec3 v2(x2, y2, z2);
    glm::vec3 v3(x3, y3, z3);


    ASSERT_EQ(v1 == v2, false);
    ASSERT_EQ(v1 == v3, true);
    ASSERT_EQ(v2 == v3, false);
}

// -------------------- Methods Tests --------------------
TEST(vec3Methods, LengthMethod){
    float x = 3.0f;
    float y = 5.0f;
    float z = 6.0f;

    glm::vec3 v(x, y, z);


    ASSERT_FLOAT_EQ(v.length(), sqrtf(x * x + y * y + z * z)) << "Check that length is works";
}