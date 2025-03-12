// Copyright (c) Eric Jeker. All Rights Reserved.

#include "Logger.h"

#include <iostream>
#include <ostream>
#include <utility>

Logger::Logger(std::string context, const int level)
    : _Context(std::move(context)), _Level(level)
{
}

Logger::~Logger() = default;

void Logger::Error(const std::string& message) const
{
    Log(message, LogLevel::Error);
}

void Logger::Warn(const std::string& message) const
{
    Log(message, LogLevel::Warning);
}

void Logger::Info(const std::string& message) const
{
    Log(message, LogLevel::Info);
}

void Logger::Debug(const std::string& message) const
{
    Log(message, LogLevel::Debug);
}

void Logger::Log(const std::string& message, LogLevel level) const
{
    /** If the requested level is higher than the current level, do not log the message. */
    if (level > _Level)
    {
        return;
    }

    switch (level)
    {
    case LogLevel::Info:
        std::cout << "[INFO]: (" << _Context << ") " << message << std::endl;
        break;
    case LogLevel::Warning:
        std::cout << "[WARNING]: (" << _Context << ") " << message << std::endl;
        break;
    case LogLevel::Error:
        std::cout << "[ERROR]: (" << _Context << ") " << message << std::endl;
        break;
    case LogLevel::Debug:
        std::cout << "[DEBUG]: (" << _Context << ") " << message << std::endl;
        break;
    }
}
