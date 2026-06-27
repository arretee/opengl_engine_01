#include <gtest/gtest.h>

#include "../../include/glmath/glmath.h"


// -------------------- Constructors checks --------------------
TEST(mat3Constructors, mat3DefaultConstructorTest) {
    glm::mat3 m;
    size_t size = 9;
    bool status = true;

    for (int i = 0; i < size; i++){
        if (m.entries[i] != 0.0f)
        {
            status = false;
        }
    }

    ASSERT_EQ(status, true);
}

TEST(mat3Constructors, mat3CopyConstructorTest) {
    glm::mat3 m;
    size_t size = 9;
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
TEST(mat3Operators, mat3PlusOperator){
    glm::mat3 m1;

    glm::mat3 m_t;
    for(int i = 0; i < 9; i++)
        m_t.entries[i] = (float) i;

    
    glm::mat3 m = m1 + m_t;

    for (int i = 0; i < 9; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float)i);
    }

    m = m + m_t;

    for (int i = 0; i < 9; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) i * 2.0f);
    }
}

TEST(mat3Operators, mat3MinusOperator){
    glm::mat3 m1;

    glm::mat3 m_t;
    for(int i = 0; i < 9; i++)
        m_t.entries[i] = (float) i;

    
    glm::mat3 m = m1 - m_t;

    for (int i = 0; i < 9; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) -i);
    }

    m = m - m_t;

    for (int i = 0; i < 9; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) -i * 2.0f);
    }
}

TEST(mat3Operators, mat3MultiplicationFloatOperator){
    glm::mat3 m1;

    for(int i = 0; i < 9; i++){
        m1.entries[i] = 1.0f;
    }
    
    glm::mat3 m = m1 * 5.0f;

    for (int i = 0; i < 9; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) 5.0f);
    }

    m = m * (-2.0f);

    for (int i = 0; i < 9; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], 5.0f * (-2.0f));
    }
}

TEST(mat3Operators, mat3Multiplicationvec3Operator){
    glm::vec3 v1(0.5f, 1.0f, 1.5f);

    glm::mat3 m_t;
    for(int i = 0; i < 9; i++)
        m_t.entries[i] = (float) i;



    glm::vec3 v = m_t * v1;

    ASSERT_FLOAT_EQ(v.x, 12.0f);
    ASSERT_FLOAT_EQ(v.y, 15.0f);
    ASSERT_FLOAT_EQ(v.z, 18.0f);
    }

TEST(mat3Operators, mat3Multiplicationmat3Operator){
    glm::mat3 m1;
    glm::mat3 m2;
    
    
    for(int i = 0; i < 9; i++){
        m1.entries[i] = (float) i + 1;
        m2.entries[i] = (float) 9 - i;
    }


    float arr[9] = {
        90.0f, 114.0f, 138.0f, 
        54.0f, 69.0f, 84.0f, 
        18.0f, 24.0f, 30.0f
    };


    glm::mat3 m = m1 * m2;


    for (int i = 0; i < 9; i++)
        ASSERT_FLOAT_EQ(m.entries[i], arr[i]);

}

TEST(mat3Operators, mat3MultiplicationEqualFloatOperator){
    glm::mat3 m;
    for(int i = 0; i < 9; i++){
        m.entries[i] = 1.0f;
    }
    
    m *= 5.0f;

    for (int i = 0; i < 9; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], (float) 5.0f);
    }

    m *= (-2.0f);

    for (int i = 0; i < 9; i++)
    {
        ASSERT_FLOAT_EQ(m.entries[i], 5.0f * (-2.0f));
    }
}


TEST(mat3Operators, mat3MultiplicationEqualmat3Operator){
    glm::mat3 m1;
    glm::mat3 m2;
    
    
    for(int i = 0; i < 9; i++){
        m1.entries[i] = (float) i + 1;
        m2.entries[i] = (float) 9 - i;
    }


    float arr[9] = {
        90.0f, 114.0f, 138.0f, 
        54.0f, 69.0f, 84.0f, 
        18.0f, 24.0f, 30.0f
    };



    m1 *= m2;


    for (int i = 0; i < 9; i++)
        ASSERT_FLOAT_EQ(m1.entries[i], arr[i]);
}