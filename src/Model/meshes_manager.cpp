#include "Model/meshes_manager.h"

MeshesManager::MeshesManager() { }

MeshesManager::~MeshesManager() { }

std::shared_ptr<Mesh> MeshesManager::load_mesh(const std::string &path)
{
    return std::shared_ptr<Mesh>();
}

void MeshesManager::create_mesh(const std::string& path, std::vector<float>&& vertices, std::vector<uint32_t>&& indices)
{
    meshes[path] = std::make_shared<Mesh>(Mesh(std::move(vertices), std::move(indices)));
}


std::shared_ptr<Mesh> MeshesManager::get_mesh(const std::string &path)
{
    // Find mesh
    auto it = meshes.find(path);

    if (it != meshes.end())
        return it->second;


    // Load mesh if not loaded
    auto mesh = load_mesh(path);
    meshes[path] = mesh;

    return mesh;
}
