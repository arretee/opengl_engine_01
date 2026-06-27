#include "glmath/mat_functions.h"


// -------------------- Maricies Creation --------------------

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

glm::mat4 glm::create_rotation_y_matrix(float angle)
{
    glm::mat4 m;

    float rad = angle * M_PI / 180;

    float c = cosf(rad);
    float s = sinf(rad);


    m.entries[0] = c;        m.entries[4] = 0.0f;   m.entries[8] = s;        m.entries[12] = 0.0f;
    m.entries[1] = 0.0f;     m.entries[5] = 1.0f;   m.entries[9] = 0.0f;     m.entries[13] = 0.0f;
    m.entries[2] = -s;       m.entries[6] = 0.0f;   m.entries[10] = c;       m.entries[14] = 0.0f;
    m.entries[3] = 0.0f;     m.entries[7] = 0.0f;   m.entries[11] = 0.0f;    m.entries[15] = 1.0f;

    return m;
}

glm::mat4 glm::create_rotation_x_matrix(float angle)
{
    glm::mat4 m;

    float rad = angle * M_PI / 180;

    float c = cosf(rad);
    float s = sinf(rad);


    m.entries[0] = 1.0f;     m.entries[4] = 0.0f;   m.entries[8] = 0.0f;     m.entries[12] = 0.0f;
    m.entries[1] = 0.0f;     m.entries[5] = c;      m.entries[9] = -s;       m.entries[13] = 0.0f;
    m.entries[2] = 0.0f;     m.entries[6] = s;      m.entries[10] = c;       m.entries[14] = 0.0f;
    m.entries[3] = 0.0f;     m.entries[7] = 0.0f;   m.entries[11] = 0.0f;    m.entries[15] = 1.0f;

    return m;
}

glm::mat4 glm::create_rotation_matrix(glm::vec3 v)
{
    return create_rotation_z_matrix(v.z) * create_rotation_y_matrix(v.y) * create_rotation_x_matrix(v.x);
}

glm::mat4 glm::create_view_transform_matrix(const vec3 &from, const vec3 &to)
{
    mat4 m;

    vec3 global_up = vec3(0.0f, 0.0f, 1.0f);
    vec3 f = normalize(to - from); // Create f vector 

    // check if f and g is not an same or reversed vectors
    if (fabs(dot_product(f, global_up)) > 0.99f)
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

glm::mat4 glm::create_view_transform_matrix(const vec3 &from, const vec3 &f, const vec3 &r, const vec3 &u)
{
    mat4 m;

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

glm::mat4 glm::create_scale_matrix(const glm::vec3& scale){
    mat4 m;

    m.entries[0] = scale.x;  m.entries[4] = 0.0f;    m.entries[8] = 0.0f;     m.entries[12] = 0.0f;
    m.entries[1] = 0.0f;     m.entries[5] = scale.y; m.entries[9] = 0.0f;     m.entries[13] = 0.0f;
    m.entries[2] = 0.0f;     m.entries[6] = 0.0f;    m.entries[10] = scale.z; m.entries[14] = 0.0f;
    m.entries[3] = 0.0f;     m.entries[7] = 0.0f;    m.entries[11] = 0.0f;    m.entries[15] = 1.0f;

    return m;
}