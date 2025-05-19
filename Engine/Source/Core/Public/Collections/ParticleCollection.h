// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PARTICLECOLLECTION_H
#define PARTICLECOLLECTION_H

#include <vector>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

/**
 * There is no game logic in a collection.
 * It's only holding the state of multiple elements close to each others in aligned std::vector.
 */
struct ParticleCollection
{
    std::vector<sf::Vector2f> positions;
    std::vector<sf::Color> colors;
    std::vector<float> sizes;
    std::vector<sf::Vector2f> velocities;
    std::vector<float> lifetimes;

    void Reserve(const size_t count)
    {
        positions.reserve(count);
        colors.reserve(count);
        sizes.reserve(count);
        velocities.reserve(count);
        lifetimes.reserve(count);
    }

    void Add(const sf::Vector2f& position, const sf::Color& color, const float size, const sf::Vector2f velocity,
             const float lifetime)
    {
        positions.push_back(position);
        colors.push_back(color);
        sizes.push_back(size);
        velocities.push_back(velocity);
        lifetimes.push_back(lifetime);
    }

    void Remove(const int index)
    {
        if (index >= GetSize()) {
            return;
        }

        // Use the "swap and pop" technique - move the last element to the position
        // of the element we want to remove, then remove the last element

        // Only perform the swap if we're not removing the last element
        if (index < GetSize() - 1) {
            positions[index] = positions.back();
            colors[index] = colors.back();
            sizes[index] = sizes.back();
            velocities[index] = velocities.back();
            lifetimes[index] = lifetimes.back();
        }

        // Remove the last elements from all vectors
        positions.pop_back();
        colors.pop_back();
        sizes.pop_back();
        velocities.pop_back();
        lifetimes.pop_back();
    }

    void Clear()
    {
        positions.clear();
        colors.clear();
        sizes.clear();
        velocities.clear();
        lifetimes.clear();
    }

    [[nodiscard]] size_t GetSize() const
    {
        return positions.size();
    }
};

#endif
