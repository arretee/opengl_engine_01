#ifndef MESH_H
#define MESH_H

#include "config.h"

struct Mesh
{

    private:
    size_t indices_count;
    GLuint VAO, VBO, EBO;

    public:
    std::vector<float> vertices;
    std::vector<uint32_t> indices;

    Mesh();
    Mesh(std::vector<float>&& ver, std::vector<uint32_t>&& ind);
    ~Mesh();


    /*
        Loads the Mesh into a GPU

        input: none
        output: none
    */
    void upload();

    /*
        Function checks if mesh is uploaded.

        input:none
        output: true if uploaded, false otherwise
    */
    bool is_uploaded();

    /*
        Function draws the mash on the screen

        input: draw mode
        output: none
    */
    void draw(GLenum mode) const;
};











#endif