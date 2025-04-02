// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef TEXTCOMPONENT_H
#define TEXTCOMPONENT_H

#include "Entity.h"
#include "RenderableEntity.h"

#include <string>
#include <SFML/Graphics.hpp>

struct TextComponent {
    std::shared_ptr<sf::Font> font;
    std::string text;
    int size{50};
    sf::Color color{sf::Color::White};
    std::uint32_t style: sf::Text::Bold;
    sf::Vector2f origin{0.f, 0.f};
    sf::Vector2f position{0.f, 0.f};
};

class Text : public Entity
{
public:
    explicit Text(std::shared_ptr<TextComponent> component);
    ~Text() override = default;
    void Update(const TimeTicker& timeTicker, const GameState& gameState) override;
    void Render(sf::RenderTexture& texture) const override;
private:
    std::shared_ptr<TextComponent> _component;
    TextRenderer _textRenderer;
};

#endif
