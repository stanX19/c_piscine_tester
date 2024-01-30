#include "C07tester.hpp"

int main(int argc, char **argv) {
	if (!UnitTestconfig::parseArgv(argc, argv))
		return 1;
	std::vector<std::function<void(UnitTest&)>> set_tests = {
		setEx00test,
		setEx01test,
		setEx02test,
		setEx03test,
		setEx04test,
		setEx05test,
	};
	std::cout << "===========C07 Tester==========\n";
	for (std::function<void(UnitTest&)> set_test : set_tests) {
		UnitTest test;
		set_test(test);
		test.run();
	}
}
