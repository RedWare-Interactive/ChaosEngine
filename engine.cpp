#include <ChaosEngine/engine.hpp>
#include "ChaosInfo.hpp"
#include <thread>

Engine::Engine(int argc, char *argv[], string gameName, int gameWidth, int gameHeight) {
	log("Starting ChaosEngine version: " + string(CHAOS_VERSION));
	game = gameName;
	width = gameWidth;
	height = gameHeight;

	string args;
	for (int i = 1; i < argc; i++) {
		args += " ";
		args += argv[i];
	}

	log("Command line:" + args);
	log("Game: " + game);
	log("Resolution: " + to_string(width) + "x" + to_string(height));

	log("Connecting to X11.");
	cnn = xcb_connect(NULL, NULL);

	// Get screen data
	const xcb_setup_t * setup = xcb_get_setup(cnn);
	xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);
	scrn = iter.data;

	log("Creating window.");
	win = xcb_generate_id(cnn);
	xcb_create_window(cnn, XCB_COPY_FROM_PARENT, win, scrn->root, 0, 0, width, height, 10, XCB_WINDOW_CLASS_INPUT_OUTPUT, scrn->root_visual, 0, NULL);

	log("Showing window.");
	xcb_map_window(cnn, win);
	xcb_flush(cnn);

	lastFrameTime = steady_clock::now();
}

Engine::~Engine() {
	log("Disconnecting from X11");
	xcb_disconnect(cnn);

	log("Stopping ChaosEngine with exit code: " + to_string(code));
}

void Engine::close(int exitCode) {
	code = exitCode;
	running = false;
}

void Engine::limitFPS() {
	//double idealFrameDuration = 1 / fpsLimit;

	duration<double> frameDuration = steady_clock::now() - lastFrameTime;
	deltaTime = frameDuration.count();
	double timeToSleep = (1 / fpsLimit) - deltaTime;

	if (timeToSleep > 0) {
		auto sleepDuration = duration<double>(timeToSleep);
		std::this_thread::sleep_for(duration_cast<nanoseconds>(sleepDuration));

		auto afterSleep = steady_clock::now();
		duration<double> realFrameDuration = afterSleep - lastFrameTime;
		deltaTime = realFrameDuration.count();
	}

	lastFrameTime = steady_clock::now();
}

bool Engine::run() {
	limitFPS();

	return running;
}
