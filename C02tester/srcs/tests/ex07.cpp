#include "C02tester.hpp"

UnitTest getEx07test() {
	std::string name = "ft_rev_int_tab";
	UnitTest test("ex07");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(int *arr, int size);",
		"int arr[1000];"
		"for (int i = 1; i < argc; i++) {"
		"	arr[i - 1] = atoi(argv[i]);"
		"}"
		+ name + "(arr, argc - 1);"
		"for (int i = 0; i < argc - 1; i++) {"
		"	printf(\"%i \", arr[i]);"
		"}"
	);
	test.addTestCase("1 ", "1 ");
	test.addTestCase("0 1 ", "1 0 ");
	test.addTestCase("3 1 2", "2 1 3 ");
	test.addTestCase("1 2 3 4 5 6 7 8 9", "9 8 7 6 5 4 3 2 1 ");
	test.addTestCase("-2 -1 1 4 5 1 4 ", "4 1 5 4 1 -1 -2 ");
	test.addTestCase("-2147483648 3 2 1 2147483647", "2147483647 1 2 3 -2147483648 ");
	test.addTestCase("2147483647 0 ", "0 2147483647 ");

	return test;
}