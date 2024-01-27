#include "C05tester.hpp"

UnitTest getEx06test() {
	UnitTest test("ex06", 10);
	test.addRequiredFile("ft_is_prime.c");
	test.addTemporaryMainFile(
		"int ft_is_prime(int nb);",
		"printf(\"%i\", ft_is_prime(atoi(argv[1])));"
	);
	test.addTestCase("-2", "0");
	test.addTestCase("-1", "0");
	test.addTestCase("0", "0");
	test.addTestCase("1", "0");
	test.addTestCase("2", "1");
	test.addTestCase("3", "1");
	test.addTestCase("4", "0");
	test.addTestCase("5", "1");
	test.addTestCase("6", "0");
	test.addTestCase("7", "1");
	test.addTestCase("8", "0");
	test.addTestCase("9", "0");
	test.addTestCase("42", "0");
	test.addTestCase("10000", "0");
	test.addTestCase("524287", "1");
	test.addTestCase("2147302921", "0");
	test.addTestCase("2147483629", "1");
	test.addTestCase("2147483646", "0");
	test.addTestCase("2147483647", "1");
	test.addTestCase("-2147483648", "0");
	return test;
}