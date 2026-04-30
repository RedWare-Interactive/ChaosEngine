#include "ChaosEngine/engine.hpp"
#include <unistd.h>
#include <sys/stat.h>

Engine::Engine(int argc, char *argv[], string gameTitle, string gameDev, int gameWidth, int gameHeight) {
	developer = gameDev;
        title = gameTitle;

	if (getenv("HOME")) {
		dataDir = string(getenv("HOME")) + "/.local";
		mkdir(dataDir.c_str(), 0755);

		dataDir += "/share";
		mkdir(dataDir.c_str(), 0755);

		dataDir += "/" + developer;
		mkdir(dataDir.c_str(), 0755);

		dataDir += "/" + title + "/";
		mkdir(dataDir.c_str(), 0755);

	}

	string logFileName = dataDir + "latest.log";


	if (access(logFileName.c_str(), F_OK) == 0) {
		struct stat t_stat;
		stat(logFileName.c_str(), &t_stat);

		struct tm *t = localtime(&t_stat.st_ctime);

		char timeLog[11];
		char timeNow[11];

		strftime(timeLog, sizeof(timeLog), "%d-%m-%Y", t);

		time(&currentTime);
		t = localtime(&currentTime);

		strftime(timeNow, sizeof(timeNow), "%d-%m-%Y", t);

		if (string(timeLog) != string(timeNow)) {
			string oldLogFileName = string(timeLog) + ".log";
			rename(logFileName.c_str(), oldLogFileName.c_str());
		}
	}

	logFile = fopen(logFileName.c_str(), "a");
	log("Starting ChaosEngine");

	width = gameWidth;
	height = gameHeight;
	string args;
	for (int i = 1; i < argc; i++) {
		args += " ";
		args += argv[i];
	}

	log("Game developer: " + developer);
	log("Game title: " + title);
	log("Resolution: " + to_string(width) + "x" + to_string(height));
	log("Data directory: " + dataDir);
	log("Command line:" + args);
}

Engine::~Engine() {
	log("Stopping ChaosEngine with exit code " + to_string(exitCode) + "\n");
	fclose(logFile);
}
