#include "C05tester.hpp"

UnitTest getEx08test() {
	UnitTest test("ex08", 10, 1);
	test.addRequiredFile("ft_ten_queens_puzzle.c");
	test.addTemporaryMainFile(
		"int ft_ten_queens_puzzle(void);",
		"fflush(stdout);"
		"int fd = dup(STDOUT_FILENO);"
   		"freopen(\"/dev/null\", \"w\", stdout);"
		"int ret = ft_ten_queens_puzzle();"
		"fflush(stdout);"
    	"dup2(fd, fileno(stdout));"
		"printf(\"%i\", ret);"
	);
	test.addTestCase("None", "724");
	return test;
}