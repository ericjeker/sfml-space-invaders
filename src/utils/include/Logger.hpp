#pragma once
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger
{
public:
	explicit Logger(std::string context = "", int level = 0);
	~Logger();

	enum LogLevel
	{
		Error = 0,
		Warning,
		Info,
		Debug
	};

	void error(const std::string& message) const;
	void warn(const std::string& message) const;
	void info(const std::string& message) const;
	void debug(const std::string& message) const;

private:
	const std::string _context;
	const int		  _level;

private:
	void log(const std::string& message, LogLevel level) const;
};

#endif