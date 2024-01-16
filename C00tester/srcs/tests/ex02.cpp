#include "C00tester.hpp"

UnitTest getEx02test() {
	UnitTest test("ex02");
	test.addRequiredFile("ft_print_reverse_alphabet.c");
	test.addTemporaryMainFile(
		"void ft_print_reverse_alphabet(void);",
		"ft_print_reverse_alphabet()"
	);
	test.addTestCase("None", "zyxwvutsrqponmlkjihgfedcba");
	return test;
}