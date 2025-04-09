// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include "TextCollection.h"
#include "Collections/GUI/ButtonCollection.h"

#include <ResourceManager.h>
#include <TimeTicker.h>

#include <SFML/Graphics/RenderTexture.hpp>

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
    explicit GUIManager(const ResourceManager& resourceManager);
    ~GUIManager() = default;

    void Update(const sf::Time& deltaTime);
    void Render(sf::RenderTexture& renderTexture);

    // Texts
    void AddText(std::string label, sf::Vector2f position, int size, sf::Color color, sf::Text::Style style);
    void UpdateTexts(const sf::Time& deltaTime);
    void RenderTexts(sf::RenderTexture& renderTexture);

    // Buttons
    void AddButton(std::string label, sf::Vector2f position, int size);
    void UpdateButtons(const sf::Time& deltaTime);
    void RenderButtons(sf::RenderTexture& renderTexture);

private:
    // We need the resource manager to load images and fonts
    ResourceManager _resourceManager;

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

    // Potential future events I will handle
    void OnMousePressed() {};
    void OnMouseReleased() {};
    void OnKeyPressed() {};
    void OnMouseMove() {};
    void OnMouseWheelMoved() {};
    void OnWindowResized() {};
};

#endif
