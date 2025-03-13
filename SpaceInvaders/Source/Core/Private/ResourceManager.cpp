// Copyright (c) Eric Jeker. All Rights Reserved.

#include "ResourceManager.h"

#include <stdexcept>

ResourceManager::ResourceManager()
{

};

ResourceManager::~ResourceManager() = default;

void ResourceManager::UnloadResource(const std::string& name)
{
    if (const auto it = _Resources.find(name); it != _Resources.end())
    {
        std::visit([](auto&& resource)
        {
            delete resource;
        }, it->second);

        _Resources.erase(name);
    }
}

void ResourceManager::ClearResources()
{
    for (auto& pair : _Resources)
    {
        UnloadResource(pair.first);
    }
}
