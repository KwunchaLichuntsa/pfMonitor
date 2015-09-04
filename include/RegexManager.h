/**
 * @file RegexManager.h
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @version concept
 * @brief 
 */

#ifndef REGEXMANAGER_H
#define REGEXMANAGER_H

#include <string>

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
class RegexManager
{
	private:
	protected:
	public:
		RegexManager();
		virtual ~RegexManager();
		std::string fileDataFilter(std::string line, int fileType);//, int fileType)
		std::string lineWhitespaceStripper(std::string line);
		bool lineDataSpliter(std::string &line, std::string &delimeter);
};

#endif // REGEXMANAGER_H
