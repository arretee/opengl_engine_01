#include "View/render.h"

// -------------------- Constructor Destructor --------------------

Render::Render(float a, float fov, float near, float far){
    aspect = a;
    this->fov = fov;
    this->near = near;
    this->far = far;
}



// -------------------- Getters Setters --------------------
float Render::get_aspect() const { return aspect; }
float Render::get_fov() const { return fov; }
float Render::get_near() const { return near; }
float Render::get_far() const { return far; }

void Render::set_aspect(float value) { aspect = value; }
void Render::set_fov(float value) { fov = value; }
void Render::set_near(float value) { near = value; }
void Render::set_far(float value) { far = value; }



void Render::render(const Scene& scene) {
    for(const auto& object: scene.get_objects())
    {
        if (object->mesh != nullptr && object -> shader != nullptr)
        {
            // Use shader
            object -> shader -> use();  

            // Upload Object if not uploaded
            if(object -> mesh -> is_uploaded() == false) { object -> mesh ->upload(); }


            // Upload uniforms
            glm::mat4 m = glm::create_projection_matrix(aspect, fov, near, far) * camera.get_view_matrix() * object->transform.get_matrix();
            object -> shader -> set_mat4("matrix", m);


            // Draw object
            object -> mesh -> draw(GL_TRIANGLES);
        }

        else
        {
            std::cout << "render error: mesh or shader is nullptr" << std::endl;
        }
    }
}