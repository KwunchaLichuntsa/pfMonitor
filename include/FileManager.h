/**
 * @file FileManager.h
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @version concept
 * @brief 
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
class FileManager
{
	public:
		FileManager();
		virtual ~FileManager();
		void fileProcessor(std::string path, std::string fileName, std::vector<std::string> &v);
		void fileReader(std::string file);
		void getFileNames(std::string path);
		void fileDataFilter(std::string line);

	protected:

	private:
		std::vector<std::string> m_pFileDataList;
		std::vector<std::string> m_pFileNameList;
		std::string m_pFileData;
		int m_pFileType;
};
#endif // FILEMANAGER_H
