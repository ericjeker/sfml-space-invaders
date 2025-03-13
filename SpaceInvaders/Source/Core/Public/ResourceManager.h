// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <unordered_map>
#include <variant>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();
    void LoadResource(const std::string& name, const std::string& path);
    void UnloadResource(const std::string& name);
    void ClearResources();

    /** Templates are evaluated at compile time so they need to be defined here */
    template <typename T>
    T& GetResource(const std::string& name)
    {
        const auto it = _Resources.find(name);
        if (it == _Resources.end())
        {
            throw std::runtime_error("Resource not found: " + name);
        }

        T** resource = std::get_if<T*>(&it->second);
        if (resource == nullptr)
        {
            throw std::runtime_error("Type mismatch for resource: " + name);
        }

        return **resource;
    }

    template <typename T>
    void SetResource(const std::string& name, T* resource)
    {
        _Resources[name] = resource;
    }

private:
    using ResourceVariant = std::variant<
        sf::CircleShape*,
        sf::Font*,
        sf::Sprite*,
        sf::Texture*
        /**  Add more resource types as needed*/>;

    std::unordered_map<std::string, ResourceVariant> _Resources;
};

#endif
