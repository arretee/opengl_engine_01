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



// -------------------- Operators --------------------
glm::mat2 glm::mat2::operator+(const mat2& other) const{
    glm::mat2 m;

    for(int i = 0; i < 4; i++) m.entries[i] = entries[i] + other.entries[i];

    return m;
}
glm::mat2 glm::mat2::operator-(const mat2& other) const{
    glm::mat2 m;

    for(int i = 0; i < 4; i++) m.entries[i] = entries[i] - other.entries[i];

    return m;
}

glm::mat2 glm::mat2::operator*(const float num) const{
    glm::mat2 m;

    for(int i = 0; i < 4; i++) m.entries[i] = entries[i] * num;

    return m;
}
glm::vec2 glm::mat2::operator*(const vec2& v) const{
    glm::vec2 ret_v;


    ret_v.x = entries[0] * v.x + entries[2] * v.y;
    ret_v.y = entries[1] * v.x + entries[3] * v.y;

    return ret_v;
}
glm::mat2 glm::mat2::operator*(const mat2& m) const{
    glm::mat2 ret_m;

    for(int row = 0; row < 2 ; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            ret_m.entries[col * 2 + row] =  entries[0 * 2 + row] * m.entries[col * 2 + 0] + 
                                            entries[1 * 2 + row] * m.entries[col * 2 + 1];
        }
    }


    return ret_m;
}

glm::mat2& glm::mat2::operator*=(const float num){
    for(int i = 0; i < 4; i++) entries[i] *= num;

    return *this;
}
glm::mat2& glm::mat2::operator*=(const mat2& m){
    glm::mat2 t;
    
    for(int row = 0; row < 2 ; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            t.entries[col * 2 + row] =    entries[0 * 2 + row] * m.entries[col * 2 + 0] + 
                                        entries[1 * 2 + row] * m.entries[col * 2 + 1];
        }
    }

    *this = t;
    return *this;
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

