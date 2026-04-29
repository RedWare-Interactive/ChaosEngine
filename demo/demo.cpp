#include <ChaosEngine/engine.hpp>
#include <unistd.h>

int main(int argc, char *argv[]) {
        Engine ch(argc, argv, "Chaos Demo");
	sleep(1);
	return ch.exitCode;
}
