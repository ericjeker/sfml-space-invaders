// Copyright (c) Eric Jeker. All Rights Reserved.

#include "ResourceManager.h"

#include <stdexcept>

void ResourceManager::UnloadResource(const std::string& name)
{
    if (const auto it = _resources.find(name); it != _resources.end())
    {
        std::visit(
            [](auto& resource)
            {
                if (resource != nullptr)
                {
                    delete resource;
                    resource = nullptr;
                }
            },
            it->second);

        _resources.erase(name);
    }
}

void ResourceManager::CleanUp()
{
    /** Create a copy of the keys to avoid modifying the collection during iteration */
    std::vector<std::string> resourceKeys;
    resourceKeys.reserve(_resources.size());

    for (const auto& pair : _resources)
    {
        resourceKeys.push_back(pair.first);
    }

    /** Now unload each resource using the copied keys */
    for (const auto& key : resourceKeys)
    {
        UnloadResource(key);
    }
}
