#include <ChaosEngine/engine.hpp>

Engine::Engine(string gameName, int gameWidth, int gameHeight) {
	log("Starting ChaosEngine.");
	game = gameName;
	width = gameWidth;
	height = gameHeight;

	log("Game: " + game);
	log("Resolution: " + to_string(width) + "x" + to_string(height));
}

Engine::~Engine() {
	log("Stoping ChaosEngine.");
}
