#include "C04tester.hpp"

UnitTest getEx01test() {
	std::string name = "ft_putstr";
	UnitTest test("ex01");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(char* str);",
		name + "(argv[1]);"
	);
	test.addTestCase("\"Hello world!\"", "Hello world!");
	test.addTestCase("123456", "123456");
	test.addTestCase("\"\"", "");
	test.addTestCase("\"\n\n\n\"", "\n\n\n");
	test.addTestCase("\"\t\b\r\"", "\t\b\r");
	test.addTestCase("\"\\`~!@#\\$%^&*()\"", "`~!@#$%^&*()");
	return test;
}