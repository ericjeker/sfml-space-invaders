// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "Component.h"

#include <functional>

#include <SFML/Graphics/Sprite.hpp>

class Button : public Component {
private:
    sf::Sprite _sprite;
    std::function<void()> _onClick;

public:
    Button(const sf::Texture& texture, std::function<void()> onClick);
    void Update(const TimeTicker& timeTicker) override;
    void Render() const override;
};

#endif
