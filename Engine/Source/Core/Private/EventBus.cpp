// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "EventBus.h"

#include <optional>

EventBus::EventBus(const size_t capacity)
    : _capacity(capacity)
{
    _buffer.reserve(_capacity);
}

void EventBus::Push(const Event& event)
{
    // We put the event at the tail
    _buffer[_tail] = event;
    // Increment the event tail
    _tail = (_tail + 1) % _capacity;
    // Check if buffer is full, need to resize
    if (_head == _tail)
    {
        _tail = _buffer.size();
        // Double the buffer size
        _capacity = _buffer.size() * 2;
        _buffer.resize(_capacity);
    }
}

std::optional<Event> EventBus::Pop()
{
    // Check if buffer is empty
    if (_head == _tail)
    {
        return std::nullopt;
    }

    // We get the event
    Event& event = _buffer[_head];
    // Move the head
    _head = (_head + 1) % _capacity;

    return event;
}

