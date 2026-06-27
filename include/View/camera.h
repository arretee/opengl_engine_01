#pragma once

#include "config.h"


class Camera {
    private:
        glm::vec3 camera_pos;

        glm::vec3 forward;
        glm::vec3 right;
        glm::vec3 up;


        // yaw -> right, left
        // pitch -> up down
        float yaw, pitch;



    public:
        Camera();
        ~Camera();


        /* 
            camera_pos set function 
        */
        void set_camera_pos(const glm::vec3& pos);
        /* 
            camera_pos get function s
        */
        glm::vec3 get_camera_pos() const;

        /*
            Gets target to focus camera on
        */
        void set_camera_target(const glm::vec3& target);

        /*
            Gets mouse data to change camera direction

            input: dx, dy of the mouse, sensitivity
            output: none
        */
        void process_mouse(float dx, float dy, float sensitivity);

        /*
            Function updates the vectors
        */
        void upadate_vectors();


        /* 
            Function creates view matrix
        */
        glm::mat4 get_view_matrix() const;
};