#include "C01tester.hpp"

std::string ft_strlen(std::string str) {
	return std::to_string(str.length());
}

UnitTest getEx06test() {
	std::string name = "ft_strlen";
	UnitTest test("ex06");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"int " + name + "(char *str);",
		"printf(\"%i\", " + name + "(argv[1]));"
	);
	test.addTestCase("\"Hello world!\"", ft_strlen("Hello world!"));
	test.addTestCase("123456", ft_strlen("123456"));
	test.addTestCase("\"\"", ft_strlen(""));
	test.addTestCase("\"\n\n\n\"", ft_strlen("\n\n\n"));
	test.addTestCase("\"\t\b\r\"", ft_strlen("\t\b\r"));
	test.addTestCase("\"\\`~!@#\\$%^&*()\"", ft_strlen("`~!@#$%^&*()"));
	test.addTestCase(std::string(42, '-'), "42");
	test.addTestCase(std::string(100, '-'), "100");
	return test;
}