// Copyright (c) Eric Jeker. All Rights Reserved.

#include "ResourceManager.h"

void ResourceManager::UnloadResource(const std::string& name)
{
    if (const auto it = _resources.find(name); it != _resources.end())
    {
        _resources.erase(name);
    }
}

void ResourceManager::CleanUp()
{
    _resources.clear();
}
