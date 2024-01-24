#include "C04tester.hpp"

UnitTest getEx03test() {
	std::string name = "ft_atoi";
	UnitTest test("ex03");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"int " + name + "(char *str);",
		"printf(\"%i\", " + name + "(argv[1]));"
	);
	for (int i = -10; i <= 10; i++)
		test.addTestCase(std::to_string(i), std::to_string(i));
	test.addTestCase("123456", "123456");
	test.addTestCase("-114514", "-114514");
	test.addTestCase("-2147483648", "-2147483648");
	test.addTestCase("2147483647", "2147483647");

	return test;
}