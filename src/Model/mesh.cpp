#include "Model/mesh.h"

Mesh::Mesh(){
    indices_count = 0;

    VAO = 0; VBO = 0; EBO = 0;
}

Mesh::Mesh(std::vector<float>&& ver, std::vector<uint32_t>&& ind) {
    vertices = std::move(ver);
    indices = std::move(ind);

    VAO = 0; VBO = 0; EBO = 0;
}

Mesh::~Mesh(){
    if(VAO != 0){
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }
}

void Mesh::upload(){
    if(VAO != 0)
    {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);

        VAO = 0; VBO = 0; EBO = 0;
    }
    
    indices_count = indices.size();

    // Generate VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    
    // Vetrtices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // Colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    // Element Buffer
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);
}

bool Mesh::is_uploaded(){
    return VAO == 0;
}

void Mesh::draw(GLenum mode) const{
    if (VAO == 0) {std::cout << "Draw Error: Mesh is not uploaded"; return;}
    
    glBindVertexArray(VAO);
    glDrawElements(mode, indices_count, GL_UNSIGNED_INT, 0);
}