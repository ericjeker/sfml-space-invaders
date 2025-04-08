// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include "TextCollection.h"
#include "Containers/GUI/ButtonCollection.h"

#include <ResourceManager.h>
#include <TimeTicker.h>

#include <SFML/Graphics/RenderTexture.hpp>

class GUIManager
{
public:
    explicit GUIManager(const ResourceManager& resourceManager);
    ~GUIManager() = default;

    void Update(const TimeTicker& timeTicker);
    void Render(sf::RenderTexture& renderTexture);

    // Texts
    void AddText(std::string label, sf::Vector2f position, int size, sf::Color color, sf::Text::Style style);
    void UpdateTexts(TimeTicker& timeTicker);
    void RenderTexts(sf::RenderTexture& renderTexture);

    // Buttons
    void AddButton(std::string label, sf::Vector2f position, int size);
    void UpdateButtons(TimeTicker& timeTicker);
    void RenderButtons(sf::RenderTexture& renderTexture);

private:
    ResourceManager _resourceManager;
    ButtonCollection _buttons;
    std::vector<std::shared_ptr<sf::Text>> _buttonDrawables;
    TextCollection _texts;
    std::vector<std::shared_ptr<sf::Text>> _textDrawables;

    void InitializeButtonDrawables();
    void InitializeTextDrawables();
};

#endif
