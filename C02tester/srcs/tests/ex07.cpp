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
	test.addTestCase("0a#1b#2c#3d#4e#5f#6g#7x#8y#9z", "0A#1B#2C#3D#4E#5F#6G#7X#8Y#9Z");
	test.addTestCase(qt + "\a\b\t\n\v\f\r\x7F" + qt, "\a\b\t\n\v\f\r\x7F");
	test.addTestCase(qt + "a\ab\bc\td\ne\vf\fg\rh\x7Fi j" + qt, "A\aB\bC\tD\nE\vF\fG\rH\x7FI J");
	return test;
}