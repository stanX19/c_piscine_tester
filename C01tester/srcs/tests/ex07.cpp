#include "C01tester.hpp"

UnitTest getEx07test() {
	std::string name = "ft_putnbr";
	UnitTest test("ex07");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(int i);",
		name + "(atoi(argv[1]));"
	);
	for (int i = -10; i <= 10; i++)
		test.addTestCase(std::to_string(i), std::to_string(i));
	test.addTestCase("123456", "123456");
	test.addTestCase("-114514", "-114514");
	test.addTestCase("-2147483648", "-2147483648");
	test.addTestCase("2147483647", "2147483647");

	return test;
}