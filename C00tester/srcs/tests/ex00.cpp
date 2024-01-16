#include "C00tester.hpp"

UnitTest getEx00test() {
	UnitTest test("ex00");
	test.addRequiredFile("ft_putchar.c");
	test.addTemporaryMainFile(
		"void ft_putchar(char c);",
		"ft_putchar(argv[1][0]);"
	);
	for (char c = '0'; c <= '9'; c++)
		test.addTestCase(std::string(1, c), std::string(1, c));
	for (char c = 'a'; c <= 'z'; c++)
		test.addTestCase(std::string(1, c), std::string(1, c));
	for (char c = 'A'; c <= 'Z'; c++)
		test.addTestCase(std::string(1, c), std::string(1, c));
	return test;
}