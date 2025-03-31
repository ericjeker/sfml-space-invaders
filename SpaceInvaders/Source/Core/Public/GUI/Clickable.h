// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <memory>


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

struct Clickable
{
public:
    // Delegate to _drawable
    [[nodiscard]] sf::FloatRect getGlobalBounds() const;

private:
    std::shared_ptr<sf::Drawable> _view;
};

#endif