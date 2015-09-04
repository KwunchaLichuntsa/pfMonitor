/**
 * @file RegexManager.cpp
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @brief 
 */
 
#include "RegexManager.h"
#include "FileManager.h"
#include "ConfigurationManager.h"
#include <regex>
#include <iostream>
RegexManager::RegexManager(){}
RegexManager::~RegexManager(){}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param line
 * @param fileType
 * @return 
 */
std::string RegexManager::fileDataFilter(std::string line, int fileType)
{
	std::string expression = "";
	std::smatch match;
	std::string lineMatch = "";

	switch(fileType)
	{
		case 2:
			expression = ".+ = .*";
			break;
		case 3:
			expression = ".+ = .*";
			break;
		case 4:
			expression = ".+ = .*";
			break;
		case 6:
			expression = ".+ = .*";
			break;
	}
	std::regex r(expression);
	if(std::regex_search(line, match, r))
	{
		lineMatch = lineWhitespaceStripper(line);
	}
	return lineMatch;
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param line
 * @return 
 */
std::string RegexManager::lineWhitespaceStripper(std::string line)
{
	line.erase(remove(line.begin(), line.end(), ' '), line.end());
	return line;
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param line
 * @param delimeter
 * @return 
 */
bool RegexManager::lineDataSpliter(std::string &line, std::string &delimeter)
{
	bool match = false;
	std::size_t pos = 0;
	pos = line.find(delimeter);
	match = (pos != std::string::npos);
	if(match == true)
	{
		line.substr(0, pos);
		line.erase(0, pos + delimeter.length());
	}
	return match;
}
