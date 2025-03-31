// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H
#include <TimeTicker.h>

class Component {
public:
    virtual void Update(const TimeTicker& timeTicker) = 0;
    virtual void Render() const = 0;
    virtual ~Component() = default;
};

#endif
