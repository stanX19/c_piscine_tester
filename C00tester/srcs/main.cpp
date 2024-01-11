#include "UnitTest.hpp"

UnitTest getEx00test() {
	UnitTest test("ex00");
	test.addRequiredFile("ft_putchar.c");
	test.addTemporaryMainFile(
		"void ft_putchar(char c);",
		"printf(\"%c\", argv[1][0]);"
	);
	for (char c = '0'; c <= '9'; c++)
		test.addTestCase(std::string(1, c), std::string(1, c));
	for (char c = 'a'; c <= 'z'; c++)
		test.addTestCase(std::string(1, c), std::string(1, c));
	for (char c = 'A'; c <= 'Z'; c++)
		test.addTestCase(std::string(1, c), std::string(1, c));
	test.addTestCase("z", "z");
	return test;
}

UnitTest getEx01test() {
	UnitTest test("ex01");
	test.addRequiredFile("ft_print_alphabet.c");
	test.addTemporaryMainFile(
		"void ft_print_alphabet(void);",
		"ft_print_alphabet()"
	);
	test.addTestCase("None", "abcdefghijklmnopqrstuvwxyz");
	return test;
}

UnitTest getEx02test() {
	UnitTest test("ex02");
	test.addRequiredFile("ft_print_reverse_alphabet.c");
	test.addTemporaryMainFile(
		"void ft_print_reverse_alphabet(void);",
		"ft_print_reverse_alphabet()"
	);
	test.addTestCase("None", "zyxwvutsrqponmlkjihgfedcba");
	return test;
}

UnitTest getEx03test() {
	std::string name = "ft_print_numbers";
	UnitTest test("ex03");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(void);",
		name + "();"
	);
	test.addTestCase("None", "0123456789");
	return test;
}

UnitTest getEx04test() {
	std::string name = "ft_is_negative";
	UnitTest test("ex04");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(int n);",
		name + "(atoi(argv[1]));"
	);
	test.addTestCase("-1", "N");
	test.addTestCase("0", "P");
	test.addTestCase("1", "P");
	test.addTestCase("2147483647", "P");
	test.addTestCase("-2147483648", "N");
	return test;
}

int main(int argc, char **argv) {
	if (!UnitTestconfig::parseArgv(argc, argv))
		return 1;
	std::vector<UnitTest> tests {
		getEx00test(),
		getEx01test(),
		getEx02test(),
		getEx04test()
	};
	for (auto &test : tests) {
		test.run();
	}
}
