#include "C03tester.hpp"
#include <string.h>
static std::string qt("\"", 1);

std::string out_strcat(const char *dst, const char *src) {
	char buf[90];
	int i = 0;
	while (i < 90)
		buf[i++] = '@';
	strcpy(buf, dst);
	strcat(buf, src);
	return std::string(buf, 90);
}

UnitTest getEx02test() {
	UnitTest test("ex02");
	test.addRequiredFile("ft_strcat.c");
	test.addTemporaryMainFile(
		"char *ft_strcat(char *dst, char *src);",
		"char dst[90];"
		"memset(dst, '@', 90);"
		"strcpy(dst, argv[1]);"
		"char* dst2 = ft_strcat(dst, argv[2]);"
		"if (dst != dst2) {printf(\"return value != dst\"); return 0; }"
		"write(1, dst, 90);"
	);
	test.addTestCase("\"Hello \" world!", out_strcat("Hello ", "world!"));
	test.addTestCase("\"\\`~!@#\" \"\\$%^&*()\"", out_strcat("`~!@#", "$%^&*()"));
	for (size_t i = 0; i < 10; i++) {
		std::string str1 = utils::generateRandomString(i);
		std::string str2 = utils::generateRandomString(i);
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt, out_strcat(str1.c_str(), str2.c_str()));
	}
	test.addTestCase("\"\" \"\"", out_strcat("", ""));
	test.addTestCase("\"\n\n\n\" \"\n\n\n\"", out_strcat("\n\n\n", "\n\n\n"));
	test.addTestCase("\" \t\r\n\" \"\f\v\b\"", out_strcat(" \t\r\n", "\f\v\b"));
	return test;
}