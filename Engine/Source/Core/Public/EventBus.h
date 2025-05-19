// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <optional>
#include <vector>


struct Event
{
};

/**
 * @brief Event bus class that manages event subscriptions and dispatches events.
 *
 * The Event Bus is based on the buffer ring pattern, which allows for efficient event handling and management.
 */
class EventBus
{
public:
    explicit EventBus(size_t capacity);
    ~EventBus() = default;

    /**
     * Push an event at the tail of the ring buffer.
     */
    void Push(const Event& event);

    /**
     * Pop the event at the head of the ring buffer.
     */
    std::optional<Event> Pop();

private:
    size_t _capacity;
    std::vector<Event> _buffer;

    size_t _head = 0;
    size_t _tail = 0;
};


#endif
