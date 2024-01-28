#include "C05tester.hpp"

UnitTest getEx07test() {
	UnitTest test("ex07", 10);
	test.addRequiredFile("ft_find_next_prime.c");
	test.addTemporaryMainFile(
		"int ft_find_next_prime(int nb);",
		"printf(\"%i\", ft_find_next_prime(atoi(argv[1])));"
	);
	test.addTestCase("-2", "2");
	test.addTestCase("-1", "2");
	test.addTestCase("0", "2");
	test.addTestCase("1", "2");
	test.addTestCase("2", "2");
	test.addTestCase("3", "3");
	test.addTestCase("4", "5");
	test.addTestCase("5", "5");
	test.addTestCase("6", "7");
	test.addTestCase("7", "7");
	test.addTestCase("8", "11");
	test.addTestCase("9", "11");
	test.addTestCase("42", "43");
	test.addTestCase("10000", "10007");
	test.addTestCase("524287", "524287");
	test.addTestCase("2147302921", "2147302961");
	test.addTestCase("2147483629", "2147483629");
	test.addTestCase("2147483646", "2147483647");
	test.addTestCase("2147483647", "2147483647");
	test.addTestCase("-2147483648", "2");
	return test;
}