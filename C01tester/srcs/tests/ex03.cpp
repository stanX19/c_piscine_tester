#include "C01tester.hpp"

static std::string	ft_div_mod(int a, int b)
{
	int div = a / b;
	int mod = a % b;

	std::ostringstream oss;
	oss << div << " " << mod;
	return oss.str();
}

UnitTest getEx03test() {
	std::string name = "ft_div_mod";
	UnitTest test("ex03");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(int a, int b, int *div, int *mod);",
		"int a = atoi(argv[1]);"
		"int b = atoi(argv[2]);"
		"int div;"
		"int mod;"
		"ft_div_mod(a, b, &div, &mod);"
		"printf(\"%i %i\", div, mod);"
	);
	for (int i = -10; i < 10; i++) {
		for (int j = 1; j < 3; j++) {
			std::ostringstream oss;
			oss << i << " " << j;
			test.addTestCase(oss.str(), ft_div_mod(i, j));
		}
		for (int j = -3; j <= -1; j++) {
			std::ostringstream oss;
			oss << i << " " << j;
			test.addTestCase(oss.str(), ft_div_mod(i, j));
		}
	}
	test.addTestCase("2147483647 -2147483648", ft_div_mod(2147483647, -2147483648));
	test.addTestCase("-2147483648 2147483647", ft_div_mod(-2147483648, 2147483647));
	test.addTestCase("1000 -2147483648", ft_div_mod(1000, -2147483648));
	test.addTestCase("2147483647 1000", ft_div_mod(2147483647, 1000));
	return test;
}
