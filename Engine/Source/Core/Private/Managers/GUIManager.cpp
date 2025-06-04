// Copyright (c) 2025 Eric Jeker. All rights reserved.


#include "Managers/GUIManager.h"

#include "Command.h"
#include "CommandRegistry.h"

#include <ResourceManager.h>
#include <TimeTicker.h>

GUIManager::GUIManager(ResourceManager& resourceManager, CommandRegistry& commandRegistry)
    : _resourceManager(resourceManager), _commandRegistry(commandRegistry)
{
};

void GUIManager::AddText(const std::string& label, const sf::Vector2f& position, const int& size, const sf::Color& color, const sf::Text::Style& style)
{
    _texts.Add(label, position, size, color, style);
}

void GUIManager::AddButton(const std::string& label, const sf::Vector2f& position, const int& size, const int& commandId)
{
    _buttons.Add(label, position, size, commandId);
}

void GUIManager::Update(const sf::Time& deltaTime)
{
    UpdateTexts(deltaTime);
    UpdateButtons(deltaTime);
}
void GUIManager::UpdateTexts(const sf::Time& deltaTime) {}
void GUIManager::UpdateButtons(const sf::Time& deltaTime) {}

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

void GUIManager::OnMousePressed(const sf::Event::MouseButtonPressed& event) const
{
    const sf::Vector2i mousePosition = event.position;

    // For each interactable element we'll check if the mouse is inside the bounds of the element
    for (int i = 0; i < _buttons.Size(); ++i)
    {
        const auto& button = _buttonDrawables[i];
        if (!button->getGlobalBounds().contains(sf::Vector2<float>(mousePosition)))
        {
            continue;
        }

        // Call the button's assigned action
        _commandRegistry.Execute(_buttons.commandIds[i]);

        // We don't cascade the event to other buttons
        return;
    }
}
