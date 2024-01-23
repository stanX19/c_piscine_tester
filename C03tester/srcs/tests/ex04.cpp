#include "C03tester.hpp"
#include <string.h>
static std::string qt("\"", 1);

std::string out_strstr(const char *dst, const char *src) {
	const char *ret = strstr(dst, src);
	if (ret == 0)
		return "Not found";
	return "Index " + std::to_string(ret - dst);
}

UnitTest getEx04test() {
	UnitTest test("ex04");
	test.addRequiredFile("ft_strstr.c");
	test.addTemporaryMainFile(
		"char *ft_strstr(char *str, char *to_find);",
		"char* dst = ft_strstr(argv[1], argv[2]);"
		"if (dst == 0) {printf(\"Not found\"); return 0;}"
		"printf(\"Index %li\", dst - argv[1]);"
	);
	test.addTestCase("\"Hello world!\" \"world!\"", out_strstr("Hello world!", "world!"));
	test.addTestCase("\"Hello world!\" \"universe\"", out_strstr("Hello world!", "universe"));
	test.addTestCase("\"Hello world!\" \"\"", out_strstr("Hello world!", ""));
	test.addTestCase("\"\\`~!@#\\$%^&*()\" \"%\"", out_strstr("`~!@#$%^&*()", "%"));
	for (size_t i = 5; i < 10; i++) {
		std::string str1 = utils::generateRandomString(i);
		std::string str2 = str1.substr(i / 2, i - i / 2);
		std::string str3 = str1.substr(0, i / 2);
		std::string str4 = str2 + str3;
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt, out_strstr(str1.c_str(), str2.c_str()));
		test.addTestCase(qt + str1 + qt + " " + qt + str3 + qt, out_strstr(str1.c_str(), str3.c_str()));
		test.addTestCase(qt + str1 + qt + " " + qt + str4 + qt, out_strstr(str1.c_str(), str4.c_str()));
	}
	test.addTestCase("aacbaacbaaa aacbaaa", out_strstr("aacbaacbaaa", "aacbaaa"));
	test.addTestCase("\"\" \"\"", out_strstr("", ""));
	test.addTestCase("\"\n\n\n\" \"\n\n\n\"", out_strstr("\n\n\n", "\n\n\n"));
	test.addTestCase("\" \t\r\n\f\v\b\" \"\r\"", out_strstr(" \t\r\n\f\v\b", "\r"));
	return test;
}