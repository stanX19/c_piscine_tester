#include "C02tester.hpp"

static std::string s0("\0", 1);

UnitTest getEx00test() {
	UnitTest test("ex00");
	test.addRequiredFile("ft_strcpy.c");
	test.addTemporaryMainFile(
		"void ft_strcpy(char *dst, char *src);",
		"char dst[90];"
		"memset(dst, '@', 90);"
		"ft_strcpy(dst, argv[1]);"
		"write(1, dst, strlen(argv[1]) + 1);"
	);
	test.addTestCase("\"Hello world!\"", "Hello world!" + s0);
	test.addTestCase("\"\"", s0);
	test.addTestCase("\"\n\n\n\"", "\n\n\n" + s0);
	test.addTestCase("\" \t\r\n\f\v\b\"", " \t\r\n\f\v\b" + s0);
	test.addTestCase("\"\\`~!@#\\$%^&*()\"", "`~!@#$%^&*()\0" + s0);
	for (size_t i = 3; i < 20; i++) {
		std::string str = utils::generateRandomString(i);
		test.addTestCase(str, str + s0);
	}
	return test;
}