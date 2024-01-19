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
	test.addTestCase("0A#1B#2C#3D#4E#5F#6G#7X#8Y#9Z", "0a#1b#2c#3d#4e#5f#6g#7x#8y#9z");
	test.addTestCase(qt + "\a\b\t\n\v\f\r\x7F" + qt, "\a\b\t\n\v\f\r\x7F");
	test.addTestCase(qt + "A\aB\bC\tD\nE\vF\fG\rH\x7FI J" + qt, "a\ab\bc\td\ne\vf\fg\rh\x7Fi j");
	return test;
}