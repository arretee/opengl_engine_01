#include "glmath/mat4.h"


// -------------------- Constructors --------------------
glm::mat4::mat4()
{
    for(int i = 0; i < 16; i++) entries[i] = 0.0f;
}
glm::mat4::mat4(const mat4 &other)
{
    for(int i = 0; i < 16; i++) entries[i] = other.entries[i];
}




// -------------------- Methods --------------------
void glm::mat4::print() const
{
    std::cout << "mat4 data: " << std::endl; 
    for (int i = 0; i < 16; i++)
    {
        std::cout << entries[i];
        if((i + 1) % 4 == 0) std::cout << std::endl;
        else std::cout << "\t|\t";
    }
}
void glm::mat4::print_gl() const
{
    size_t size = 4;
    std::cout << "mat" << size << " gl_view: " << std::endl; 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << entries[i + j * size];
            if (j != size - 1) std::cout << "\t|\t";
        }

        std::cout << std::endl;
    }
}


