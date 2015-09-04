/**
 * @file ConfigurationManager.cpp
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @brief 
 */
  
#include "ConfigurationManager.h"
#include "FileManager.h"
#include "RegexManager.h"
#include "LogManager.h"
#include <iostream>

//ConfigurationManager& gConfigurationManager = ConfigurationManager::sGetInstance();
ConfigurationManager::ConfigurationManager() : configuration() {}
ConfigurationManager::~ConfigurationManager() {}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
void ConfigurationManager::SelfConfiguration()
{
	std::string path = "";
	std::string file = "";
	bool match = false;
	std::vector<std::string> delimeters;
	FileManager FileMgmr;
	RegexManager reMgmr;
	try
	{
		for(uint i = 0; i <= static_cast<int>(eCfgVariables::SLEEPTIMER); ++i)
		{
			delimeters.push_back(GetConfigurationMapping(static_cast<eCfgVariables>(i)));
			//gLogManager::sGetInstance().log(gLogManager::sGetInstance().eLogLevel::INFO, delimeters[i]);
		}
		SetConfigurationValue(eCfgVariables::DIRCFG, GetConfigurationMapping(eCfgVariables::DIRCFG));
		SetConfigurationValue(eCfgVariables::FILEPFCFG, GetConfigurationMapping(eCfgVariables::FILEPFCFG));
		SetConfigurationValue(eCfgVariables::FILERULEDEF, GetConfigurationMapping(eCfgVariables::FILERULEDEF));
		path = GetConfigurationValue(eCfgVariables::DIRCFG);
		file = GetConfigurationValue(eCfgVariables::FILEPFCFG);
		FileMgmr.fileProcessor(path, file, this->cfgData);
		for(uint i = 0; i < this->cfgData.size(); i++)
		{
			for(uint j = 0; j < delimeters.size(); j++)
			{
				match = reMgmr.lineDataSpliter(this->cfgData[i], delimeters[j]);
				if(match == true)
				{
					SetConfigurationValue(static_cast<eCfgVariables>(i), this->cfgData[i]);
					//gLogManager::sGetInstance().log(gLogManager::sGetInstance().eLogLevel::INFO, configuration[static_cast<eCfgVariables>(i)]);
					break;
				}
			}
		}
	}
	catch(int e)
	{
		gLogManager::sGetInstance().log(LogManager::eLogLevel::ERROR, "An exception occured: " + e);
	}
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param enumID
 * @param cfgValue
 */
void ConfigurationManager::SetConfigurationValue(eCfgVariables enumID, std::string cfgValue)
{
	configuration[enumID] = cfgValue;
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param enumID
 * @return 
 */
std::string ConfigurationManager::GetConfigurationValue(eCfgVariables enumID)
{
	std::map<eCfgVariables, std::string>::iterator  it;
	std::string enumValue = "";
	for(it = configuration.begin(); it != configuration.end(); ++it)
	{
		if(it->first == enumID)
		{
			enumValue = it->second;
			break;
		}
	}
	return enumValue;
}

/**
 //////////////////////////////////////////////////////////////////
 // @brief
 //////////////////////////////////////////////////////////////////
 * @param path
 * @return
 */
int ConfigurationManager::GetFileType(std::string path)
{
	int type = 0;

	if(path == GetConfigurationValue(eCfgVariables::DIRACTIONS))
	{
		type = 2;
	}
	else if(path == GetConfigurationValue(eCfgVariables::DIRCFG))
	{
		type = 3;
	}
	else if(path == GetConfigurationValue(eCfgVariables::DIRFWLOG))
	{
		type = 4;
	}
	else if(path == GetConfigurationValue(eCfgVariables::DIRRULES))
	{
		type = 6;
	}
	return type;
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param cfgID
 * @return 
 */
std::string ConfigurationManager::GetConfigurationMapping(eCfgVariables cfgID)
{
	std::string mapValue = "";
	switch(cfgID)
	{
		case eCfgVariables::ADDRFROM:
			mapValue = "fromaddr=";
			break;
		case eCfgVariables::ADDRTO:
			mapValue = "toaddr=";
			break;
		case eCfgVariables::DIRACTIONS:
			mapValue = "actionDir=";
			break;
		case eCfgVariables::DIRFWLOG:
			mapValue = "firewallLogDir=";
			break;
		case eCfgVariables::DIRMONLOG:
			mapValue = "pfMonitorLogDir=";
			break;
		case eCfgVariables::DIRRULES:
			mapValue = "ruleDir=";
			break;
		case eCfgVariables::SCANINTERVAL:
			mapValue = "interval=";
			break;
		case eCfgVariables::SLEEPTIMER:
			mapValue = "sleeptimer=";
			break;
		case eCfgVariables::DIRCFG:
			mapValue = "T:\\Git\\pfMonitor\\cfg"; //Linux/Unix!!!!!!
			break;
		case eCfgVariables::FILEPFCFG:
			mapValue = "pfmonitor.cfg";
			break;
		case eCfgVariables::FILERULEDEF:
			mapValue = "ruledefinition.cfg";
			break;
	}
	return mapValue;
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
void ConfigurationManager::vStartUp()
{
	gLogManager::sGetInstance().log(LogManager::eLogLevel::NOTIFICATION, "...Starting up Configuration Manager...");
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
void ConfigurationManager::vShutDown()
{
	gLogManager::sGetInstance().log(LogManager::eLogLevel::NOTIFICATION, "...Shutting down & cleaning Configuration Manager...");
}
