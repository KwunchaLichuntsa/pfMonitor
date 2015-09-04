/**
 * @file ConfigurationManager.h
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @version concept
 * @brief 
 */

#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include "Singleton.h"
#include <string>
#include <map>
#include <vector>

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
class ConfigurationManager : public Singleton<ConfigurationManager>, IManager
{
		friend class Singleton<ConfigurationManager>;

	private:
		ConfigurationManager();
		virtual ~ConfigurationManager();
		enum class eCfgVariables
		{
		    ADDRFROM = 0,
		    ADDRTO,
		    DIRACTIONS,
		    DIRFWLOG,
		    DIRMONLOG,
		    DIRRULES,
		    SCANINTERVAL,
		    SLEEPTIMER,
			DIRCFG,
			FILEPFCFG,
		    FILERULEDEF
		};
		std::map<eCfgVariables, std::string> configuration;
		std::vector<std::string> cfgData;

	protected:

	public:
		void SelfConfiguration();
		void SetConfigurationValue(eCfgVariables cfgID, std::string cfgValue);
		std::string GetConfigurationValue(eCfgVariables cfgID);
		std::string GetConfigurationMapping(eCfgVariables cfgID);
		int GetFileType(std::string path);
		void vStartUp() override;
		void vShutDown() override;
};
typedef Singleton<ConfigurationManager> gConfigurationManager;
//extern ConfigurationManager& gConfigurationManager;
#endif // CONFIGURATIONMANAGER_H
