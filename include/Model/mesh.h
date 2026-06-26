#ifndef MESH_H
#define MESH_H

#include "config.h"

struct mesh
{

    private:
    size_t indices_count;
    GLuint VAO, VBO, EBO;

    public:
    std::vector<float> vertices;
    std::vector<uint32_t> indices;

    mesh();
    mesh(std::vector<float>&& ver, std::vector<uint32_t>&& ind);
    ~mesh();


    /*
        Loads the Mesh into a GPU

        input: none
        output: none
    */
    void upload();

    /*
        Function draws the mash on the screen

        input: draw mode
        output: none
    */
    void draw(GLenum mode) const;
};











#endif