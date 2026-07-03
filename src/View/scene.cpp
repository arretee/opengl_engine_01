#include "View/scene.h"

Scene::Scene() {next_id = 0;}

unsigned int Scene::add_object(const std::shared_ptr<Object>& object_ptr){
    objects.push_back(object_ptr);
    next_id = objects.size();

    return next_id - 1;
}


std::shared_ptr<Object> Scene::get_object(unsigned int id) const {
    if (id < next_id) 
    {
        return objects[id];
    }

    return nullptr;
}

const std::vector<std::shared_ptr<Object>>& Scene::get_objects() const
{
    return objects;
}