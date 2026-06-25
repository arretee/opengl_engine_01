#include <gtest/gtest.h>

#include "../../include/glmath.h"

// -------------------- Constructors Tests --------------------
TEST(vec2Constructors, DefaultConstructorTest){
    glm::vec2 v;

    ASSERT_FLOAT_EQ(v.x, 0.0f);
    ASSERT_FLOAT_EQ(v.y, 0.0f);
}

TEST(vec2Constructors, ValueConstructorTest){
    float x = 0.5f;
    float y = -4.0f;
    
    glm::vec2 v(x, y);

    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
}

TEST(vec2Constructors, vec3_to_vec2ConstructorTest){
    float x = 0.5f;
    float y = -4.0f;
    float z = 7.0f;


    glm::vec3 v3(x, y, z);
    
    glm::vec2 v(v3);

    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
}

TEST(vec2Constructors, vec4_to_vec2ConstructorTest){
    float x = 0.5f;
    float y = -4.0f;
    float z = 7.0f;
    float w = 71.0f;


    glm::vec4 v4(x, y, z, w);
    
    glm::vec2 v(v4);

    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);

}

TEST(vec2Constructors, CopyConstructorTest){
    glm::vec2 v2;
    v2.x = 5.0f;
    v2.y = 2.1f;

    glm::vec2 v(v2);


    ASSERT_FLOAT_EQ(v.x, v2.x);
    ASSERT_FLOAT_EQ(v.y, v2.y);
}


// -------------------- Operators Tests --------------------
TEST(vec2Operators, OperatorEqual){
    float x1, x2, x3;
    float y1, y2, y3;

    x1 = 0.5f; x2 = 1.0f; x3 = 10.0f;
    y1 = 0.7f; y2 = 1.5f; y3 = 15.2f;



    glm::vec2 v1(x1, y1);
    glm::vec2 v2(x2, y2);

    glm::vec2 v3 = v1;
    ASSERT_FLOAT_EQ(v3.x == x1, true) << "1. Check that v3.x is copied from v1.x";
    ASSERT_FLOAT_EQ(v3.y == y1, true) << "2. Check that v3.y is copied from v1.y";

    v3 = v2;
    ASSERT_FLOAT_EQ(v3.x == x2, true) << "3. Check that v3.x is copied from v2.x";
    ASSERT_FLOAT_EQ(v3.y == y2, true) << "4. Check that v3.y is copied from v2.y";
}

TEST(vec2Operators, OperatorAddition){
    float x1, x2, x3;
    float y1, y2, y3;

    x1 = 0.5f; x2 = 1.0f; x3 = 10.0f;
    y1 = 0.7f; y2 = 1.5f; y3 = 15.2f;



    glm::vec2 v1(x1, y1);
    glm::vec2 v2(x2, y2);
    glm::vec2 v3(x3, y3);

    glm::vec2 v = v1 + v2; 
    ASSERT_FLOAT_EQ(v.x, x1 + x2) << "Check that v.x is equal to v1.x + v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 + y2) << "Check that v.y is equal to v1.y + v2.y";

    v = v + v3;
    ASSERT_FLOAT_EQ(v.x, x1 + x2 + x3) << "Check that v.x is equal to v1.x + v2.x + v3.x";
    ASSERT_FLOAT_EQ(v.y, y1 + y2 + y3) << "Check that v.y is equal to v1.y + v2.y + v3.y";
}

TEST(vec2Operators, OperatorMinus){
    float x1, x2, x3;
    float y1, y2, y3;

    x1 = 0.5f; x2 = 1.0f; x3 = 10.0f;
    y1 = 0.7f; y2 = 1.5f; y3 = 15.2f;



    glm::vec2 v1(x1, y1);
    glm::vec2 v2(x2, y2);
    glm::vec2 v3(x3, y3);

    glm::vec2 v = v1 - v2; 
    ASSERT_FLOAT_EQ(v.x, x1 - x2) << "Check that v.x is equal to v1.x - v2.x";
    ASSERT_FLOAT_EQ(v.y, y1 - y2) << "Check that v.y is equal to v1.y - v2.y";

    v = v - v3;
    ASSERT_FLOAT_EQ(v.x, x1 - x2 - x3) << "Check that v.x is equal to v1.x - v2.x - v3.x";
    ASSERT_FLOAT_EQ(v.y, y1 - y2 - y3) << "Check that v.y is equal to v1.y - v2.y - v3.y";
}

TEST(vec2Operators, OperatorMultiplication){

    float x1 = 0.5f;
    float y1 = 0.7f;
    float n = 5;


    glm::vec2 v1(x1, y1);


    glm::vec2 v = v1 * n; 
    ASSERT_FLOAT_EQ(v.x, x1 * n) << "Check that v.x is equal to v1.x * n";
    ASSERT_FLOAT_EQ(v.y, y1 * n) << "Check that v.y is equal to v1.y * n";

    v = v * n;
    ASSERT_FLOAT_EQ(v.x, x1 * n * n) << "Check that v.x is equal to v1.x * n * n";
    ASSERT_FLOAT_EQ(v.y, y1 * n * n) << "Check that v.y is equal to v1.y * n * n";
}


// -------------------- Methods Tests --------------------
TEST(vec2Methods, LengthMethod){
    float x = 3.0f;
    float y = 5.0f;

    glm::vec2 v(x, y);


    ASSERT_FLOAT_EQ(v.length(), sqrtf(x * x + y * y)) << "Check that length is works";
}