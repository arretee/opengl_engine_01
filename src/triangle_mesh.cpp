#include "triangle_mesh.h"

TriangleMesh::TriangleMesh() {
    std::vector<float> positions = {
        -0.5f, -0.5f, 0.5f,  // TOP LEFT BACK       0
        0.5f, -0.5f, 0.5f,  // TOP LEFT FRONT       1

        -0.5f, 0.5f, 0.5f,   // TOP RIGHT BACK      2
        0.5f, 0.5f, 0.5f,   // TOP RIGHT FRONT      3


        -0.5f, -0.5f, -0.5f,  // BOTTOM LEFT BACK   4
        0.5f, -0.5f, -0.5f,  // BOTTOM LEFT FRONT   5

        -0.5f, 0.5f, -0.5f,   // BOTTOM RIGHT BACK  6
        0.5f, 0.5f, -0.5f,   // BOTTOM RIGHT FRONT  7
    };

    std::vector<int> elements = {
        // Front
        0, 1, 3,
        3, 2, 0, 
        
        // Back
        5, 4, 6, 
        6, 7, 5,

        // Left
        4, 0, 2,
        2, 6, 4,

        // Right
        1, 5, 7,
        7, 3, 1,

        // Top
        2, 3, 7,
        7, 6, 2,

        // Bottom
        4, 5, 1,
        1, 0, 4,
    };

    std::vector<float> colors = {
        1.0f, 0.0f, 0.0f,   // Red
        1.0f, 0.0f, 0.0f,   // Red

        0.0f, 1.0f, 0.0f,   // Green
        0.0f, 1.0f, 0.0f,   // Green

        0.0f, 0.0f, 1.0f,   // Blue
        0.0f, 0.0f, 1.0f,   // Blue

        0.0f, 0.0f, 0.0f,   // Black
        0.0f, 0.0f, 0.0f,   // Black
    };

    element_count = elements.size();

    // Generate and setup VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    VBOs.resize(2);

    // position set
    glGenBuffers(1, &VBOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), positions.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    //color
    glGenBuffers(1, &VBOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(float), colors.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(1);


    // Element Buffer
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(int), elements.data(), GL_STATIC_DRAW);

}

void TriangleMesh::draw() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, element_count, GL_UNSIGNED_INT, 0);
}

TriangleMesh::~TriangleMesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(VBOs.size(), VBOs.data());
}