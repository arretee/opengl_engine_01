#include "View/camera.h"

// -------------------- Constructor Destructor --------------------
Camera::Camera(){ 
    camera_pos = glm::vec3(0.0f, 0.0f, 0.0f);

    forward = glm::vec3(0.0f, 0.0f, -1.0f);
    right   = glm::vec3(1.0f, 0.0f, 0.0f);
    up      = glm::vec3(0.0f, 1.0f, 0.0f);

    yaw = -90.0f;
    pitch = 0.0f;
}
Camera::~Camera() { }

// -------------------- Get Set --------------------
void Camera::set_camera_pos(const glm::vec3& pos){
     camera_pos = pos; 
    }
glm::vec3 Camera::get_camera_pos() const { 
    return camera_pos; 
}

void Camera::set_camera_target(const glm::vec3 &target)
{
    // Calculate vectors
    glm::vec3 global_up = glm::vec3(0.0f, 1.0f, 0.0f);
    forward = glm::normalize(target - camera_pos);

    // check if forward and g is not an same or reversed vectors
    if (fabs(glm::dot_product(forward, global_up)) > 0.99f)
    {
        global_up = glm::vec3(0.0f, 0.0f, 1.0f); // choose other global up
    }

    right = glm::normalize(glm::cross_product(forward, global_up));
    up = glm::normalize(glm::cross_product(right, forward));


    // Calculate Yaw Pitch
    pitch = asin(forward.y);
    yaw = atan2(forward.z, forward.x);
}


// -------------------- Mouse control --------------------
void Camera::process_mouse(float dx, float dy, float sensitivity){
    dx *= sensitivity;
    dy *= sensitivity;

    yaw += dx;
    pitch += dy;

    if (pitch > 1.553f){
        pitch = 1.553f;
    }
    else if (pitch < -1.553f){
        pitch = -1.553f;
    }

    upadate_vectors();
}

void Camera::upadate_vectors(){ 
    // Forward
    forward.x = cos(yaw) * cos(pitch);
    forward.y = sin(pitch);
    forward.z = sin(yaw) * cos(pitch);

    forward = glm::normalize(forward);


    // Get global up
    glm::vec3 global_up = glm::vec3(0.0f, 1.0f, 0.0f);

    // check if forward and g is not an same or reversed vectors
    if (fabs(glm::dot_product(forward, global_up)) > 0.99f)
    {
        global_up = glm::vec3(0.0f, 0.0f, 1.0f); // choose other global up
    }

    // Get right, up
    right = glm::normalize(glm::cross_product(forward, global_up));
    up = glm::normalize(glm::cross_product(right, forward));
}


// -------------------- Matrix --------------------
glm::mat4 Camera::get_view_matrix() const {
    return glm::create_view_transform_matrix(camera_pos, forward, right, up);
}