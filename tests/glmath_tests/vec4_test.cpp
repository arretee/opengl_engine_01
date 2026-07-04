#include <gtest/gtest.h>

#include "../../include/glmath/glmath.h"


// -------------------- Constructors Tests --------------------
TEST(vec4Constructors, DefaultConstructorTest){
    glm::vec4 v;

    ASSERT_FLOAT_EQ(v.x, 0.0f);
    ASSERT_FLOAT_EQ(v.y, 0.0f);
    ASSERT_FLOAT_EQ(v.z, 0.0f);
    ASSERT_FLOAT_EQ(v.w, 0.0f);
}

TEST(vec4Constructors, ValueConstructorTest){
    float x = 0.5f;
    float y = -4.0f;
    float z = 0.213215f;
    float w = -4.5f;
    
    glm::vec4 v(x, y, z, w);

    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
    ASSERT_FLOAT_EQ(v.z, z);
    ASSERT_FLOAT_EQ(v.w, w);
}

TEST(vec4Constructors, vec3_to_vec4ConstructorTest){
    float x = 0.5f;
    float y = -4.0f;
    float z = 7.0f;


    glm::vec3 v3(x, y, z);
    
    glm::vec4 v(v3);

    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
    ASSERT_FLOAT_EQ(v.z, z);
    ASSERT_FLOAT_EQ(v.w, 0.0f);
}

TEST(vec4Constructors, vec2_to_vec4ConstructorTest){
    float x = 0.5f;
    float y = -4.0f;

    glm::vec2 v2(x, y);
    
    glm::vec4 v(v2);

    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
    ASSERT_FLOAT_EQ(v.z, 0.0f);
    ASSERT_FLOAT_EQ(v.w, 0.0f);

}

TEST(vec4Constructors, CopyConstructorTest){
    glm::vec4 v4;
    v4.x = 5.0f;
    v4.y = 2.1f;

    glm::vec4 v(v4);


    ASSERT_FLOAT_EQ(v.x, v4.x);
    ASSERT_FLOAT_EQ(v.y, v4.y);
    ASSERT_FLOAT_EQ(v.z, v4.z);
    ASSERT_FLOAT_EQ(v.w, v4.w);
}


// -------------------- Operators Tests --------------------
TEST(vec4Operators, OperatorEqual){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;
    float w1, w2, w3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;
    w1 = 0.47f; w2 = 1.54f; w3 = 15.24f;


    glm::vec4 v1(x1, y1, z1, w1);
    glm::vec4 v2(x2, y2, z2, w2);

    glm::vec4 v3 = v1;
    ASSERT_FLOAT_EQ(v3.x == x1, true) << "1. Check that v3.x is copied from v1.x";
    ASSERT_FLOAT_EQ(v3.y == y1, true) << "2. Check that v3.y is copied from v1.y";
    ASSERT_FLOAT_EQ(v3.z == z1, true) << "1. Check that v3.z is copied from v1.z";
    ASSERT_FLOAT_EQ(v3.w == w1, true) << "2. Check that v3.w is copied from v1.w";

    v3 = v2;
    ASSERT_FLOAT_EQ(v3.x == x2, true) << "1. Check that v3.x is copied from v2.x";
    ASSERT_FLOAT_EQ(v3.y == y2, true) << "2. Check that v3.y is copied from v2.y";
    ASSERT_FLOAT_EQ(v3.z == z2, true) << "1. Check that v3.z is copied from v2.z";
    ASSERT_FLOAT_EQ(v3.w == w2, true) << "2. Check that v3.w is copied from v2.w";
}

TEST(vec4Operators, OperatorAddition){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;
    float w1, w2, w3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;
    w1 = 0.47f; w2 = 1.54f; w3 = 15.24f;



    glm::vec4 v1(x1, y1, z1, w1);
    glm::vec4 v2(x2, y2, z2, w2);
    glm::vec4 v3(x3, y3, z3, w3);


    glm::vec4 v = v1 + v2; 
    ASSERT_FLOAT_EQ(v.x, x1 + x2) << "Check that v.x is equal to v1.x + v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 + y2) << "Check that v.y is equal to v1.y + v2.y";
    ASSERT_FLOAT_EQ(v.z, z1 + z2) << "Check that v.z is equal to v1.z + v2.z";
    ASSERT_FLOAT_EQ(v.w, w1 + w2) << "Check that v.w is equal to v1.w + v2.w";


    v = v + v3;
    ASSERT_FLOAT_EQ(v.x, x1 + x2 + x3) << "Check that v.x is equal to v1.x + v2.x + v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 + y2 + y3) << "Check that v.y is equal to v1.y + v2.y + v2.y";
    ASSERT_FLOAT_EQ(v.z, z1 + z2 + z3) << "Check that v.z is equal to v1.z + v2.z + v2.z";
    ASSERT_FLOAT_EQ(v.w, w1 + w2 + w3) << "Check that v.w is equal to v1.w + v2.w + v2.w";
}

