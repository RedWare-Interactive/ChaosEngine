#include <ChaosEngine/engine.hpp>

int main(int argc, char *argv[]) {
	Engine ch(argc, argv);

	while (ch.run()) {
		ch.log("Delta time: " + to_string(ch.deltaTime));
	}

	return ch.code;
}
