// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <Logger.h>
#include <Screen.h>

class GameScreen final : public Screen
{
public:
    explicit GameScreen(SpaceInvaders& game);
    ~GameScreen() override = default;

    void Activate() override;
    void Shutdown() override;
    void HandleEvents(const std::optional<sf::Event>& event) override;

    /**
     * Updates the game screen state.
     * @param {TimeTicker} timeTicker - The time information
     */
    void Update(const TimeTicker& timeTicker) override;
    void Render() const override;

private:
    Logger _logger;
};

#endif
