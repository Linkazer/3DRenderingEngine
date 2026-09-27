#pragma once

#include <string>

class LogSystem
{
public :
	LogSystem() = default;
	~LogSystem() = default;

	bool Initialize();
	void Clean();

	static void Log(std::string logMessage);
	static void LogWarning(std::string logMessage);
	static void LogError(std::string logMessage);
};