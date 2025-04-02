// Copyright (c) Eric Jeker. All Rights Reserved.

#include "Screen.h"

Screen::Screen(SpaceInvaders& game) : _game(game) {}

SpaceInvaders& Screen::GetGame() const
{
    return _game;
}

void Screen::AddEntity(const std::shared_ptr<Entity>& entity)
{
    _entities.push_back(entity);
}
