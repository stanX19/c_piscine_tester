#include "C02tester.hpp"

static std::string qt("\"");

std::string gen_upper_str(int size) {
	const char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::ostringstream oss;
	for (int i = 0; i < size; i++)
		oss << alpha[i % 26];
	return oss.str();
}

UnitTest getEx05test() {
	UnitTest test("ex05");
	test.addRequiredFile("ft_str_is_uppercase.c");
	test.addTemporaryMainFile(
		"int	ft_str_is_uppercase(char *str);",
		"printf(\"%i\", ft_str_is_uppercase(argv[1]));"
	);
	static const char *non_uppercase = "abcdefghijklmnopqrstuvwxyz\t\r\n\f\v\b 1234567890";
	for (size_t i = 1; i < 5; i++) {
		std::string str = gen_upper_str(i);
		test.addTestCase(qt + str + qt, "1");
		test.addTestCase(qt + str + non_uppercase[i % 43] + qt, "0");
		test.addTestCase(qt + str + non_uppercase[i * 3 % 43] + str + qt, "0");
		test.addTestCase(qt + non_uppercase[i * 5 % 43] + str + non_uppercase[i * 7 % 43] + qt, "0");
	}
	return test;
}