TEST(vec4Operators, OperatorMinus){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;
    float w1, w2, w3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;
    w1 = 0.47f; w2 = 1.54f; w3 = 15.24f;



    glm::vec4 v1(x1, y1, z1, w1);
    glm::vec4 v2(x2, y2, z2, w2);
    glm::vec4 v3(x3, y3, z3, w3);


    glm::vec4 v = v1 - v2; 
    ASSERT_FLOAT_EQ(v.x, x1 - x2) << "Check that v.x is equal to v1.x - v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 - y2) << "Check that v.y is equal to v1.y - v2.y";
    ASSERT_FLOAT_EQ(v.z, z1 - z2) << "Check that v.z is equal to v1.z - v2.z";
    ASSERT_FLOAT_EQ(v.w, w1 - w2) << "Check that v.w is equal to v1.w - v2.w";


    v = v - v3;
    ASSERT_FLOAT_EQ(v.x, x1 - x2 - x3) << "Check that v.x is equal to v1.x - v2.x - v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 - y2 - y3) << "Check that v.y is equal to v1.y - v2.y - v2.y";
    ASSERT_FLOAT_EQ(v.z, z1 - z2 - z3) << "Check that v.z is equal to v1.z - v2.z - v2.z";
    ASSERT_FLOAT_EQ(v.w, w1 - w2 - w3) << "Check that v.w is equal to v1.w - v2.w - v2.w";
}

TEST(vec4Operators, OperatorMultiplication){

    float x1 = 0.5f;
    float y1 = 0.7f;
    float z1 = 0.3f;
    float w1 = 0.1f;
    float n = 5;


    glm::vec4 v1(x1, y1, z1, w1);


    glm::vec4 v = v1 * n; 
    ASSERT_FLOAT_EQ(v.x, x1 * n) << "Check that v.x is equal to v1.x * n";
    ASSERT_FLOAT_EQ(v.y, y1 * n) << "Check that v.y is equal to v1.y * n";
    ASSERT_FLOAT_EQ(v.z, z1 * n) << "Check that v.z is equal to v1.z * n";
    ASSERT_FLOAT_EQ(v.w, w1 * n) << "Check that v.w is equal to v1.w * n";

    v = v * n;
    ASSERT_FLOAT_EQ(v.x, x1 * n * n) << "Check that v.x is equal to v1.x * n * n";
    ASSERT_FLOAT_EQ(v.y, y1 * n * n) << "Check that v.y is equal to v1.y * n * n";
    ASSERT_FLOAT_EQ(v.z, z1 * n * n) << "Check that v.z is equal to v1.z * n * n";
    ASSERT_FLOAT_EQ(v.w, w1 * n * n) << "Check that v.w is equal to v1.w * n * n";
}

TEST(vec4Operators, OperatorPlusEqual){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;
    float w1, w2, w3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;
    w1 = 0.47f; w2 = 1.54f; w3 = 15.24f;



    glm::vec4 v1(x1, y1, z1, w1);
    glm::vec4 v2(x2, y2, z2, w2);
    glm::vec4 v3(x3, y3, z3, w3);


    v1 += v2;
    ASSERT_FLOAT_EQ(v1.x, x1 + x2) << "Check that v1.x is equal to x1 + x2";
    ASSERT_FLOAT_EQ(v1.y, y1 + y2) << "Check that v1.y is equal to y1 + y2";
    ASSERT_FLOAT_EQ(v1.z, z1 + z2) << "Check that v1.z is equal to z1 + z2";
    ASSERT_FLOAT_EQ(v1.w, w1 + w2) << "Check that v1.w is equal to w1 + w2";

    v1 += v3;
    ASSERT_FLOAT_EQ(v1.x, x1 + x2 + x3) << "Check that v1.x is equal to x1 + x2 + x3";
    ASSERT_FLOAT_EQ(v1.y, y1 + y2 + y3) << "Check that v1.y is equal to y1 + y2 + y3";
    ASSERT_FLOAT_EQ(v1.z, z1 + z2 + z3) << "Check that v1.z is equal to z1 + z2 + z3";
    ASSERT_FLOAT_EQ(v1.w, w1 + w2 + w3) << "Check that v1.w is equal to w1 + w2 + w3";
}

