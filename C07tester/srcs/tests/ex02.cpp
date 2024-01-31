#include "C07tester.hpp"

static void addTestCaseArgv(UnitTest &test, std::string str) {
	std::istringstream iss(str);
	std::ostringstream oss;
	int size;
	int a, b;
	iss >> a >> b;
	if (a < b) {
		size = b - a;
		for (int i = a; i < b; i++) {
			oss << i << ", ";
		}
		oss << "size=" << size;
	}
	else {
		oss << "NULL size=0";
	}
	test.addTestCase(str, oss.str());
}

UnitTest getEx02test() {
	UnitTest test("ex02", 1, true);
	test.addRequiredFile("ft_ultimate_range.c");
	test.addTemporaryMainFile(
		"int	ft_ultimate_range(int **range, int min, int max);",
		"int a = atoi(argv[1]);"
		"int b = atoi(argv[2]);"
		"int *ret;"
		"int size = ft_ultimate_range(&ret, a, b);"
		"if (ret) {"
		"	for (int i = 0; i < size; i++) { printf(\"%i, \", ret[i]); }"
		"	free(ret);"
		"} else {"
		"	printf(\"NULL \");"
		"}"
		"printf(\"size=%i\", size);"
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