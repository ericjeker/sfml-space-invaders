// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include "CommandRegistry.h"
#include "Collections/GUI/TextCollection.h"
#include "Collections/GUI/ButtonCollection.h"
#include "ResourceManager.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

/**
 * The GUIManager take care of GUI elements and their interaction. Accepting events and checking for hits
 * on the elements, modifying their state. The GUIManager is also responsible for rendering these elements.
 *
 * It's doing a little bit too much honestly, and at some point I might outsource the rendering to a RenderingSystem.
 * Probably the Inputs could also be handled to a InputHandler, interacting with a CommandRegistry.
 *
 * But let's KISS for now.
 */
class GUIManager
{
public:
    GUIManager(ResourceManager& resourceManager, CommandRegistry& commandRegistry);
    ~GUIManager() = default;

    void Update(const sf::Time& deltaTime);
    void Render(sf::RenderTexture& renderTexture);

    // Texts
    void AddText(const std::string& label, const sf::Vector2f& position, const int& size, const sf::Color& color, const sf::Text::Style& style);
    void UpdateTexts(const sf::Time& deltaTime);
    void RenderTexts(sf::RenderTexture& renderTexture);

    // Buttons
    void AddButton(const std::string& label, const sf::Vector2f& position, const int& size, const int& commandId);
    void UpdateButtons(const sf::Time& deltaTime);
    void RenderButtons(sf::RenderTexture& renderTexture);

    // Potential future events I will handle
    void OnMousePressed(const sf::Event::MouseButtonPressed& event) const;
    void OnMouseReleased() {};
    void OnKeyPressed() {};
    void OnMouseMove() {};
    void OnMouseWheelMoved() {};
    void OnWindowResized() {};

private:
    // We need the resource manager to load images and fonts
    ResourceManager& _resourceManager;
    CommandRegistry& _commandRegistry;

    // Collection of all the elements displayed on screen (SoA)
    // TODO: I am not sure yet if the GUIManager should hold the state of the elements, maybe not...
    //   maybe the Screen should hold the state, and the GUIManager just receive it in parameter
    ButtonCollection _buttons;
    TextCollection _texts;

    // The actual sf::Drawable elements
    std::vector<std::shared_ptr<sf::Text>> _buttonDrawables;
    std::vector<std::shared_ptr<sf::Text>> _textDrawables;

    void InitializeButtonDrawables();
    void InitializeTextDrawables();

};

#endif
