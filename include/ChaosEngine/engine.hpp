#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>
#include <iostream>
#include <time.h>

using namespace std;

class Engine {
public:
	Engine(int argc, char *argv[], string gameTitle="ChaosEngine", int gameWidth=800, int gameHeight=600);
	~Engine();
	void log(string msg);
	string title;
	int exitCode = 0;
	int width;
	int height;
private:
	time_t currentTime;
	FILE *logFile;
};

#endif // ENGINE_HPP
