// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PADDLE_H
#define PADDLE_H

struct Transform;
struct Physics;
struct RigidBody;
struct PlayerController;

struct Paddle
{
    Transform transform;
    Physics physics;
    RigidBody rigidBody;
    PlayerController playerController;
};

#endif
