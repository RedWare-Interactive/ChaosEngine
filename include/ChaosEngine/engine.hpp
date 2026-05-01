#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>

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
	void startLog();
	void stopLog();
};

#endif // ENGINE_HPP
