#include "ChaosEngine/engine.hpp"

void Engine::log(string msg) {
	time(&currentTime);
	struct tm *t = localtime(&currentTime);
	char timeMsg[25];

	strftime(timeMsg, sizeof(timeMsg), "[%d/%m/%Y %H:%M:%S]: ", t);

	string logMsg = string(timeMsg) + msg;

	printf("%s\n", logMsg.c_str());
	fprintf(logFile, "%s\n", logMsg.c_str());
}
