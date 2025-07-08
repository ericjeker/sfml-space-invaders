// Copyright (c) Eric Jeker. All Rights Reserved.

#include "gtest/gtest.h"

// Set a high log level to ensure all logging functions are active for testing
#undef LOG_LEVEL
#define LOG_LEVEL 5

#include "Logger.h"

#include <iostream>
#include <sstream>

// A test fixture for the Logger tests that handles stream redirection.
class LoggerTest : public ::testing::Test
{
protected:
	std::stringstream _outBuffer;
	std::stringstream _errBuffer;

	std::streambuf* _originalCoutBuf{};
	std::streambuf* _originalCerrBuf{};

	void SetUp() override
	{
		// Redirect std::cout to our stringstream buffer
		_originalCoutBuf = std::cout.rdbuf();
		std::cout.rdbuf(_outBuffer.rdbuf());

		// Redirect std::cerr to our stringstream buffer
		_originalCerrBuf = std::cerr.rdbuf();
		std::cerr.rdbuf(_errBuffer.rdbuf());
	}

	void TearDown() override
	{
		// Restore original stream buffers
		std::cout.rdbuf(_originalCoutBuf);
		std::cerr.rdbuf(_originalCerrBuf);
	}
};

TEST_F(LoggerTest, FatalLogsToCerr)
{
	const std::string message = "This is a fatal message.";
	Logger::Fatal(message);
	EXPECT_EQ(_errBuffer.str(), "[FATAL]: " + message + "\n");
	EXPECT_TRUE(_outBuffer.str().empty());
}

TEST_F(LoggerTest, ErrorLogsToCerr)
{
	const std::string message = "This is an error message.";
	Logger::Error(message);
	EXPECT_EQ(_errBuffer.str(), "[ERROR]: " + message + "\n");
	EXPECT_TRUE(_outBuffer.str().empty());
}

TEST_F(LoggerTest, WarnLogsToCout)
{
	const std::string message = "This is a warning message.";
	Logger::Warn(message);
	EXPECT_EQ(_outBuffer.str(), "[WARN]:  " + message + "\n");
	EXPECT_TRUE(_errBuffer.str().empty());
}

TEST_F(LoggerTest, InfoLogsToCout)
{
	const std::string message = "This is an info message.";
	Logger::Info(message);
	EXPECT_EQ(_outBuffer.str(), "[INFO]:  " + message + "\n");
	EXPECT_TRUE(_errBuffer.str().empty());
}

TEST_F(LoggerTest, DebugLogsToCout)
{
	const std::string message = "This is a debug message.";
	Logger::Debug(message);
	EXPECT_EQ(_outBuffer.str(), "[DEBUG]: " + message + "\n");
	EXPECT_TRUE(_errBuffer.str().empty());
}

TEST_F(LoggerTest, TraceLogsToCout)
{
	const std::string message = "This is a trace message.";
	Logger::Trace(message);
	EXPECT_EQ(_outBuffer.str(), "[TRACE]: " + message + "\n");
	EXPECT_TRUE(_errBuffer.str().empty());
}