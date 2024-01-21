#include "C03tester.hpp"
#include <string.h>
static std::string qt("\"", 1);

std::string out_strncat(const char *dst, const char *src, unsigned int n) {
	char buf[90];
	int i = 0;
	while (i < 90)
		buf[i++] = '@';
	strcpy(buf, dst);
	strncat(buf, src, n);
	return std::string(buf, 90);
}

UnitTest getEx03test() {
	UnitTest test("ex03");
	test.addRequiredFile("ft_strncat.c");
	test.addTemporaryMainFile(
		"char *ft_strncat(char *dst, char *src, unsigned int nb);",
		"char dst[90];"
		"memset(dst, '@', 90);"
		"strcpy(dst, argv[1]);"
		"char* dst2 = ft_strncat(dst, argv[2], atoi(argv[3]));"
		"if (dst != dst2) {printf(\"return value != dst\"); return 0; }"
		"write(1, dst, 90);"
	);
	test.addTestCase("\"Hello \" world! 7", out_strncat("Hello ", "world!", 7));
	test.addTestCase("\"\\`~!@#\" \"\\$%^&*()\" 7", out_strncat("`~!@#", "$%^&*()", 7));
	for (size_t i = 0; i < 5; i++) {
		std::string str1 = utils::generateRandomString(i);
		std::string str2 = utils::generateRandomString(i);
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " " + std::to_string(i), out_strncat(str1.c_str(), str2.c_str(), i));
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " " + std::to_string(i + 1), out_strncat(str1.c_str(), str2.c_str(), i + 1));
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " " + std::to_string(i * 2 + 2), out_strncat(str1.c_str(), str2.c_str(), i * 2));
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " " + std::to_string(i / 2), out_strncat(str1.c_str(), str2.c_str(), i / 2));
	}
	test.addTestCase("\"\" \"\" 1", out_strncat("", "", 1));
	test.addTestCase("\"\n\n\n\" \"\n\n\n\" 4", out_strncat("\n\n\n", "\n\n\n", 4));
	test.addTestCase("\" \t\r\n\" \"\f\v\b\" 4", out_strncat(" \t\r\n", "\f\v\b", 4));
	return test;
}