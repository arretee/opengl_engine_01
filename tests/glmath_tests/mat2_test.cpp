#include <gtest/gtest.h>

#include "../../include/glmath/glmath.h"

// -------------------- Constructors checks --------------------
TEST(mat2Constructors, mat2DefaultConstructorTest) {
    glm::mat3 m;
    size_t size = 4;
    bool status = true;

    for (int i = 0; i < size; i++){
        if (m.entries[i] != 0.0f)
        {
            status = false;
        }
    }

    ASSERT_EQ(status, true);
}

TEST(mat2Constructors, mat2CopyConstructorTest) {
    glm::mat3 m;
    size_t size = 4;
    bool status = true;

    for (float i = 0.0f; i < size; i += 1.0f)
    {
        m.entries[(int) i] = i;
    }

    glm::mat3 m2(m);

    for (int i = 0; i < size; i += 1)
    {
        if (m.entries[i] != m2.entries[i]) status = false;
    }

    ASSERT_EQ(status, true);
}


// -------------------- Operators --------------------
TEST(mat2Operators, mat2PlusOperator){
    glm::mat2 m1;

    glm::mat2 m_t;
    for(int i = 0; i < 4; i++)
        m_t.entries[i] = (float) i;

    
    glm::mat2 m = m1 + m_t;

    for (int i = 0; i < 4; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float)i);
    }

    m = m + m_t;

    for (int i = 0; i < 4; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) i * 2.0f);
    }
}

TEST(mat2Operators, mat2MinusOperator){
    glm::mat2 m1;

    glm::mat2 m_t;
    for(int i = 0; i < 4; i++)
        m_t.entries[i] = (float) i;

    
    glm::mat2 m = m1 - m_t;

    for (int i = 0; i < 4; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) -i);
    }

    m = m - m_t;

    for (int i = 0; i < 4; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) -i * 2.0f);
    }
}

TEST(mat2Operators, mat2MultiplicationFloatOperator){
    glm::mat2 m1;

    for(int i = 0; i < 4; i++){
        m1.entries[i] = 1.0f;
    }
    
    glm::mat2 m = m1 * 5.0f;

    for (int i = 0; i < 4; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) 5.0f);
    }

    m = m * (-2.0f);

    for (int i = 0; i < 4; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], 5.0f * (-2.0f));
    }
}

TEST(mat2Operators, mat2Multiplicationvec2Operator){
    glm::vec2 v1(0.5f, 1.0f);

    glm::mat2 m_t;
    for(int i = 0; i < 4; i++)
        m_t.entries[i] = (float) i;



    glm::vec2 v = m_t * v1;

    ASSERT_FLOAT_EQ(v.x, 2.0f);
    ASSERT_FLOAT_EQ(v.y, 3.5f);
    }

TEST(mat2Operators, mat2Multiplicationmat2Operator){
    glm::mat2 m1;
    glm::mat2 m2;
    
    
    for(int i = 0; i < 4; i++){
        m1.entries[i] = (float) i + 1;
        m2.entries[i] = (float) 4 - i;
    }


    float arr[4] = {
        13.0f, 20.0f,
        5.0f, 8.0f,
    };


    glm::mat2 m = m1 * m2;


    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(m.entries[i], arr[i]);

}

TEST(mat2Operators, mat2MultiplicationEqualFloatOperator){
    glm::mat2 m;
    for(int i = 0; i < 4; i++){
        m.entries[i] = 1.0f;
    }
    
    m *= 5.0f;

    for (int i = 0; i < 4; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) 5.0f);
    }

    m *= (-2.0f);

    for (int i = 0; i < 4; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], 5.0f * (-2.0f));
    }
}


TEST(mat2Operators, mat2MultiplicationEqualmat2Operator){
    glm::mat2 m1;
    glm::mat2 m2;
    
    
    for(int i = 0; i < 4; i++){
        m1.entries[i] = (float) i + 1;
        m2.entries[i] = (float) 4 - i;
    }


    float arr[4] = {
        13.0f, 20.0f,
        5.0f, 8.0f,
    };


    m1 *= m2;


    for (int i = 0; i < 4; i++)
        ASSERT_FLOAT_EQ(m1.entries[i], arr[i]);
}