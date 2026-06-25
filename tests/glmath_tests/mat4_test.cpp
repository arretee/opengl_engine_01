#include <gtest/gtest.h>

#include "../../include/glmath.h"

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