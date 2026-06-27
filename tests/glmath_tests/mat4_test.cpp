#include <gtest/gtest.h>

#include "../../include/glmath/glmath.h"


// -------------------- Constructors checks --------------------
TEST(mat4Constructors, mat4DefaultConstructorTest) {
    glm::mat4 m;
    size_t size = 16;
    bool status = true;

    for (int i = 0; i < size; i++){
        if (m.entries[i] != 0.0f)
        {
            status = false;
        }
    }

    ASSERT_EQ(status, true);
}

TEST(mat4Constructors, mat4CopyConstructorTest) {
    glm::mat4 m;
    size_t size = 16;
    bool status = true;

    for (float i = 0.0f; i < size; i += 1.0f)
    {
        m.entries[(int) i] = i;
    }

    glm::mat4 m2(m);

    for (int i = 0; i < size; i += 1)
    {
        if (m.entries[i] != m2.entries[i]) status = false;
    }

    ASSERT_EQ(status, true);
}

// -------------------- Operators --------------------
TEST(mat4Operators, mat4PlusOperator){
    glm::mat4 m1;

    glm::mat4 m_t;
    for(int i = 0; i < 16; i++)
        m_t.entries[i] = (float) i;

    
    glm::mat4 m = m1 + m_t;

    for (int i = 0; i < 16; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float)i);
    }

    m = m + m_t;

    for (int i = 0; i < 16; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) i * 2.0f);
    }
}

TEST(mat4Operators, mat4MinusOperator){
    glm::mat4 m1;

    glm::mat4 m_t;
    for(int i = 0; i < 16; i++)
        m_t.entries[i] = (float) i;

    
    glm::mat4 m = m1 - m_t;

    for (int i = 0; i < 16; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) -i);
    }

    m = m - m_t;

    for (int i = 0; i < 16; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) -i * 2.0f);
    }
}

TEST(mat4Operators, mat4MultiplicationFloatOperator){
    glm::mat4 m1;

    for(int i = 0; i < 16; i++){
        m1.entries[i] = 1.0f;
    }
    
    glm::mat4 m = m1 * 5.0f;

    for (int i = 0; i < 16; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) 5.0f);
    }

    m = m * (-2.0f);

    for (int i = 0; i < 16; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], 5.0f * (-2.0f));
    }
}

TEST(mat4Operators, mat4Multiplicationvec4Operator){
    glm::vec4 v1(0.5f, 1.0f, 1.5f, 2.0f);

    glm::mat4 m_t;
    for(int i = 0; i < 16; i++)
        m_t.entries[i] = (float) i;



    glm::vec4 v = m_t * v1;

    ASSERT_FLOAT_EQ(v.x, 40.0f);
    ASSERT_FLOAT_EQ(v.y, 45.0f);
    ASSERT_FLOAT_EQ(v.z, 50.0f);
    ASSERT_FLOAT_EQ(v.w, 55.0f);
    }

TEST(mat4Operators, mat4Multiplicationmat4Operator){
    glm::mat4 m1;
    glm::mat4 m2;
    
    
    for(int i = 0; i < 16; i++){
        m1.entries[i] = (float) i + 1;
        m2.entries[i] = (float) 16 - i;
    }


    float arr[16] = {
        386.0f, 444.0f, 502.0f, 560.0f, 
        274.0f, 316.0f, 358.0f, 400.0f,
        162.0f, 188.0f, 214.0f, 240.0f,
        50.0f , 60.0f,  70.0f,  80.0f,
    };


    glm::mat4 m = m1 * m2;


    for (int i = 0; i < 16; i++)
        ASSERT_FLOAT_EQ(m.entries[i], arr[i]);

}

TEST(mat4Operators, mat4MultiplicationEqualFloatOperator){
    glm::mat4 m;
    for(int i = 0; i < 16; i++){
        m.entries[i] = 1.0f;
    }
    
    m *= 5.0f;

    for (int i = 0; i < 16; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) 5.0f);
    }

    m *= (-2.0f);

    for (int i = 0; i < 16; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], 5.0f * (-2.0f));
    }
}


TEST(mat4Operators, mat4MultiplicationEqualmat4Operator){
    glm::mat4 m1;
    glm::mat4 m2;
    
    
    for(int i = 0; i < 16; i++){
        m1.entries[i] = (float) i + 1;
        m2.entries[i] = (float) 16 - i;
    }


    float arr[16] = {
        386.0f, 444.0f, 502.0f, 560.0f, 
        274.0f, 316.0f, 358.0f, 400.0f,
        162.0f, 188.0f, 214.0f, 240.0f,
        50.0f , 60.0f,  70.0f,  80.0f,
    };


    m1 *= m2;


    for (int i = 0; i < 16; i++)
        ASSERT_FLOAT_EQ(m1.entries[i], arr[i]);
}