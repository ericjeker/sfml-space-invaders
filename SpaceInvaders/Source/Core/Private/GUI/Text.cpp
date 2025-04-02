// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Text.h"

void Text::Update(const TimeTicker& timeTicker, const GameState& gameState) {}

TextRenderer::TextRenderer(std::shared_ptr<const TextComponent> component) : _component(component)
{
    _text = std::make_unique<sf::Text>(*_component->font, _component->text, _component->size);
    _text->setString(_component->text);
    _text->setCharacterSize(_component->size);
    _text->setFillColor(_component->color);
    _text->setStyle(_component->style);
    _text->setOrigin(_text->getGlobalBounds().getCenter());
    _text->setPosition(_component->position);
}

void TextRenderer::Render(sf::RenderTexture& texture) const
{
    texture.draw(*_text);
}
