// Copyright (c) Eric Jeker. All Rights Reserved.

#include "ResourceManager.h"

#include <ranges>

ResourceManager::ResourceManager()
{

};

ResourceManager::~ResourceManager() = default;

void ResourceManager::UnloadResource(const std::string& name)
{
    if (const auto it = _Resources.find(name); it != _Resources.end())
    {
        std::visit([](auto& resource)
        {
            if (resource != nullptr)
            {
                delete resource;
                resource = nullptr;
            }
        }, it->second);

        _Resources.erase(name);
    }
}

void ResourceManager::ClearResources()
{
    /** Create a copy of the keys to avoid modifying the collection during iteration */
    std::vector<std::string> resourceKeys;
    resourceKeys.reserve(_Resources.size());

    for (const auto& key : _Resources | std::views::keys)
    {
        resourceKeys.push_back(key);
    }

    /** Now unload each resource using the copied keys */
    for (const auto& key : resourceKeys)
    {
        UnloadResource(key);
    }
}
