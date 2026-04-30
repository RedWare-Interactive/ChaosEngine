#include "ChaosEngine/engine.hpp"
#include <unistd.h>
#include <sys/stat.h>

Engine::Engine(int argc, char *argv[], string gameTitle, int gameWidth, int gameHeight) {
	const char *logFileName = "latest.log";

	if (access(logFileName, F_OK) == 0) {
		struct stat t_stat;
		stat(logFileName, &t_stat);

		struct tm *t = localtime(&t_stat.st_ctime);

		char timeLog[11];
		char timeNow[11];

		strftime(timeLog, sizeof(timeLog), "%d-%m-%Y", t);

		time(&currentTime);
		t = localtime(&currentTime);

		strftime(timeNow, sizeof(timeNow), "%d-%m-%Y", t);

		log(string(timeLog) + " " + string(timeNow));
		if (string(timeLog) != string(timeNow)) {
			string oldLogFileName = string(timeLog) + ".log";
			rename(logFileName, oldLogFileName.c_str());
		}
	}

	logFile = fopen(logFileName, "a");
	log("Starting ChaosEngine");

	title = gameTitle;
	width = gameWidth;
	height = gameHeight;
	string args;
	for (int i = 1; i < argc; i++) {
		args += " ";
		args += argv[i];
	}

	log("Game title: " + title);
	log("Resolution: " + to_string(width) + "x" + to_string(height));
	log("Command line:" + args);
}

Engine::~Engine() {
	log("Stopping ChaosEngine with exit code " + to_string(exitCode) + "\n");
	fclose(logFile);
}
