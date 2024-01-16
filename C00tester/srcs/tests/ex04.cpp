#include "C00tester.hpp"

UnitTest getEx04test() {
	std::string name = "ft_is_negative";
	UnitTest test("ex04");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(int n);",
		name + "(atoi(argv[1]));"
	);
	for (int i = 0; i < 10; i++)
		test.addTestCase(std::to_string(i), "P");
	for (int i = -1; i > 10; i--)
		test.addTestCase(std::to_string(i), "N");
	test.addTestCase("2147483647", "P");
	test.addTestCase("-2147483648", "N");
	return test;
}