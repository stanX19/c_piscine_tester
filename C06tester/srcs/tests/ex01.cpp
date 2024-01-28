#include "C06tester.hpp"

UnitTest getEx01test() {
	std::string name = "ft_recursive_factorial";
	UnitTest test("ex01");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"int " + name + "(int nb);",
		"printf(\"%i\", " + name + "(atoi(argv[1])));"
	);
	test.addTestCase("1", "1");
	test.addTestCase("2", "2");
	test.addTestCase("3", "6");
	test.addTestCase("4", "24");
	test.addTestCase("5", "120");
	test.addTestCase("6", "720");
	test.addTestCase("7", "5040");
	test.addTestCase("8", "40320");
	test.addTestCase("9", "362880");
	test.addTestCase("10", "3628800");
	test.addTestCase("11", "39916800");
	test.addTestCase("12", "479001600");
	test.addTestCase("0", "1");
	test.addTestCase("-1", "0");
	test.addTestCase("-2", "0");
	return test;
}