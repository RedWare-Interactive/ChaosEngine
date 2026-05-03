#include "ChaosEngine/engine.hpp"
#include <unistd.h>
#include <time.h>

time_t currentTime;
struct tm *t;

FILE *logFile;

void Engine::startLog() {
	if (getenv("HOME")) {
		dataDir = string(getenv("HOME")) + "/.local/share/" + developer + "/" + title + "/";
		fsmkdir(dataDir.c_str());
	}

	string logFileName = dataDir + "latest.log";

	if (access(logFileName.c_str(), F_OK) == 0) {
		struct stat t_stat;
		stat(logFileName.c_str(), &t_stat);

		t = localtime(&t_stat.st_ctime);

		char timeLog[11];
		char timeNow[11];

		strftime(timeLog, sizeof(timeLog), "%d-%m-%Y", t);

		time(&currentTime);
		t = localtime(&currentTime);

		strftime(timeNow, sizeof(timeNow), "%d-%m-%Y", t);

		if (string(timeLog) != string(timeNow)) {
			string oldLogFileName = dataDir + string(timeLog) + ".log";
			rename(logFileName.c_str(), oldLogFileName.c_str());
		}
	}

	logFile = fopen(logFileName.c_str(), "a");
}

void Engine::stopLog() {
	fprintf(logFile, "|--- End of log ---|\n");
	fclose(logFile);
}

void Engine::log(string msg) {
	time(&currentTime);
	t = localtime(&currentTime);
	char timeMsg[25];

	strftime(timeMsg, sizeof(timeMsg), "[%d/%m/%Y %H:%M:%S]: ", t);

	string logMsg = string(timeMsg) + msg;

	printf("%s\n", logMsg.c_str());

	if (logFile) {
		fprintf(logFile, "%s\n", logMsg.c_str());
	}
}
