#include "glmath.h"


// -------------------- Structs defines --------------------
// ---------- mat2 ----------
glm::mat2::mat2()
{
    for(int i = 0; i < 4; i++) entries[i] = 0.0f;
}
glm::mat2::mat2(const mat2 &other)
{
    for(int i = 0; i < 4; i++) entries[i] = other.entries[i];
}
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


// ---------- mat3 ----------
glm::mat3::mat3()
{
    for(int i = 0; i < 9; i++) entries[i] = 0.0f;
}
glm::mat3::mat3(const mat3 &other)
{
    for(int i = 0; i < 9; i++) entries[i] = other.entries[i];
}
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


// ---------- mat4 ----------
glm::mat4::mat4()
{
    for(int i = 0; i < 16; i++) entries[i] = 0.0f;
}
glm::mat4::mat4(const mat4 &other)
{
    for(int i = 0; i < 16; i++) entries[i] = other.entries[i];
}
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



// ---------- vec2 ----------
glm::vec2::vec2()
{
    for(int i = 0; i < 2; i++) entries[i] = 0.0f;
}
glm::vec2::vec2(float x, float y)
{
    entries[0] = x; entries[1] = y;
}
glm::vec2::vec2(const vec3& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
}
glm::vec2::vec2(const vec4& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
}
glm::vec2::vec2(const vec2 &other)
{
    x = other.x;
    y = other.y;
}

glm::vec2 &glm::vec2::operator=(const vec2 &other)
{
    x = other.x;
    y = other.y;

    return *this;
}
glm::vec2 glm::vec2::operator+(const vec2 &other) const
{
    return vec2(x + other.x, y + other.y);
}
glm::vec2 glm::vec2::operator-(const vec2 &other) const
{
    return vec2(x - other.x, y - other.y);
}
glm::vec2 glm::vec2::operator*(const float num) const
{
    return vec2(x * num, y * num);
}

float glm::vec2::length() const
{
    return sqrtf(x * x + y * y);
}
void glm::vec2::print() const
{
    std::cout << "vec2: x -> " << x << "\t|\ty->" << y << std::endl; 
}


// ---------- vec3 ----------
glm::vec3::vec3()
{
    for(int i = 0; i < 3; i++) entries[i] = 0.0f;

}
glm::vec3::vec3(float x, float y, float z)
{
    entries[0] = x; entries[1] = y; entries[2] = z;
}
glm::vec3::vec3(const vec2& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
    entries[2] = 0.0f;
}
glm::vec3::vec3(const vec4& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
    entries[2] = v.entries[2];
}
glm::vec3::vec3(const vec3 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
}

glm::vec3 &glm::vec3::operator=(const vec3 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    
    return *this;
}
glm::vec3 glm::vec3::operator+(const vec3 &other) const
{
    return vec3(x + other.x, y + other.y, z + other.z);
}
glm::vec3 glm::vec3::operator-(const vec3 &other) const
{
    return vec3(x - other.x, y - other.y, z - other.z);
}
glm::vec3 glm::vec3::operator*(const float num) const
{
    return vec3(x * num, y * num, z * num);
}

float glm::vec3::length() const
{
    return sqrtf( x * x + y * y + z * z);
}
void glm::vec3::print() const
{
    std::cout << "vec2: x -> " << x << "\t|\ty->" << y << "\t|\tz->" << z << std::endl; 
}

// ---------- vec4 ----------
glm::vec4::vec4()
{
    for(int i = 0; i < 4; i++) entries[i] = 0.0f;
}
glm::vec4::vec4(float x, float y, float z, float w)
{
    entries[0] = x; entries[1] = y; entries[2] = z; entries[3] = w;
}
glm::vec4::vec4(const vec2& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
    entries[2] = 0.0f;
    entries[3] = 0.0f;
}
glm::vec4::vec4(const vec3& v)
{
    entries[0] = v.entries[0];
    entries[1] = v.entries[1];
    entries[2] = v.entries[2];
    entries[3] = 0.0f;
}
glm::vec4::vec4(const vec4 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
}

glm::vec4 &glm::vec4::operator=(const vec4 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;

    return *this;
}
glm::vec4 glm::vec4::operator+(const vec4 &other) const
{
    return vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}
glm::vec4 glm::vec4::operator-(const vec4 &other) const
{
    return vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}
glm::vec4 glm::vec4::operator*(const float num) const
{
    return vec4(x * num, y * num, z * num, w * num);
}

float glm::vec4::length() const
{
    return sqrtf(x * x + y * y + z * z + w * w);
}
void glm::vec4::print() const
{
    std::cout << "vec2: x -> " << x << "\t|\ty->" << y << "\t|\tz->" << z << "\t|\tw->" << w << std::endl; 
}

