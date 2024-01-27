#include "C05tester.hpp"

UnitTest getEx05test() {
	UnitTest test("ex05");
	test.addRequiredFile("ft_sqrt.c");
	test.addTemporaryMainFile(
		"int ft_sqrt(int nb);",
		"printf(\"%i\", ft_sqrt(atoi(argv[1])));"
	);
	test.addTestCase("-2", "0");
	test.addTestCase("-1", "0");
	test.addTestCase("0", "0");
	test.addTestCase("1", "1");
	test.addTestCase("2", "0");
	test.addTestCase("3", "0");
	test.addTestCase("4", "2");
	test.addTestCase("9", "3");
	test.addTestCase("42", "0");
	test.addTestCase("100000000", "10000");
	test.addTestCase("2147395600", "46340");
	test.addTestCase("2147483647", "0");
	test.addTestCase("-2147483648", "0");
	return test;
}