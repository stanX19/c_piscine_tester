#include "C06tester.hpp"

static void addTestCaseArgv(UnitTest &test, std::string str) {
	std::string answer = str;
	std::replace(answer.begin(), answer.end(), ' ', '\n');
	test.addTestCase(str, answer + '\n');
}

UnitTest getEx01test() {
	UnitTest test("ex01", 1, true);
	test.addRequiredFile("ft_print_params.c");
	addTestCaseArgv(test, "Hello world");
	addTestCaseArgv(test, "Thanks for using my tester instead of that mini moulinette.");
	test.addTestCase("", "");
	addTestCaseArgv(test, "OneParamOnly");
	test.addTestCase("Here comes the unprintable: '\222\356\3\5'", "Here\ncomes\nthe\nunprintable:\n\222\356\3\5\n");
	addTestCaseArgv(test, "W h a t A b o u t T h i s");
	addTestCaseArgv(test, "One morning, when Gregor Samsa woke from troubled dreams, he found himself transformed in his bed into a horrible vermin. He lay on his armour-like back, and if he lifted his head a little he could see his brown belly, slightly domed and divided by arches into stiff sections.");
	return test;
}