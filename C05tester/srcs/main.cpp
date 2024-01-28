#include "C05tester.hpp"

int main(int argc, char **argv) {
	if (!UnitTestconfig::parseArgv(argc, argv))
		return 1;
	std::vector<UnitTest> tests {
		getEx00test(),
		getEx01test(),
		getEx02test(),
		getEx03test(),
		getEx04test(),
		getEx05test(),
		getEx06test(),
		getEx07test(),
	};
	std::cout << "===========C05 Tester==========\n";
	for (auto &test : tests) {
		test.run();
	}
}
