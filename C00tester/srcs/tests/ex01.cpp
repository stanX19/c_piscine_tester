#include "C00tester.hpp"

UnitTest getEx01test() {
	UnitTest test("ex01");
	test.addRequiredFile("ft_print_alphabet.c");
	test.addTemporaryMainFile(
		"void ft_print_alphabet(void);",
		"ft_print_alphabet()"
	);
	test.addTestCase("None", "abcdefghijklmnopqrstuvwxyz");
	return test;
}
