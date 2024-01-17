#include "C01tester.hpp"

UnitTest getEx02test() {
	UnitTest test("ex02");
	test.addRequiredFile("ft_swap.c");
	test.addTemporaryMainFile(
		"void ft_swap(int *a, int *b);",
		"int a = atoi(argv[1]);"
		"int b = atoi(argv[2]);"
		"ft_swap(&a, &b);"
		"printf(\"%i %i\", a, b);"
	);
	test.addTestCase("3 4", "4 3");
	test.addTestCase("0 0", "0 0");
	test.addTestCase("1 1", "1 1");
	test.addTestCase("-1 1", "1 -1");
	test.addTestCase("8 -7", "-7 8");
	test.addTestCase("420 69", "69 420");
	test.addTestCase("1234 5678", "5678 1234");
	test.addTestCase("-112321 52678", "52678 -112321");
	test.addTestCase("2147483647 -2147483648", "-2147483648 2147483647");
	return test;
}