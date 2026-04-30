#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>
#include <time.h>

using namespace std;

class Engine {
public:
	Engine(int argc, char *argv[], string gameTitle="ChaosEngine", string gameDev="RedWare Interactive", int gameWidth=800, int gameHeight=600);
	~Engine();
	void log(string msg);
	string title;
	string developer;
	string dataDir;
	int exitCode = 0;
	int width;
	int height;
private:
	time_t currentTime;
	FILE *logFile;
};

#endif // ENGINE_HPP
