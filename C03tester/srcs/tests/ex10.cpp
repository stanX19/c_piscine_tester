#include "C03tester.hpp"
#include <string.h>
static std::string s0("\0", 1);

std::string out_strlcpy(const char *src, int n) {
	char buf[90];
	int i = 0;
	while (i < 90)
		buf[i++] = '@';
	n = strlcpy(buf, src, n);
	return std::string(buf, 90) + " " + std::to_string(n);
}

UnitTest getEx10test() {
	UnitTest test("ex10");
	test.addRequiredFile("ft_strlcpy.c");
	test.addTemporaryMainFile(
		"unsigned int ft_strlcpy(char *dst, char *src, unsigned int n);",
		"char dst[100];"
		"memset(dst, '@', 90);"
		"int n = atoi(argv[2]);"
		"unsigned int t = ft_strlcpy(dst, argv[1], n);"
		"write(1, dst, 90);"
		"printf(\" %u\", t);"
	);
	test.addTestCase("\"Hello world!\" 13", out_strlcpy("Hello world!", 13));
	for (size_t i = 10; i < 20; i++) {
		std::string str = utils::generateRandomString(i);
		test.addTestCase(str + " " + std::to_string(i * 2), out_strlcpy(str.c_str(), i * 2));
		test.addTestCase(str + " " + std::to_string(i / 2), out_strlcpy(str.c_str(), i / 2));
	}
	test.addTestCase("\"\" 1", out_strlcpy("", 1));
	test.addTestCase("\"\n\n\n\" 4", out_strlcpy("\n\n\n", 4));
	test.addTestCase("\" \t\r\n\f\v\b\" 9", out_strlcpy(" \t\r\n\f\v\b", 9));
	test.addTestCase("\"\\`~!@#\\$%^&*()\" 14", out_strlcpy("`~!@#$%^&*()", 14));
	return test;
}