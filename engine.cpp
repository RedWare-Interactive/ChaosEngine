#include "ChaosEngine/engine.hpp"

Engine::Engine(int argc, char *argv[], string gameTitle, int gameWidth, int gameHeight) {
	logFile = fopen("log.txt", "a");
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
