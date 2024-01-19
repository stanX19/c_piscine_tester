#include "C02tester.hpp"

static std::string qt("\"");

UnitTest getEx08test() {
	UnitTest test("ex08");
	test.addRequiredFile("ft_strlowcase.c");
	test.addTemporaryMainFile(
		"char*	ft_strlowcase(char *str);",
		"printf(\"%s\", ft_strlowcase(argv[1]));"
	);
	test.addTestCase(qt + "Hello World!" + qt, "hello world!");
	test.addTestCase("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
	test.addTestCase("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz");
	test.addTestCase("AbCdEfGhIjKlMnOpQrStUvWxYz", "abcdefghijklmnopqrstuvwxyz");
	test.addTestCase("aBcDeFgHiJkLmNoPqRsTuVwXyZ", "abcdefghijklmnopqrstuvwxyz");
	test.addTestCase(qt + qt, "");
	test.addTestCase("A", "a");
	test.addTestCase("Z", "z");
	test.addTestCase("0123456789", "0123456789");
	test.addTestCase("\"@AZ[\\`az{\"", "@az[`az{");
	test.addTestCase("0A_1B_2C_3D_4E_5F_6G_7X_8Y_9Z", "0a_1b_2c_3d_4e_5f_6g_7x_8y_9z");
	test.addTestCase(qt + "\a\b\t\n\v\f\r\x7F" + qt, "\a\b\t\n\v\f\r\x7F");
	test.addTestCase(qt + "A\aB\bC\tD\nE\vF\fG\rH\x7FI J" + qt, "a\ab\bc\td\ne\vf\fg\rh\x7Fi j");
	return test;
}