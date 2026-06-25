#include <gtest/gtest.h>

#include "../../include/glmath.h"

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