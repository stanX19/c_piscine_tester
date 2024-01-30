#include "C07tester.hpp"

void setEx00test(UnitTest &test) {
	test.configure("ex00", 1);
	test.addTemporaryMainFile(
		"char	*ft_strdup(char *src);",
		"char *ret = ft_strdup(argv[1]);"
		"printf(\"%s\", ret);"
		"free(ret);"
	);
	test.addRequiredFile("ft_strdup.c");
	test.addTestCase("''", "");
	test.addTestCase("'Hello World!'", "Hello World!");
	test.addTestCase("'\1\2\3\4\037\177'", "\1\2\3\4\037\177");
	test.addTestCase("'This is a very long string'", "This is a very long string");
	test.addTestCase("'0123456789'", "0123456789");
	test.addTestCase("'!@#$%^&*(*&^%$#@!#$%^&*)~'", "!@#$%^&*(*&^%$#@!#$%^&*)~");
}