// -------------------- Vector Math Functions --------------------

float glm::dot_product(const vec3 &v1, const vec3 &v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

glm::vec3 glm::cross_product(const vec3 &v1, const vec3 &v2)
{
    glm::vec3 result;

    result.x = (v1.y * v2.z) - (v1.z * v2.y);
    result.y = (v1.z * v2.x) - (v1.x * v2.z);
    result.z = (v1.x * v2.y) - (v1.y * v2.x);

    return result;
}

glm::vec2 glm::normalize(const vec2 &v)
{
    float magnitude = v.length();

    if (magnitude == 0) throw std::runtime_error("Devide by zero in glmath.cpp -> glm::normalize");

    return vec2(v.x / magnitude, v.y / magnitude);
}
glm::vec3 glm::normalize(const vec3 &v)
{
    float magnitude = v.length();

    if (magnitude == 0) throw std::runtime_error("Devide by zero in glmath.cpp -> glm::normalize");

    return vec3(v.x / magnitude, v.y / magnitude, v.z / magnitude);
}
glm::vec4 glm::normalize(const vec4 &v)
{
    float magnitude = v.length();

    if (magnitude == 0) throw std::runtime_error("Devide by zero in glmath.cpp -> glm::normalize");

    return vec4(v.x / magnitude, v.y / magnitude, v.z / magnitude, v.w / magnitude);
}

// -------------------- OpenGL Create Matrices Functions --------------------
glm::mat4 glm::create_traslation_matrix(const vec3& translation){
    glm::mat4 m;

    m.entries[0] = 1.0f;   m.entries[4] = 0.0f;   m.entries[8] = 0.0f;   m.entries[12] = translation.x;
    m.entries[1] = 0.0f;   m.entries[5] = 1.0f;   m.entries[9] = 0.0f;   m.entries[13] = translation.y;
    m.entries[2] = 0.0f;   m.entries[6] = 0.0f;   m.entries[10] = 1.0f;  m.entries[14] = translation.z;
    m.entries[3] = 0.0f;   m.entries[7] = 0.0f;   m.entries[11] = 0.0f;  m.entries[15] = 1.0f;

    return m;
}

glm::mat4 glm::create_rotation_z_matrix(float angle)
{
    glm::mat4 m;

    float rad = angle * M_PI / 180;

    float c = cosf(rad);
    float s = sinf(rad);


    m.entries[0] = c;   m.entries[4] = -s;   m.entries[8] = 0.0f;   m.entries[12] = 0.0f;
    m.entries[1] = s;   m.entries[5] = c;   m.entries[9] = 0.0f;   m.entries[13] = 0.0f;
    m.entries[2] = 0.0f;   m.entries[6] = 0.0f;   m.entries[10] = 1.0f;  m.entries[14] = 0.0f;
    m.entries[3] = 0.0f;   m.entries[7] = 0.0f;   m.entries[11] = 0.0f;  m.entries[15] = 1.0f;


    return m;
}

glm::mat4 glm::create_view_transform_matrix(const vec3 &from, const vec3 &to)
{
    mat4 m;

    vec3 global_up = vec3(0.0f, 0.0f, 1.0f);
    vec3 f = normalize(to - from); // Create f vector 

    // check if f and g is not an same or reversed vectors
    if (dot_product(f, global_up) > 0.99f)
    {
        global_up = vec3(0.0f, 1.0f, 0.0f); // choose other global up
    }


    vec3 r = normalize(cross_product(f, global_up));    // Create r vector
    vec3 u = normalize(cross_product(r, f));            // Create u vector


    m.entries[0] = r.x;   m.entries[4] = r.y;   m.entries[8] = r.z;   m.entries[12] = -dot_product(r, from);
    m.entries[1] = u.x;   m.entries[5] = u.y;   m.entries[9] = u.z;   m.entries[13] = -dot_product(u, from);
    m.entries[2] = -f.x;  m.entries[6] = -f.y;  m.entries[10] = -f.z; m.entries[14] = dot_product(f, from);
    m.entries[3] = 0.0f;  m.entries[7] = 0.0f;  m.entries[11] = 0.0f; m.entries[15] = 1.0f;

    return m;
}

glm::mat4 glm::create_projection_matrix(float aspect, float pov, float n, float f)
{
    mat4 m;

    pov = pov / 2 / M_PI / 180;
    float t = tanf(pov);

    n = -n;
    f = -f;


    m.entries[0] = 1.0f / (aspect * t);
    m.entries[5] = 1.0f / t;
    m.entries[10] = -(n + f) / (n - f);
    m.entries[11] = -1.0f;
    m.entries[14] = 2 * n * f / (n - f);

    return m;
}
