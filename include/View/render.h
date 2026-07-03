#pragma once

#include <vector>
#include <memory>

#include "View/camera.h"
#include "View/scene.h"

#include "Model/object.h"
#include "glmath/glmath.h"

class Render {
    private:

        float aspect, fov, near, far; 

    public:
        Camera camera;

        // Constructors Destructors
        Render(float a, float fov, float near, float far);
        ~Render() = default;

        // Getters setters
        float get_aspect() const;
        float get_fov() const;
        float get_near() const;
        float get_far() const;

        void set_aspect(float value);
        void set_fov(float value);
        void set_near(float value);
        void set_far(float value);


        // Methods
        void render(const Scene& scene);
};