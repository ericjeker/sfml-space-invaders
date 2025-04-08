// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef BUTTONCOLLECTION_H
#define BUTTONCOLLECTION_H

#include <string>
#include <vector>

#include <SFML/System/Vector2.hpp>

struct ButtonCollection
{
    std::vector<sf::Vector2f> positions;
    std::vector<int> sizes;
    std::vector<bool> isHovered;
    std::vector<bool> isPressed;
    std::vector<int> actionIds;
    std::vector<std::string> labels;

    // Add a new button
    void Add(const std::string label, const sf::Vector2f position, const int size, const int actionId)
    {
        positions.push_back(position);
        sizes.push_back(size);
        isHovered.push_back(false);
        isPressed.push_back(false);
        actionIds.push_back(actionId);
        labels.push_back(label);
    }

    // Reserve memory for expected number of buttons
    void Reserve(size_t count)
    {
        positions.reserve(count);
        sizes.reserve(count);
        isHovered.reserve(count);
        isPressed.reserve(count);
        actionIds.reserve(count);
        labels.reserve(count);
    }

    // Clear all buttons
    void Clear()
    {
        positions.clear();
        sizes.clear();
        isHovered.clear();
        isPressed.clear();
        actionIds.clear();
        labels.clear();
    }

    // Get number of buttons
    [[nodiscard]] size_t Size() const
    {
        return positions.size();
    }
};

#endif
