#include "C02tester.hpp"

static std::string qt("\"");

std::string convertUnprintableToHex(const std::string& input) {
    std::ostringstream result;

    for (char ch : input) {
        if (isprint(static_cast<unsigned char>(ch))) {
            result << ch;
        } else {
            result << '\\' << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(static_cast<unsigned char>(ch));
        }
    }

    return result.str();
}

UnitTest getEx11test() {
	UnitTest test("ex11");
	test.addRequiredFile("ft_putstr_non_printable.c");
	test.addTemporaryMainFile(
		"void	ft_putstr_non_printable(char *str);",
		"ft_putstr_non_printable(argv[1]);"
	);
	test.addTestCase(qt + "Hello World!" + qt, "Hello World!");
	test.addTestCase("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
	test.addTestCase(qt + qt, "");
	for (int i = 1; i <= 32; i++) {
		char c = i;
		std::string str(1, c);
		test.addTestCase(qt + str + qt, convertUnprintableToHex(str));
	}
	for (int i = 127; i <= 255; i++) {
		char c = i;
		std::string str(1, c);
		test.addTestCase(qt + str + qt, convertUnprintableToHex(str));
	}
	std::string buf;
	std::string buf2;
	for (int i = 1; i <= 33; i++) {
		char c = i;
		std::string str(1, c);
		buf += str;
		buf2 += str + " ";
	}
	for (int i = 125; i <= 255; i++) {
		char c = i;
		std::string str(1, c);
		buf += str;
		buf2 += str + " ";
	}
	test.addTestCase(qt + buf + qt, convertUnprintableToHex(buf));
	test.addTestCase(qt + buf2 + qt, convertUnprintableToHex(buf2));
	return test;
}