#include <iostream>
#include <ostream>
#include <utility>

#include "Logger.hpp"

Logger::Logger(std::string context, const int level)
	: _context(std::move(context)), _level(level) {}

Logger::~Logger() = default;

void Logger::error(const std::string& message) const
{
	log(message, Error);
}

void Logger::warn(const std::string& message) const
{
	log(message, Warning);
}

void Logger::info(const std::string& message) const
{
	log(message, Info);
}

void Logger::debug(const std::string& message) const
{
	log(message, Debug);
}

void Logger::log(const std::string& message, LogLevel level) const
{
	if (level > _level)
	{
		return;
	}

	switch (level)
	{
		case Info:
			std::cout << "[INFO]: (" << _context << ") " << message << std::endl;
			break;
		case Warning:
			std::cout << "[WARNING]: (" << _context << ") " << message << std::endl;
			break;
		case Error:
			std::cout << "[ERROR]: (" << _context << ") " << message << std::endl;
			break;
		case Debug:
			std::cout << "[DEBUG]: (" << _context << ") " << message << std::endl;
			break;
	}
}
