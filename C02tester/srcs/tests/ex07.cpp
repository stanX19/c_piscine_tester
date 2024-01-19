#include "C02tester.hpp"

static std::string qt("\"");

UnitTest getEx07test() {
	UnitTest test("ex07");
	test.addRequiredFile("ft_strupcase.c");
	test.addTemporaryMainFile(
		"char*	ft_strupcase(char *str);",
		"printf(\"%s\", ft_strupcase(argv[1]));"
	);
	test.addTestCase(qt + "Hello world!" + qt, "HELLO WORLD!");
	test.addTestCase("abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	test.addTestCase("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	test.addTestCase("AbCdEfGhIjKlMnOpQrStUvWxYz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	test.addTestCase("aBcDeFgHiJkLmNoPqRsTuVwXyZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	test.addTestCase(qt + qt, "");
	test.addTestCase("a", "A");
	test.addTestCase("z", "Z");
	test.addTestCase("0123456789", "0123456789");
	test.addTestCase("\"@AZ[\\`az{\"", "@AZ[`AZ{");
	test.addTestCase("0a_1b_2c_3d_4e_5f_6g_7x_8y_9z", "0A_1B_2C_3D_4E_5F_6G_7X_8Y_9Z");
	test.addTestCase(qt + "\a\b\t\n\v\f\r\x7F" + qt, "\a\b\t\n\v\f\r\x7F");
	test.addTestCase(qt + "a\ab\bc\td\ne\vf\fg\rh\x7Fi j" + qt, "A\aB\bC\tD\nE\vF\fG\rH\x7FI J");
	return test;
}