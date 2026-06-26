#include "glmath/mat2.h"


// -------------------- Constructors --------------------
glm::mat2::mat2()
{
    for(int i = 0; i < 4; i++) entries[i] = 0.0f;
}
glm::mat2::mat2(const mat2 &other)
{
    for(int i = 0; i < 4; i++) entries[i] = other.entries[i];
}




// -------------------- Methods --------------------
void glm::mat2::print() const
{
    std::cout << "mat2 data: " << std::endl; 
    for (int i = 0; i < 4; i++)
    {
        std::cout << entries[i];
        if((i + 1) % 2 == 0) std::cout << std::endl;
        else std::cout << "\t|\t";
    }
}
void glm::mat2::print_gl() const
{
    size_t size = 2;
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

