#include "C02tester.hpp"

static std::string qt("\"");

std::string gen_num_str(int size) {
	const char *alpha = "1234567890";
	std::ostringstream oss;
	for (int i = 0; i < size; i++)
		oss << alpha[i % 10];
	return oss.str();
}

UnitTest getEx03test() {
	UnitTest test("ex03");
	test.addRequiredFile("ft_str_is_numeric.c");
	test.addTemporaryMainFile(
		"int	ft_str_is_numeric(char *str);",
		"printf(\"%i\", ft_str_is_numeric(argv[1]));"
	);
	static const char *non_numeric = "\t\r\n\f\v\b abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (size_t i = 1; i <= 10; i++) {
		std::string str = gen_num_str(i);
		test.addTestCase(str, "1");
		test.addTestCase(qt + str + non_numeric[i % 59] + qt, "0");
		test.addTestCase(qt + str + non_numeric[i * 10 % 59] + str + qt, "0");
		test.addTestCase(qt + non_numeric[i * 7 % 59] + str + non_numeric[i * 14 % 59] + qt, "0");
	}
	return test;
}