TEST(vec4Operators, OperatorMinusEqual){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;
    float w1, w2, w3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 10.0f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 15.2f;
    z1 = 02.7f; z2 = 12.5f; z3 = 125.2f;
    w1 = 0.47f; w2 = 1.54f; w3 = 15.24f;



    glm::vec4 v1(x1, y1, z1, w1);
    glm::vec4 v2(x2, y2, z2, w2);
    glm::vec4 v3(x3, y3, z3, w3);


    v1 -= v2;
    ASSERT_FLOAT_EQ(v1.x, x1 - x2) << "Check that v1.x is equal to x1 - x2";
    ASSERT_FLOAT_EQ(v1.y, y1 - y2) << "Check that v1.y is equal to y1 - y2";
    ASSERT_FLOAT_EQ(v1.z, z1 - z2) << "Check that v1.z is equal to z1 - z2";
    ASSERT_FLOAT_EQ(v1.w, w1 - w2) << "Check that v1.w is equal to w1 - w2";

    v1 -= v3;
    ASSERT_FLOAT_EQ(v1.x, x1 - x2 - x3) << "Check that v1.x is equal to x1 - x2 - x3";
    ASSERT_FLOAT_EQ(v1.y, y1 - y2 - y3) << "Check that v1.y is equal to y1 - y2 - y3";
    ASSERT_FLOAT_EQ(v1.z, z1 - z2 - z3) << "Check that v1.z is equal to z1 - z2 - z3";
    ASSERT_FLOAT_EQ(v1.w, w1 - w2 - w3) << "Check that v1.w is equal to w1 - w2 - w3";
}

TEST(vec4Operators, OperatorMultiplicationEqual){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;
    float w1, w2, w3;


    x1 = 0.5f;
    y1 = 0.7f;
    z1 = 02.7f;
    w1 = 0.47f;



    glm::vec4 v1(x1, y1, z1, w1);



    v1 *= 2.0f;
    ASSERT_FLOAT_EQ(v1.x, x1 * 2.0f) << "Check that v1.x is equal to x1 2.0f";
    ASSERT_FLOAT_EQ(v1.y, y1 * 2.0f) << "Check that v1.y is equal to y1 2.0f";
    ASSERT_FLOAT_EQ(v1.z, z1 * 2.0f) << "Check that v1.z is equal to z1 2.0f";
    ASSERT_FLOAT_EQ(v1.w, w1 * 2.0f) << "Check that v1.w is equal to w1 2.0f";

    v1 *= 3.0f;
    ASSERT_FLOAT_EQ(v1.x, x1 * 2.0f * 3.0f) << "Check that v1.x is equal to x1 * 2.0f * 3.0f";
    ASSERT_FLOAT_EQ(v1.y, y1 * 2.0f * 3.0f) << "Check that v1.y is equal to y1 * 2.0f * 3.0f";
    ASSERT_FLOAT_EQ(v1.z, z1 * 2.0f * 3.0f) << "Check that v1.z is equal to z1 * 2.0f * 3.0f";
    ASSERT_FLOAT_EQ(v1.w, w1 * 2.0f * 3.0f) << "Check that v1.w is equal to w1 * 2.0f * 3.0f";
}

TEST(vec4Operators, OperatorEquation){
    float x1, x2, x3;
    float y1, y2, y3;
    float z1, z2, z3;
    float w1, w2, w3;


    x1 = 0.5f;  x2 = 1.0f;  x3 = 0.5f;
    y1 = 0.7f;  y2 = 1.5f;  y3 = 0.7f;
    z1 = 02.7f; z2 = 12.5f; z3 = 2.7f;
    w1 = 0.47f; w2 = 1.54f; w3 = 0.47f;



    glm::vec4 v1(x1, y1, z1, w1);
    glm::vec4 v2(x2, y2, z2, w2);
    glm::vec4 v3(x3, y3, z3, w3);


    ASSERT_EQ(v1 == v2, false);
    ASSERT_EQ(v1 == v3, true);
    ASSERT_EQ(v2 == v3, false);
  
}

// -------------------- Methods Tests --------------------
TEST(vec4Methods, LengthMethod){
    float x = 3.0f;
    float y = 5.0f;
    float z = 6.0f;
    float w = 7.0f;

    glm::vec4 v(x, y, z, w);


    ASSERT_FLOAT_EQ(v.length(), sqrtf(x * x + y * y + z * z + w * w)) << "Check that length is works";
}