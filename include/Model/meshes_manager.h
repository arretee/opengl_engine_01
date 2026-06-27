#pragma once

#include <iostream>

#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <unordered_map>

#include <memory>


#include "Model/mesh.h"

class MeshesManager {
    private:
        // Vars
        std::unordered_map<std::string, std::shared_ptr<Mesh>> meshes;


        // Methods
        std::shared_ptr<Mesh> load_mesh(const std::string& path);


    public:
        // Constructors
        MeshesManager();
        ~MeshesManager();


        // Methods
        void create_mesh(const std::string& path, std::vector<float>&& vertices, std::vector<uint32_t>&& indices);
        std::shared_ptr<Mesh> get_mesh(const std::string& path);

};