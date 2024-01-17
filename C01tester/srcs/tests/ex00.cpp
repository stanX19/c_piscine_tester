#include "C01tester.hpp"

UnitTest getEx00test() {
	UnitTest test("ex00");
	test.addRequiredFile("ft_ft.c");
	test.addTemporaryMainFile(
		"void ft_ft(int *c);",
		"int n = atoi(argv[1]);"
		"ft_ft(&n);"
		"printf(\"%i\", n);"
	);
	for (char c = '0'; c <= '9'; c++)
		test.addTestCase(std::string(1, c), "42");
	return test;
}