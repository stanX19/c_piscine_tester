#include "C03tester.hpp"
#include <cstring>
static std::string qt("\"", 1);


// apple source code
size_t std_strlcat(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return(dlen + strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	/* count does not include NUL */
}

std::string out_strlcat(const char *dst, const char *src, unsigned int n) {
	char buf[90];
	int i = 0;
	while (i < 90)
		buf[i++] = '@';
	strcpy(buf, dst);
	size_t ret = std_strlcat(buf, src, n);
	return std::string(buf, 90) + " " + std::to_string(ret);
}

UnitTest getEx05test() {
	UnitTest test("ex05");
	test.addRequiredFile("ft_strlcat.c");
	test.addTemporaryMainFile(
		"unsigned int ft_strlcat(char *dst, char *src, unsigned int nb);",
		"char dst[90];"
		"memset(dst, '@', 90);"
		"strcpy(dst, argv[1]);"
		"unsigned int x = ft_strlcat(dst, argv[2], atoi(argv[3]));"
		"write(1, dst, 90);"
		"printf(\" %u\", x);"
	);
	test.addTestCase("\"Hello \" \"world!\" 7", out_strlcat("Hello ", "world!", 7));
	test.addTestCase("\"\\`~!@#\" \"\\$%^&*()\" 7", out_strlcat("`~!@#", "$%^&*()", 7));
	for (size_t i = 0; i < 5; i++) {
		std::string str1 = utils::generateRandomString(i);
		std::string str2 = utils::generateRandomString(i);
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " " + std::to_string(i), out_strlcat(str1.c_str(), str2.c_str(), i));
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " " + std::to_string(i + 1), out_strlcat(str1.c_str(), str2.c_str(), i + 1));
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " " + std::to_string(i * 2 + 2), out_strlcat(str1.c_str(), str2.c_str(), i * 2 + 2));
		test.addTestCase(qt + str1 + qt + " " + qt + str2 + qt + " " + std::to_string(i / 2), out_strlcat(str1.c_str(), str2.c_str(), i / 2));
	}
	test.addTestCase("\"\" \"\" 1", out_strlcat("", "", 1));
	test.addTestCase("\"\n\n\n\" \"\n\n\n\" 4", out_strlcat("\n\n\n", "\n\n\n", 4));
	test.addTestCase("\" \t\r\n\" \"\f\v\b\" 4", out_strlcat(" \t\r\n", "\f\v\b", 4));
	return test;
}