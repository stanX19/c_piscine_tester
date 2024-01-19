#include "C02tester.hpp"

static std::string qt("\"");

std::string gen_lower_str(int size) {
	const char *alpha = "abcdefghijklmnopqrstuvwxyz";
	std::ostringstream oss;
	for (int i = 0; i < size; i++)
		oss << alpha[i % 26];
	return oss.str();
}

UnitTest getEx04test() {
	UnitTest test("ex04");
	test.addRequiredFile("ft_str_is_lowercase.c");
	test.addTemporaryMainFile(
		"int	ft_str_is_lowercase(char *str);",
		"printf(\"%i\", ft_str_is_lowercase(argv[1]));"
	);
	static const char *non_lowercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\t\r\n\f\v\b 1234567890";
	for (size_t i = 1; i < 26; i++) {
		if (i == 4)
			i = 24;
		std::string str = gen_lower_str(i);
		test.addTestCase(qt + str + qt, "1");
		test.addTestCase(qt + str + non_lowercase[i % 43] + qt, "0");
		test.addTestCase(qt + str + non_lowercase[i * 3 % 43] + str + qt, "0");
		test.addTestCase(qt + non_lowercase[i * 5 % 43] + str + non_lowercase[i * 7 % 43] + qt, "0");
	}
	return test;
}