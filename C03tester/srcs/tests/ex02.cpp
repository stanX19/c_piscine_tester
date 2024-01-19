#include "C03tester.hpp"

static std::string qt("\"");

std::string gen_alpha_str(int size) {
	const char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::ostringstream oss;
	for (int i = 0; i < size; i++)
		oss << alpha[std::rand() % 52];
	return oss.str();
}

UnitTest getEx02test() {
	UnitTest test("ex02");
	test.addRequiredFile("ft_str_is_alpha.c");
	test.addTemporaryMainFile(
		"int	ft_str_is_alpha(char *str);",
		"printf(\"%i\", ft_str_is_alpha(argv[1]));"
	);
	static const char *non_alpha = "\t\r\n\f\v\b 1234567890";
	for (size_t i = 1; i <= 52; i++) {
		if (i == 4)
			i = 48;
		std::string str = gen_alpha_str(i);
		test.addTestCase(str, "1");
		test.addTestCase(qt + str + non_alpha[i % 17] + qt, "0");
		test.addTestCase(qt + str + non_alpha[i % 17] + str + qt, "0");
		test.addTestCase(qt + non_alpha[i % 17] + str + non_alpha[i % 17] + qt, "0");
	}
	return test;
}