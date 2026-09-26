#include <Engine\LogSystem\LogSystem.h>

#include <iostream>

bool LogSystem::Initialize()
{
	return true;
}

void LogSystem::Clean()
{}

void LogSystem::Log(std::string logMessage)
{
	std::cout << "LOG : " << logMessage << std::endl;
}

void LogSystem::LogWarning(std::string logMessage)
{
	std::cout << "WARNING : " << logMessage << std::endl;
}

void LogSystem::LogError(std::string logMessage)
{
	std::cout << "!! ERROR !! : " << logMessage << std::endl;
}
