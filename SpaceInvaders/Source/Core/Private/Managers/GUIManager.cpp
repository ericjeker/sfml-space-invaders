// Copyright (c) 2025 Eric Jeker. All rights reserved.


#include "Managers/GUIManager.h"

#include <ResourceManager.h>
#include <TimeTicker.h>

GUIManager::GUIManager(const ResourceManager& resourceManager)
    : _resourceManager(resourceManager) {

      };


void GUIManager::AddText(std::string label, sf::Vector2f position, int size, sf::Color color, sf::Text::Style style)
{
    _texts.Add(label, position, size, color, style);
}

void GUIManager::AddButton(const std::string label, const sf::Vector2f position, const int size)
{
    _buttons.Add(label, position, size, 0);
}

void GUIManager::Update(const TimeTicker& timeTicker) {}
void GUIManager::UpdateTexts(TimeTicker& timeTicker) {}
void GUIManager::UpdateButtons(TimeTicker& timeTicker) {}

/**
 * @brief Initializes drawable objects for buttons in the GUI.
 *
 * The primary purpose of this method is to prepare drawable representations for
 * subsequent button rendering.
 */
void GUIManager::InitializeButtonDrawables()
{
    _buttonDrawables.clear();

    for (int i = 0; i < _buttons.Size(); ++i)
    {
        auto button = std::make_shared<sf::Text>(*_resourceManager.GetResource<sf::Font>("DefaultFont"));
        button->setFillColor(sf::Color::White);
        _buttonDrawables.push_back(button);
    }
}
void GUIManager::InitializeTextDrawables()
{
    _textDrawables.clear();

    for (int i = 0; i < _texts.Size(); ++i)
    {
        auto button = std::make_shared<sf::Text>(*_resourceManager.GetResource<sf::Font>("DefaultFont"));
        button->setFillColor(sf::Color::White);
        _textDrawables.push_back(button);
    }
}


void GUIManager::Render(sf::RenderTexture& renderTexture)
{
    RenderButtons(renderTexture);
    RenderTexts(renderTexture);
}

void GUIManager::RenderButtons(sf::RenderTexture& renderTexture)
{
    if (_buttonDrawables.empty() || _buttonDrawables.size() != _buttons.Size())
    {
        InitializeButtonDrawables();
    }

    for (int i = 0; i < _buttons.Size(); ++i)
    {
        auto& button = _buttonDrawables[i];
        button->setString(_buttons.labels[i]);
        button->setCharacterSize(_buttons.sizes[i]);
        button->setOrigin({button->getGlobalBounds().size.x / 2, button->getGlobalBounds().size.y / 2});
        button->setPosition(_buttons.positions[i]);

        renderTexture.draw(*button);
    }
}

void GUIManager::RenderTexts(sf::RenderTexture& renderTexture)
{
    if (_textDrawables.empty() || _textDrawables.size() != _texts.Size())
    {
        InitializeTextDrawables();
    }

    for (int i = 0; i < _texts.Size(); ++i)
    {
        auto& text = _textDrawables[i];
        text->setString(_texts.labels[i]);
        text->setCharacterSize(_texts.sizes[i]);
        text->setOrigin({text->getGlobalBounds().size.x / 2, text->getGlobalBounds().size.y / 2});
        text->setPosition(_texts.positions[i]);

        renderTexture.draw(*text);
    }

}
