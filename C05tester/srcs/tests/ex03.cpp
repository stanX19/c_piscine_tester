#include "C05tester.hpp"

UnitTest getEx03test() {
	std::string name = "ft_recursive_power";
	UnitTest test("ex03");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"int " + name + "(int nb, int power);",
		"printf(\"%i\", " + name + "(atoi(argv[1]), atoi(argv[2])));"
	);
	test.addTestCase("2 5", "32");
	test.addTestCase("5 0", "1");
	test.addTestCase("-1 0", "1");
	test.addTestCase("-1 -1", "0");
	test.addTestCase("-2 -1", "0");
	test.addTestCase("-24 2", "576");
	test.addTestCase("-42 3", "-74088");
	test.addTestCase("1 2147483647", "1");
	test.addTestCase("-1 2147483647", "-1");
	test.addTestCase("0 2147483647", "0");
	test.addTestCase("2 30", "1073741824");
	test.addTestCase("-2 31", "-2147483648");

	return test;
}