// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Clickable.h"

sf::FloatRect Clickable::getGlobalBounds() const
{
    return *_view.getGlobalBounds();
}