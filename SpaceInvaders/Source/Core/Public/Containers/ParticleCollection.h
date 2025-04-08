// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PARTICLECOLLECTION_H
#define PARTICLECOLLECTION_H

#include <vector>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

struct ParticleCollection
{
    std::vector<sf::Vector2f> positions;
    std::vector<sf::Color> colors;
    std::vector<float> sizes;
    std::vector<float> velocities;
    std::vector<float> lifetimes;

    void Add(const sf::Vector2f& position, const sf::Color& color, const float size, const float velocity,
             const float lifetime)
    {
        positions.push_back(position);
        colors.push_back(color);
        sizes.push_back(size);
        velocities.push_back(velocity);
        lifetimes.push_back(lifetime);
    }

    void Reserve(const size_t count)
    {
        positions.reserve(count);
        colors.reserve(count);
        sizes.reserve(count);
        velocities.reserve(count);
        lifetimes.reserve(count);
    }

    void Clear()
    {
        positions.clear();
        colors.clear();
        sizes.clear();
        velocities.clear();
        lifetimes.clear();
    }

    size_t Size() const
    {
        return positions.size();
    }
};

#endif
