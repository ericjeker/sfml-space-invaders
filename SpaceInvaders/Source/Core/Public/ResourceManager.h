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
#include <SFML/Graphics/Text.hpp>

class ResourceManager
{
public:
    ResourceManager() = default;
    ~ResourceManager() = default;
    void LoadResource(const std::string& name, const std::string& path);
    void UnloadResource(const std::string& name);
    void CleanUp();

    /** Templates are evaluated at compile time so they need to be defined here */
    template <typename T>
    T& GetResource(const std::string& name)
    {
        const auto it = _resources.find(name);
        if (it == _resources.end())
        {
            throw std::runtime_error("Resource not found: " + name);
        }

        T** resource = std::get_if<T*>(&it->second);
        if (!resource || *resource == nullptr)
        {
            throw std::runtime_error("Type mismatch for resource: " + name);
        }

        return **resource;
    }

    /** Templates are evaluated at compile time so they need to be defined here */
    template <typename T>
    void SetResource(const std::string& name, T* resource)
    {
        _resources[name] = resource;
    }

private:
    using ResourceVariant = std::variant<
        sf::CircleShape*,
        sf::Font*,
        sf::Text*,
        sf::Sprite*,
        sf::Texture*
        /**  Add more resource types as needed*/>;

    std::unordered_map<std::string, ResourceVariant> _resources;
};

#endif
