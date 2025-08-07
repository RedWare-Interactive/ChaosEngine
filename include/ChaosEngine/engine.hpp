#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <string>

using namespace std;

class Engine {
public:
	Engine(string gameName="Default game", int gameWidth=800, int gameHeight=600);
	~Engine();
	void log(string msg);
	void err(string msg, int exitCode=0);
	string game;
	int width;
	int height;

};

#endif // ENGINE_HPP
