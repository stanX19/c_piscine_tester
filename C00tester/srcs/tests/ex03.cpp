#include "C00tester.hpp"

UnitTest getEx03test() {
	std::string name = "ft_print_numbers";
	UnitTest test("ex03");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(void);",
		name + "();"
	);
	test.addTestCase("None", "0123456789");
	return test;
}
