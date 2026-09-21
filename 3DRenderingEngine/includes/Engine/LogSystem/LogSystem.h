#pragma once

#include <string>

class LogSystem
{
public :
	LogSystem() = default;
	~LogSystem() = default;

	void Log(std::string logMessage);
	void LogWarning(std::string logMessage);
	void LogError(std::string logMessage);
};