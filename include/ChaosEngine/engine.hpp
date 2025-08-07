#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <string>

using namespace std;

class Engine {
public:
	Engine();
	~Engine();
	void log(string msg);
	void err(string msg, int exitCode=0);
};

#endif // ENGINE_HPP
