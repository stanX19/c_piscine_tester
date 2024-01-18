#include "C02tester.hpp"

static std::string s0("\0", 1);

std::string out_strncpy(const char *src, int n) {
	char buf[90];
	int i = 0;
	while(src[i] && i < n) {
		buf[i] = src[i];
		i++;
	}
	while (i < n)
		buf[i++] = '\0';
	while (i < 90)
		buf[i++] = '@';
	return std::string(buf, 90);
}

UnitTest getEx01test() {
	UnitTest test("ex01");
	test.addRequiredFile("ft_strncpy.c");
	test.addTemporaryMainFile(
		"void ft_strncpy(char *dst, char *src, unsigned int n);",
		"char dst[100];"
		"memset(dst, '@', 90);"
		"int n = atoi(argv[2]);"
		"ft_strncpy(dst, argv[1], n);"
		"write(1, dst, 90);"
	);
	test.addTestCase("\"Hello world!\" 13", out_strncpy("Hello world!", 13));
	test.addTestCase("\"\" 1", out_strncpy("", 1));
	test.addTestCase("\"\n\n\n\" 4", out_strncpy("\n\n\n", 4));
	test.addTestCase("\" \t\r\n\f\v\b\" 9", out_strncpy(" \t\r\n\f\v\b", 9));
	test.addTestCase("\"\\`~!@#\\$%^&*()\" 14", out_strncpy("`~!@#$%^&*()", 14));
	for (size_t i = 10; i < 20; i++) {
		std::string str = utils::generateRandomString(i);
		test.addTestCase(str + " " + std::to_string(i * 2), out_strncpy(str.c_str(), i * 2));
		test.addTestCase(str + " " + std::to_string(i / 2), out_strncpy(str.c_str(), i / 2));
	}
	return test;
}