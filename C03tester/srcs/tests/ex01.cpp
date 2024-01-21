#include "C03tester.hpp"

static std::string qt("\"", 1);

static std::string get_result(const char* s1, const char *s2, unsigned int n) {
	int val = std::strncmp(s1, s2, n);
	if (val < 0) val = -1;
	if (val > 0) val = 1;
	return std::to_string(val);
}

UnitTest getEx01test() {
	UnitTest test("ex01");
	test.addRequiredFile("ft_strncmp.c");
	test.addTemporaryMainFile(
		"int ft_strncmp(char *s1, char *s2, unsigned int n);",
		"int val = ft_strncmp(argv[1], argv[2], atoi(argv[3]));"
		"if (val < 0) val = -1;\n"
		"if (val > 0) val = 1;\n"
		"printf(\"%d\", val);"
	);
	test.addTestCase("\"Hello world!\" \"Hello world!\" 100", "0");
	test.addTestCase("\"\" \"\" 100", "0");
	test.addTestCase("\"\n\n\n\" \"\n\n\n\" 100", "0");
	test.addTestCase("\"\t\r\n\f\v\b\" \"\t\r\n\f\v\b\" 100", "0");
	test.addTestCase("\"\\`~!@#\\$%^&*()\" \"\\`~!@#\\$%^&*()\" 100", "0");
	for (int i = 1; i <= 32; i+=3) {
		char c1 = i;
		std::string str1(1, c1);
		std::string str2 = "a";
		const char *cstr1 = str1.c_str();
		const char *cstr2 = str2.c_str();
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " 1", get_result(cstr1, cstr2, 1));
	}
	for (int i = 127; i <= 255; i+=32) {
		char c1 = i;
		std::string str1(1, c1);
		std::string str2 = "a";
		const char *cstr1 = str1.c_str();
		const char *cstr2 = str2.c_str();
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " 1", get_result(cstr1, cstr2, 1));
	}
	for (size_t i = 0; i < 3; i++) {
		std::string s1 = utils::generateRandomString(i);
		std::string s2 = utils::generateRandomString(i);
		std::string s3 = utils::generateRandomString(i);
		s2 = s1 + s2 + s3;
		s1 = s1 + s3;
		const char* c1 = s1.c_str();
		const char* c2 = s2.c_str();
		test.addTestCase(qt + s1 + qt + " " + qt + s2 + qt + " " + std::to_string(i), get_result(c1, c2, i));
		test.addTestCase(qt + s1 + qt + " " + qt + s2 + qt + " " + std::to_string(i + 1), get_result(c1, c2, i + 1));
		test.addTestCase(qt + s1 + qt + " " + qt + s2 + qt + " " + std::to_string(3 * i + 2), get_result(c1, c2, 3 * i + 2));
	}
	return test;
}