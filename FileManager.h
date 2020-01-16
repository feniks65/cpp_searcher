#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "FileSearcher.h"

class FileManager {
	FileSender fileSender;
	std::vector<File> files;
	FileSearcher mFileSearcher;

	int getFileSize(std::string filePath) {
		return 6000000; //TODO read proper file size
	}

	char * readAllBytes(const char * filename, int * read)
	{
		ifstream ifs(filename, ios::binary|ios::ate);
		ifstream::pos_type pos = ifs.tellg();
		int length = pos;
		char *pChars = new char[length];
		ifs.seekg(0, ios::beg);
		ifs.read(pChars, length);
		ifs.close();
		*read = length;
		return pChars;
	}

	char* readFileFromPath(std::string filePath, long *size) {
		char *content = readAllBytes(filePath.c_str(), size);
		return content;
	}

	void processFileList() {
		while(true) {
			std::vector<std::string> fileList = mFileSearcher.getFiles();
			for(auto filePath : fileList) {
				long fileSize;
				char* content = readFileFromPath(filePath, fileSize);
				File file(filePath, content, fileSize);
				FileSender fileSender(file);
			}
		}
	}
public:
	FileManager(FileSearcher &fileSearcher) {
		mFileSearcher = fileSearcher;
		std::thread processFiles(processFileList);
	}

};

#endif