// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <string>

enum LogLevel
{
    Error = 0,
    Warning,
    Info,
    Debug
};

/**
 * Logger is a utility made for easy logging of messages in the game.
 * It can log messages at different levels such as Error, Warning, Info, and Debug.
 * It can be used in any part of the game to log messages.
 */
class Logger
{
public:
    /* By default, the logger will log messages at the Error level. */
    explicit Logger(std::string context = "", int level = LogLevel::Error);
    ~Logger();

    void Error(const std::string& message) const;
    void Warn(const std::string& message) const;
    void Info(const std::string& message) const;
    void Debug(const std::string& message) const;

private:
    const std::string _Context;
    const int _Level;

private:
    void Log(const std::string& message, LogLevel level) const;
};

#endif
