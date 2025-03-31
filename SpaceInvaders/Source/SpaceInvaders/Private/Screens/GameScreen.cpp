// Copyright (c) Eric Jeker. All Rights Reserved.

#include "GameScreen.h"

#include <Configuration.h>
#include <SpaceInvaders.h>
#include <TimeTicker.h>
#include <TitleScreen.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameScreen::GameScreen(SpaceInvaders& game) : Screen(game), _logger("GameScreen", game.GetConfiguration().LogLevel) {}

void GameScreen::Activate()
{
    _logger.Debug("Activating GameScreen");

    Configuration configuration = GetGame().GetConfiguration();

    /** Load resources when the Screen is activated */
    std::shared_ptr<sf::CircleShape> circle = std::make_shared<sf::CircleShape>(3.f);
    circle->setFillColor(sf::Color::White);
    circle->setOrigin({circle->getRadius(), circle->getRadius()});
    circle->setPosition({-1.f, -1.f});
    GetGame().GetResourceManager().SetResource<sf::CircleShape>("GameScreen::ClickDot",
                                                                std::shared_ptr<sf::CircleShape>(circle));

    if (!sf::Shader::isAvailable())
    {
        _logger.Error("Shader is not available");
        return;
    }

    std::shared_ptr<sf::Shader> shader = std::make_shared<sf::Shader>();
    if (!shader->loadFromFile("Assets/Shaders/shader.frag", sf::Shader::Type::Fragment))
    {
        _logger.Error("Failed to load 'Assets/Shaders/shader'");
        return;
    }

    shader->setUniform("u_resolution", sf::Glsl::Vec2{configuration.WindowSize});
    shader->setUniform("u_time", 5.f);

    GetGame().GetResourceManager().SetResource<sf::Shader>("GameScreen::Shader", std::shared_ptr<sf::Shader>(shader));
}

void GameScreen::Shutdown()
{
    _logger.Debug("Shutting down GameScreen");
    GetGame().GetResourceManager().UnloadResource("GameScreen::ClickDot");
    GetGame().GetResourceManager().UnloadResource("GameScreen::Shader");
}

void GameScreen::Update(const TimeTicker& timeTicker)
{
    if (GetGame().GetState().isPaused)
    {
        return;
    }

    auto& resourceManager = GetGame().GetResourceManager();

    std::shared_ptr<sf::CircleShape> circle = resourceManager.GetResource<sf::CircleShape>("GameScreen::ClickDot");
    auto color = circle->getFillColor();
    color.a = color.a * 0.98f;
    circle->setFillColor(color);

    std::shared_ptr<sf::Shader> shader = resourceManager.GetResource<sf::Shader>("GameScreen::Shader");
    shader->setUniform("u_time", timeTicker.elapsedTime.asSeconds());
}

void GameScreen::Render() const
{
    auto& resourceManager = GetGame().GetResourceManager();
    auto& window = GetGame().GetWindow();

    std::shared_ptr<sf::Shader> shader = resourceManager.GetResource<sf::Shader>("GameScreen::Shader");
    shader->setUniform("u_texture", sf::Shader::CurrentTexture);

    // Create a rectangle that covers the entire window
    sf::RectangleShape texture;
    texture.setSize(sf::Vector2f(window.getSize()));
    texture.setPosition({0, 0});

    // Draw the rectangle with the shader applied
    sf::RenderStates states;
    states.shader = shader.get();
    window.draw(texture, states);

    // Draw the click dot
    std::shared_ptr<sf::CircleShape> circle = resourceManager.GetResource<sf::CircleShape>("GameScreen::ClickDot");
    window.draw(*circle);
}

void GameScreen::HandleEvents(const std::optional<sf::Event>& event)
{
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
        {
            GetGame().GetScreenManager().SetCurrentScreen<TitleScreen>();
        }
    }
    else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
    {
        std::shared_ptr<sf::CircleShape> circle =
            GetGame().GetResourceManager().GetResource<sf::CircleShape>("GameScreen::ClickDot");
        circle->setPosition(sf::Vector2f(mouseButtonPressed->position));
        circle->setFillColor(sf::Color::White);
    }
}
