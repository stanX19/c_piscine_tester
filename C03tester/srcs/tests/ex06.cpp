#include "C03tester.hpp"

static std::string qt("\"");

std::string gen_printable_str(int size) {
	const char *alpha = "1234567890 abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::ostringstream oss;
	for (int i = 0; i < size; i++)
		oss << alpha[i % 64];
	return oss.str();
}

UnitTest getEx06test() {
	UnitTest test("ex06");
	test.addRequiredFile("ft_str_is_printable.c");
	test.addTemporaryMainFile(
		"int	ft_str_is_printable(char *str);",
		"printf(\"%i\", ft_str_is_printable(argv[1]));"
	);
	static const char *non_printable = "\a\b\t\n\v\f\r\n\x7F";
	for (size_t i = 1; i < 64; i++) {
		//skip range
		if (i == 4)
			i = 58;
		std::string str = gen_printable_str(i);
		test.addTestCase(qt + str + qt, "1");
		test.addTestCase(qt + str + non_printable[i % 8] + qt, "0");
		test.addTestCase(qt + str + non_printable[i * 8 % 8] + str + qt, "0");
		test.addTestCase(qt + non_printable[i * 7 % 8] + str + non_printable[i * 14 % 8] + qt, "0");
	}
	return test;
}