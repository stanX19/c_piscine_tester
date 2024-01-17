#include "C01tester.hpp"

UnitTest getEx08test() {
	std::string name = "ft_sort_int_tab";
	UnitTest test("ex08");
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
	test.addTestCase("0 1 ", "0 1 ");
	test.addTestCase("3 1 2", "1 2 3 ");
	test.addTestCase("9 8 7 6 5 4 3 2 1 ", "1 2 3 4 5 6 7 8 9 ");
	test.addTestCase("4 1 -1 -2 5 4 1 ", "-2 -1 1 1 4 4 5 ");
	test.addTestCase("2147483647 -2147483648 1 2 3 ", "-2147483648 1 2 3 2147483647 ");
	std::ostringstream input;
	std::ostringstream output;
	for (int i = 0; i < 1000; i++) {
		input << 999 - i << " ";
		output << i << " ";
	}
	test.addTestCase(input.str(), output.str());

	return test;
}