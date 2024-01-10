#include "UnitTest.hpp"

UnitTest getEx00test() {
	UnitTest test("ex00");
	test.addRequiredFile("ft_putchar.c");
	test.addTemporaryMainFile(
		"void ft_putchar(char c);",
		"ft_putchar(argv[1][0]);"
	);
	test.addTestCase("a", "a");
	test.addTestCase("x", "x");
	test.addTestCase("c", "c");
	return test;
}

int main(int argc, char **argv) {
	if (!UnitTestconfig::parseArgv(argc, argv))
		return 1;
	std::vector<UnitTest> tests;

	tests.push_back(getEx00test());
	tests[0].run();
}
