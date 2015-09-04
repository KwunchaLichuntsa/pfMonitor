/**
 * @file FileManager.cpp
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @brief 
 */
 
#include "FileManager.h"
#include "RegexManager.h"
#include "ConfigurationManager.h"
#include <iostream>
#include <fstream>
#include "dirent.h"

FileManager::FileManager() {} // : mFileDataList(0),
//m_pFileNameList(0),
//m_pFileData(0){}
//m_pFileType(0){}
FileManager::~FileManager() {}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param path
 * @param fileName
 * @param v
 */
void FileManager::fileProcessor(std::string path, std::string fileName, std::vector<std::string> &v)
{
	this->m_pFileType = ConfigurationManager::sGetInstance().GetFileType(path);
	if(fileName == "all")
	{
		gConfigurationManager::sGetInstance().GetFileType(path);
		//for()
		//{

		//}
	}
	else if(fileName != "all")
	{
		std::string file = path + "\\" + fileName;
		fileReader(file);
	}
	for(unsigned int index = 0; index < this->m_pFileDataList.size(); index++)
	{
		v.push_back(this->m_pFileDataList[index]);
	}
	this->m_pFileDataList.clear();
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param file
 */
void FileManager::fileReader(std::string file)
{
	RegexManager reMgmr;
	std::ifstream inputFile;
	std::string line = "";
	try
	{
		inputFile.open(file, std::ios_base::in);
		if(inputFile.is_open())
		{
			while(std::getline(inputFile, line))
			{
				std::string filteredLine = "";
				filteredLine = reMgmr.fileDataFilter(line, this->m_pFileType);
				if(!filteredLine.empty())
				{
					this->m_pFileDataList.push_back(filteredLine);
				}
			}
		}
		else
		{
			std::cout << "Unable to open file." << std::endl;
		}
		//inputFile.seekg(0, std::ios::end);
		//this->tmpFileData.reserve(inputFile.tellg());
		//inputFile.seekg(0, std::ios::beg);
		//this->tmpFileData.assign((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	}
	catch(int e)
	{
		std::cout << "An exception occured: " << e << std::endl;
	}
	inputFile.close();
}

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 * @param path
 */
void FileManager::getFileNames(std::string path)
{
	DIR *dp = NULL;
	struct dirent *dirp;

	dp = opendir(path.c_str());
	while((dirp = readdir(dp)) != NULL)
	{
		this->m_pFileNameList.push_back(std::string(dirp->d_name));
	}
	closedir(dp);
}
