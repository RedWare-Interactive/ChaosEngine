#include <ChaosEngine/engine.hpp>
#include <cstring>

void Engine::fsmkdir(string directory, int mode) {
	string Directory = directory;
	string dir;

	int directoryLength = Directory.length();
	int dirLength;
	int i;

	char directoryArray[directoryLength];

	struct stat sb;

	memcpy(&directoryArray, Directory.c_str(), directoryLength + 2);

	if (directoryArray[directoryLength - 1] != '/') {
		directoryArray[directoryLength] = '/';
		directoryLength++;
	}

	for (i = 0; i < directoryLength; i++) {
		dir += directoryArray[i];
		dirLength = dir.length() - 1;

		if (directoryArray[dirLength] == '/' && stat(dir.c_str(), &sb) == -1) {
			log("Creating " + dir + " directory.");
			mkdir(dir.c_str(), mode);
		}
	}
}
