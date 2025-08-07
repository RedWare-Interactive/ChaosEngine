#include <ChaosEngine/engine.hpp>

void Engine::err(string msg, int exitCode) {
        cerr << "[ERROR] " << msg << endl;
}
