#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <string>
#include <xcb/xcb.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Engine {
public:
	Engine(int argc, char *argv[], string gameName="Default game", int gameWidth=800, int gameHeight=600);
	~Engine();
	void log(string msg);
	void err(string msg, int exitCode=0);
	string game;
	int width;
	int height;
	int code = 0;
	double fpsLimit = 60;
	double deltaTime = 0;
	bool running = true;
	void limitFPS();
	void close(int exitCode=0);
	bool run();
private:
	xcb_connection_t *cnn;
	xcb_screen_t *scrn;
	xcb_window_t win;
	steady_clock::time_point lastFrameTime;
};

#endif // ENGINE_HPP
