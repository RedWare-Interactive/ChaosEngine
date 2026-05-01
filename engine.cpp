#include "ChaosEngine/engine.hpp"

Engine::Engine(int argc, char *argv[], string gameTitle, string gameDev, int gameWidth, int gameHeight) {
	developer = gameDev;
        title = gameTitle;

	startLog();

	log("Starting ChaosEngine.");

	width = gameWidth;
	height = gameHeight;
	string args;
	for (int i = 1; i < argc; i++) {
		args += " ";
		args += argv[i];
	}

	log("Game developer: " + developer);
	log("Game title: " + title);
	log("Resolution: " + to_string(width) + "x" + to_string(height));
	log("Data directory: " + dataDir);
	log("Command line:" + args);
}

Engine::~Engine() {
	log("Stopping ChaosEngine with exit code " + to_string(exitCode));
	stopLog();
}
