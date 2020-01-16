#include <iostream>

#include "Base64.h"
#include "File.h"

int main() {
	const char* fileContent = "aaaaaaaaaaaaa";
	long fileSize = 14;
	File file("/tmp/log", fileContent, fileSize);
	return 0;
}