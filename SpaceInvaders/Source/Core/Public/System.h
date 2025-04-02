// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include "Entity.h"

#include <vector>

class System {
public:
    virtual ~System() = default;
    virtual void Render(std::vector<Entity> entities) const;
    virtual void Update(std::vector<Entity> entities, const TimeTicker& timeTicker, const GameState& gameState);
};

#endif
