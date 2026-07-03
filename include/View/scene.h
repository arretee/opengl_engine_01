#pragma once

#include <vector>
#include <unordered_map>
#include <memory>

#include "Model/object.h"
#include "Model/mesh.h"
#include "Model/transform.h"



class Scene {
    private:
        unsigned int next_id = 0;
        std::vector<std::shared_ptr<Object>> objects;

    public:
        Scene();

        unsigned int add_object(const std::shared_ptr<Object>& object_ptr);

        std::shared_ptr<Object> get_object(unsigned int id) const;
        const std::vector<std::shared_ptr<Object>>& get_objects() const;
};