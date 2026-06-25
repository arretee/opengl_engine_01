#ifndef TRIANGLE_MESH_H
#define TRIANGLE_MESH_H

#include <vector>
#include <glad/glad.h>


class TriangleMesh {
public:
TriangleMesh();
void draw();
~TriangleMesh();

private:
unsigned int EBO, VAO, element_count;
std::vector<unsigned int> VBOs;
};


#endif