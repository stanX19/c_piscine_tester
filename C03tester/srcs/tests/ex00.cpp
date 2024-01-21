#include "C03tester.hpp"
#include <string.h>

static std::string qt("\"", 1);

static std::string get_result(const char* s1, const char *s2) {
	int val = strcmp(s1, s2);
	if (val < 0) val = -1;
	if (val > 0) val = 1;
	return std::to_string(val);
}

UnitTest getEx00test() {
	UnitTest test("ex00");
	test.addRequiredFile("ft_strcmp.c");
	test.addTemporaryMainFile(
		"int ft_strcmp(char *s1, char *s2);",
		"int val = ft_strcmp(argv[1], argv[2]);"
		"if (val < 0) val = -1;\n"
		"if (val > 0) val = 1;\n"
		"printf(\"%d\", val);"
	);
	test.addTestCase("\"Hello world!\" \"Hello world!\"", "0");
	test.addTestCase("\"\" \"\"", "0");
	test.addTestCase("\"\n\n\n\" \"\n\n\n\"", "0");
	test.addTestCase("\"\t\r\n\f\v\b\" \"\t\r\n\f\v\b\"", "0");
	test.addTestCase("\"\\`~!@#\\$%^&*()\" \"\\`~!@#\\$%^&*()\"", "0");
	for (int i = 1; i <= 32; i += 3) {
		char c1 = i;
		std::string str1(1, c1);
		std::string str2 = "a";
		const char *cstr1 = str1.c_str();
		const char *cstr2 = str2.c_str();
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt, get_result(cstr1, cstr2));
	}
	for (int i = 127; i <= 255; i += 32) {
		char c1 = i;
		std::string str1(1, c1);
		std::string str2 = "a";
		const char *cstr1 = str1.c_str();
		const char *cstr2 = str2.c_str();
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt, get_result(cstr1, cstr2));
	}
	for (size_t i = 0; i < 10; i++) {
		std::string s1 = utils::generateRandomString(i);
		std::string s2 = utils::generateRandomString(i);
		const char* c1 = s1.c_str();
		const char* c2 = s2.c_str();
		test.addTestCase(qt + s1 + qt + " " + qt + s2 + qt, get_result(c1, c2));
	}
	return test;
}