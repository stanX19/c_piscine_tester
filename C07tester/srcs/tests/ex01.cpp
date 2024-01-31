#include "C07tester.hpp"

static void addTestCaseArgv(UnitTest &test, std::string str) {
	std::istringstream iss(str);
	std::ostringstream oss;
	int a, b;
	iss >> a >> b;
	if (a < b) {
		for (int i = a; i < b; i++) {
			oss << i << ", ";
		}
	}
	else
		oss << "NULL";
	test.addTestCase(str, oss.str());
}

UnitTest getEx01test() {
	UnitTest test("ex01", 1);
	test.addRequiredFile("ft_range.c");
	test.addTemporaryMainFile(
		"int	*ft_range(int min, int max);",
		"int a = atoi(argv[1]);"
		"int b = atoi(argv[2]);"
		"int *ret = ft_range(a, b);"
		"if (!ret) {printf(\"NULL\");return 0;}"
		"for (int i = 0; i < b - a; i++) { printf(\"%i, \", ret[i]); }"
		"free(ret);"
	);
	addTestCaseArgv(test, "0 1");
	addTestCaseArgv(test, "1 10");
	addTestCaseArgv(test, "10 20");
	addTestCaseArgv(test, "-10 0");
	addTestCaseArgv(test, "-10000 -9900");
	addTestCaseArgv(test, "-2147483648 -2147483640");
	addTestCaseArgv(test, "2147483640 2147483647");

	addTestCaseArgv(test, "1 0");
	addTestCaseArgv(test, "-1 -2");
	addTestCaseArgv(test, "-1 -2");
	addTestCaseArgv(test, "2147483647 -2147483648");
	return test;
}