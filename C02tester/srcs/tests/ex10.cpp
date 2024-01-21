#include "C02tester.hpp"
#include <string.h>

static std::string qt("\"", 1);

// from apple source code
size_t std_strlcpy(char * dst, const char * src, size_t maxlen) {
    const size_t srclen = strlen(src);
    if (srclen + 1 < maxlen) {
        memcpy(dst, src, srclen + 1);
    } else if (maxlen != 0) {
        memcpy(dst, src, maxlen - 1);
        dst[maxlen-1] = '\0';
    }
    return srclen;
}

std::string out_strlcpy(const char *src, int n) {
	char buf[90];
	int i = 0;
	while (i < 90)
		buf[i++] = '@';
	n = std_strlcpy(buf, src, n);
	return std::string(buf, 90) + " " + std::to_string(n);
}

UnitTest getEx10test() {
	UnitTest test("ex10");
	test.addRequiredFile("ft_strlcpy.c");
	test.addTemporaryMainFile(
		"unsigned int ft_strlcpy(char *dst, char *src, unsigned int n);",
		"char dst[100];"
		"memset(dst, '@', 90);"
		"int n = atoi(argv[2]);"
		"unsigned int t = ft_strlcpy(dst, argv[1], n);"
		"write(1, dst, 90);"
		"printf(\" %u\", t);"
	);
	test.addTestCase("\"Hello world!\" 13", out_strlcpy("Hello world!", 13));
	for (size_t i = 0; i < 10; i++) {
		std::string str = utils::generateRandomString(i);
		test.addTestCase(qt + str + qt + " " + std::to_string(i * 2), out_strlcpy(str.c_str(), i * 2));
		test.addTestCase(qt + str + qt + " " + std::to_string(i / 2), out_strlcpy(str.c_str(), i / 2));
	}
	test.addTestCase("\"\" 1", out_strlcpy("", 1));
	test.addTestCase("\"\n\n\n\" 4", out_strlcpy("\n\n\n", 4));
	test.addTestCase("\" \t\r\n\f\v\b\" 9", out_strlcpy(" \t\r\n\f\v\b", 9));
	test.addTestCase("\"\\`~!@#\\$%^&*()\" 14", out_strlcpy("`~!@#$%^&*()", 14));
	return test;
}