#include "ChaosEngine/engine.hpp"

void Engine::log(string msg) {
	time(&currentTime);
	struct tm *t = localtime(&currentTime);
	char buff[25];

	strftime(buff, sizeof(buff), "[%d/%m/%Y %H:%M:%S]: ", t);

	string logMsg = buff + msg + "\n";

	printf(logMsg.c_str());
	fprintf(logFile, logMsg.c_str());
}
