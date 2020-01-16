#ifndef FILE_H
#define FILE_H

class File {
	std::string fileName;
	std::string encodedContent;
	long fileSize;
	const char *fileBytes;

	std::ifstream::pos_type filesize(const char* filename)
	{
	    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	    return in.tellg(); 
	}

	void readFileContentBinary() {
		
	}

public:
	File(std::string fileName, const char *fileBytes, long fileSize) {
		this->fileName = fileName;
		this->fileSize = fileSize;
		this->encodedContent = Base64::base64_encode((unsigned const char*)fileBytes, fileSize);
		this->fileBytes = fileBytes;
	}

	std::string getEncodedContent() {
		return encodedContent;
	}

	std::string getFileName() {
		return fileName;
	}

	long getFileSize() {
		return fileSize;
	}

	~File() {
		delete fileBytes;
	}
};

#endif