#include "C04tester.hpp"
#include <string.h>

UnitTest getEx05test() {
	UnitTest test("ex05");
	test.addRequiredFile("ft_atoi_base.c");
	test.addTemporaryMainFile(
		"int ft_atoi_base(char *str, char *base);",
		"printf(\"%i\", ft_atoi_base(argv[1], argv[2]));"
	);
	test.addTestCase("123456789 0123456789", "123456789");
	test.addTestCase("\"  \t\n\f\r1234\" 0123456789", "1234");
	test.addTestCase("\"  \t\n\f\r#4321   \" 0123456789", "0");
	test.addTestCase("\"  \t\n\f\r---123!5###\" 0123456789", "-123");
	test.addTestCase("\"  --\t\n\f\r+12345###\" 0123456789", "0");
	test.addTestCase("CR ReapeatdChars", "0");
	test.addTestCase("0 0", "0");
	test.addTestCase("0 01", "0");
	test.addTestCase("1 01", "1");
	test.addTestCase("-1 01", "-1");
	test.addTestCase("-------------------++--------+++---1 012", "1");
	test.addTestCase("Supprised? p?usSerdi", "1636184836");
	test.addTestCase("186A0 0123456789ABCDEF", "100000");
	test.addTestCase("ZZZ 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", "46655");
	test.addTestCase("12112122212110202101 012", "2147483647");
	test.addTestCase("-10000000000000000000000000000000 01", "-2147483648");
	test.addTestCase("--1111111111111111111111111111111 01", "2147483647");
	test.addTestCase("-----zyxwv 0123456789ABCDEFGHIJKLMNOPQRTUVWXYZabcdefghijklmnopqrstuvwxyz", "-844361690");
	test.addTestCase("\"--+--\xFF\xF0---123\" \"123\xF6\xFF\xF0\"", "29");
	return test;
}