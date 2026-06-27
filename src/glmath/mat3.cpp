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


// -------------------- Operators --------------------
glm::mat3 glm::mat3::operator+(const mat3& other) const{
    glm::mat3 m;

    for(int i = 0; i < 9; i++) m.entries[i] = entries[i] + other.entries[i];

    return m;
}
glm::mat3 glm::mat3::operator-(const mat3& other) const{
    glm::mat3 m;

    for(int i = 0; i < 9; i++) m.entries[i] = entries[i] - other.entries[i];

    return m;
}

glm::mat3 glm::mat3::operator*(const float num) const{
    glm::mat3 m;

    for(int i = 0; i < 9; i++) m.entries[i] = entries[i] * num;

    return m;
}
glm::vec3 glm::mat3::operator*(const vec3& v) const{
    glm::vec3 ret_v;


    ret_v.x = entries[0] * v.x + entries[3] * v.y + entries[6] * v.z;
    ret_v.y = entries[1] * v.x + entries[4] * v.y + entries[7] * v.z;
    ret_v.z = entries[2] * v.x + entries[5] * v.y + entries[8] * v.z;

    return ret_v;
}
glm::mat3 glm::mat3::operator*(const mat3& m) const{
    glm::mat3 ret_m;

    for(int row = 0; row < 3 ; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            ret_m.entries[col * 3 + row] =  entries[0 * 3 + row] * m.entries[col * 3 + 0] + 
                                            entries[1 * 3 + row] * m.entries[col * 3 + 1] + 
                                            entries[2 * 3 + row] * m.entries[col * 3 + 2];
        }
    }


    return ret_m;
}

glm::mat3& glm::mat3::operator*=(const float num){
    for(int i = 0; i < 9; i++) entries[i] *= num;

    return *this;
}
glm::mat3& glm::mat3::operator*=(const mat3& m){
    mat3 t;

    for(int row = 0; row < 3 ; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            t.entries[col * 3 + row] =    entries[0 * 3 + row] * m.entries[col * 3 + 0] + 
                                        entries[1 * 3 + row] * m.entries[col * 3 + 1] + 
                                        entries[2 * 3 + row] * m.entries[col * 3 + 2];
        }
    }

    *this = t;
    return *this;
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