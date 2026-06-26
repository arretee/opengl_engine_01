#include "glmath/mat3.h"


// -------------------- Constructors --------------------
glm::mat3::mat3()
{
    for(int i = 0; i < 9; i++) entries[i] = 0.0f;
}
glm::mat3::mat3(const mat3 &other)
{
    for(int i = 0; i < 9; i++) entries[i] = other.entries[i];
}


// -------------------- Methods --------------------
void glm::mat3::print() const
{
    std::cout << "mat3 data: " << std::endl; 
    for (int i = 0; i < 9; i++)
    {
        std::cout << entries[i];
        if((i + 1) % 3 == 0) std::cout << std::endl;
        else std::cout << "\t|\t";
    }
}
void glm::mat3::print_gl() const
{
    size_t size = 3;
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