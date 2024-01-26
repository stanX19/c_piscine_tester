#include "C05tester.hpp"

UnitTest getEx05test() {
	UnitTest test("ex05");
	test.addRequiredFile("ft_sqrt.c");
	test.addTemporaryMainFile(
		"int ft_sqrt(int nb);",
		"printf(\"%i\", ft_sqrt(atoi(argv[1])));"
	);
	test.addTestCase("1", "1");
	test.addTestCase("4", "2");
	return test;
}