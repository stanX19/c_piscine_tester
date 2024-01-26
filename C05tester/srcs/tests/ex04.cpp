#include "C05tester.hpp"

UnitTest getEx04test() {
	std::string name = "ft_fibonacci";
	UnitTest test("ex04");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"int " + name + "(int nb);",
		"printf(\"%i\", " + name + "(atoi(argv[1])));"
	);
	test.addTestCase("-2", "-1");
	test.addTestCase("-1", "-1");
	test.addTestCase("0", "0");
	test.addTestCase("1", "1");
	test.addTestCase("2", "1");
	test.addTestCase("3", "2");
	test.addTestCase("4", "3");
	test.addTestCase("5", "5");
	test.addTestCase("6", "8");
	test.addTestCase("7", "13");
	test.addTestCase("8", "21");
	test.addTestCase("9", "34");
	test.addTestCase("10", "55");
	test.addTestCase("11", "89");
	test.addTestCase("12", "144");
	test.addTestCase("13", "233");
	test.addTestCase("14", "377");
	test.addTestCase("15", "610");
	test.addTestCase("16", "987");
	test.addTestCase("17", "1597");
	test.addTestCase("18", "2584");
	test.addTestCase("19", "4181");
	test.addTestCase("20", "6765");
	test.addTestCase("21", "10946");
	test.addTestCase("22", "17711");
	test.addTestCase("23", "28657");
	test.addTestCase("24", "46368");
	test.addTestCase("25", "75025");
	test.addTestCase("26", "121393");
	test.addTestCase("27", "196418");
	test.addTestCase("28", "317811");
	test.addTestCase("29", "514229");
	test.addTestCase("30", "832040");
	test.addTestCase("31", "1346269");
	test.addTestCase("32", "2178309");
	test.addTestCase("33", "3524578");
	test.addTestCase("34", "5702887");
	test.addTestCase("35", "9227465");
	test.addTestCase("36", "14930352");
	test.addTestCase("37", "24157817");
	test.addTestCase("38", "39088169");
	test.addTestCase("39", "63245986");
	test.addTestCase("40", "102334155");
	test.addTestCase("41", "165580141");

	return test;
}