// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef TEXTCOLLECTION_H
#define TEXTCOLLECTION_H

#include <string>
#include <vector>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

struct TextCollection
{
    std::vector<std::string> labels;
    std::vector<sf::Vector2f> positions;
    std::vector<int> sizes;
    std::vector<sf::Color> colors;
    std::vector<sf::Text::Style> styles;

    // Add a new text
    void Add(const std::string label, const sf::Vector2f position, const int size, const sf::Color color,
             const sf::Text::Style style)
    {
        labels.push_back(label);
        positions.push_back(position);
        sizes.push_back(size);
        colors.push_back(color);
        styles.push_back(style);
    }

    // Reserve memory for expected number of text
    void Reserve(const size_t count)
    {
        positions.reserve(count);
        sizes.reserve(count);
        labels.reserve(count);
        colors.reserve(count);
        styles.reserve(count);
    }

    // Clear all text
    void Clear()
    {
        positions.clear();
        sizes.clear();
        labels.clear();
        colors.clear();
        styles.clear();
    }

    // Get number of text
    [[nodiscard]] size_t Size() const
    {
        return positions.size();
    }
};

#endif
