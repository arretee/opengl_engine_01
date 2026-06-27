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


// -------------------- Operators --------------------
glm::mat4 glm::mat4::operator+(const mat4& other) const{
    glm::mat4 m;

    for(int i = 0; i < 16; i++) m.entries[i] = entries[i] + other.entries[i];

    return m;
}
glm::mat4 glm::mat4::operator-(const mat4& other) const{
    glm::mat4 m;

    for(int i = 0; i < 16; i++) m.entries[i] = entries[i] - other.entries[i];

    return m;
}

glm::mat4 glm::mat4::operator*(const float num) const{
    glm::mat4 m;


    for(int i = 0; i < 16; i++) m.entries[i] = entries[i] * num;

    return m;
}
glm::vec4 glm::mat4::operator*(const vec4& v) const{
    glm::vec4 ret_v;


    ret_v.x = entries[0] * v.x + entries[4] * v.y + entries[8] * v.z  + entries[12] * v.w;
    ret_v.y = entries[1] * v.x + entries[5] * v.y + entries[9] * v.z  + entries[13] * v.w;
    ret_v.z = entries[2] * v.x + entries[6] * v.y + entries[10] * v.z + entries[14] * v.w;
    ret_v.w = entries[3] * v.x + entries[7] * v.y + entries[11] * v.z + entries[15] * v.w;

    return ret_v;
}
glm::mat4 glm::mat4::operator*(const mat4& m) const{
    glm::mat4 ret_m;

    for(int row = 0; row < 4 ; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            ret_m.entries[col * 4 + row] =  entries[0 * 4 + row] * m.entries[col * 4 + 0] + 
                                            entries[1 * 4 + row] * m.entries[col * 4 + 1] + 
                                            entries[2 * 4 + row] * m.entries[col * 4 + 2] + 
                                            entries[3 * 4 + row] * m.entries[col * 4 + 3];
        }
    }


    return ret_m;
}

glm::mat4& glm::mat4::operator*=(const float num){
    for(int i = 0; i < 16; i++) entries[i] *= num;

    return *this;
}
glm::mat4& glm::mat4::operator*=(const mat4& m){
    mat4 t;

    for(int row = 0; row < 4 ; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            t.entries[col * 4 + row] =    entries[0 * 4 + row] * m.entries[col * 4 + 0] + 
                                        entries[1 * 4 + row] * m.entries[col * 4 + 1] + 
                                        entries[2 * 4 + row] * m.entries[col * 4 + 2] + 
                                        entries[3 * 4 + row] * m.entries[col * 4 + 3];
        }
    }

    *this = t;
    return *this;
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


