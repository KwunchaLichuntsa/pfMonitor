/**
 * @file LogManager.h
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @version concept
 * @brief 
 */

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "Singleton.h"
#include <vector>
#include <string>

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
class LogManager : public Singleton<LogManager>, IManager
{
		friend class Singleton<LogManager>;

	private:
		LogManager();
		virtual ~LogManager();

	protected:
		
	public:
		enum class eLogLevel
		{
			DEBUG = 0,
			INFO,
			NOTIFICATION,
			WARNING,
			ERROR,
			CRITICAL
		};
		void log(const eLogLevel& level, const std::string& message);
		void log(const eLogLevel& level, const std::vector<std::string>& message);
		void logHelper(const eLogLevel& level, const std::string& message);
		void vStartUp() override;
		void vShutDown() override;
		
};
typedef Singleton<LogManager> gLogManager;
#endif // LOGMANAGER_H
