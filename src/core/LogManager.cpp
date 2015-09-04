/**
 * @file LogManager.cpp
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @brief 
 */

#include "LogManager.h"
#include <iostream>

LogManager::LogManager(){}
LogManager::~LogManager(){}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param level
 * @param message
 */
void LogManager::log(const eLogLevel& level, const std::string& message)
{
	logHelper(level, message);
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param level
 * @param message
 */
void LogManager::log(const eLogLevel& level, const std::vector<std::string>& message)
{
	
	for(size_t i = 0; i < message.size(); i++)
	{
		logHelper(level, message[i]);
	}
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param level
 * @param message
 */
void LogManager::logHelper(const eLogLevel& level, const std::string& message)
{
	std::string levelMessage = "";
	switch(level)
	{
		case eLogLevel::CRITICAL:
			levelMessage = "CRTICAL";
			break;
		case eLogLevel::DEBUG:
			levelMessage = "DEBUG";
			break;
		case eLogLevel::ERROR:
			levelMessage = "ERROR";
			break;
		case eLogLevel::INFO:
			levelMessage = "INFORMATION";
			break;
		case eLogLevel::NOTIFICATION:
			levelMessage = "NOTIFICATION";
			break;
		case eLogLevel::WARNING:
			levelMessage = "WARNING";
			break;
		default: levelMessage = "ggghhuuuuuhhh?!";
	}
	std::cout << "[" << levelMessage << "]" << "-> " << message << std::endl;
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
void LogManager::vStartUp()
{
	log(eLogLevel::NOTIFICATION, "...Starting up Log Manager...");
	LogManager();
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
void LogManager::vShutDown()
{
	log(eLogLevel::NOTIFICATION, "...Shutting down & cleaning Log Manager...");
}
