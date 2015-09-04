/**
 * @file Monitor.cpp
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @brief 
 */

#include "Monitor.h"
#include "ConfigurationManager.h"
#include "LogManager.h"
#include <iostream>
//#include <memory>

Monitor::Monitor() {}
Monitor::~Monitor() {}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @return 
 */
int main()
{
	try
	{
		gConfigurationManager::sGetInstance().vStartUp();
		gLogManager::sGetInstance().vStartUp();
		
		gConfigurationManager::sGetInstance().SelfConfiguration();
		gLogManager::sGetInstance().log(LogManager::eLogLevel::INFO, "End of <main>.");
		
		gConfigurationManager::sGetInstance().vShutDown();
		gLogManager::sGetInstance().vShutDown();
		//ConfigurationManager * cfgMgmr = new ConfigurationManager;
		//cfgMgmr->SelfConfiguration();
		//std::unique_ptr<ConfigurationManager> cfgMgmr(new ConfigurationManager);
		//auto CfgMgmr = std::make_shared<ConfigurationManager>();
		//CfgMgmr->SetConfiguration();
	}
	catch(int e)
	{
		std::cerr << "an exception occured: " << e << std::endl;
	}
	return 0;
}
