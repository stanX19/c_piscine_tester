#include "C08tester.hpp"

UnitTest getEx02test()  {
	UnitTest test("ex02", 1);
	test.addTemporaryMainFile(
	"#include \"ft_abs.h\"\n",
	"printf(\"%i\", ABS(atoi(argv[1])));"
	);
	test.addRequiredFile("ft_abs.h");
	test.addTestCase("10", "10");
	test.addTestCase("2", "2");
	test.addTestCase("1", "1");
	test.addTestCase("0", "0");
	test.addTestCase("-1", "1");
	test.addTestCase("-2", "2");
	test.addTestCase("-10", "10");
	test.addTestCase("-2147483647", "2147483647");
	test.addTestCase("2147483647", "2147483647");

	return test;
}
