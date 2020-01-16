#ifndef FILESEARCHER_H
#define FILESEARCHER_H

#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

class FileSearcher {
	std::vector<std::string> interestingFileTypes = {".gif"};
	std::vector<std::string> filePaths;
	static std::mutex glock;

	void addNewFile(std::string filePath) {
		filePaths.push_back(filePath);
	}

	static void searchForInterestingFiles(FileSearcher &objRef) {
		while(true) {
			//TODO search paths code
			glock.lock();
			objRef.addNewFile("/tmp/properties1.yaml");
			objRef.addNewFile("/tmp/properties2.yaml");
			glock.unlock();

			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}

public:
	FileSearcher() {
		std::thread searchingThread(searchForInterestingFiles, this);
	}

	std::vector<std::string> getFiles() {
		std::vector<std::string> tmpFilePaths;
		glock.lock();
		tmpFilePaths = filePaths;
		glock.unlock();
		return tmpFilePaths;
	}
};

#endif
