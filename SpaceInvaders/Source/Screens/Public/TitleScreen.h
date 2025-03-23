// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <Logger.h>
#include <Screen.h>

class TitleScreen : public Screen {
public:
    TitleScreen(SpaceInvaders& game);

    void Update(const TimeTicker& timeTicker) override;
    void Render() const override;
    void Activate() override;
    void Shutdown() override;

private:
    const Logger _logger;
};

#endif
