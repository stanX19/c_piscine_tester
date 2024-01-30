#include "C06tester.hpp"

static std::string genExpected(const std::string& inputString) {
    std::istringstream iss(inputString);
    std::vector<std::string> words;
    std::string word;

    while (std::getline(iss, word, ' ')) {
        words.push_back(word);
    }
    std::reverse(words.begin(), words.end());
    std::ostringstream oss;
    for (const auto& w : words) {
        oss << w << '\n';
    }
    return oss.str();
}

static void addTestCaseArgv(UnitTest &test, std::string str) {
	test.addTestCase(str, genExpected(str));
}

void setEx02test(UnitTest &test) {
	test.configure("ex02", 1, true);
	test.addRequiredFile("ft_rev_params.c");
	addTestCaseArgv(test, "Hello world");
	addTestCaseArgv(test, "Thanks again for using my tester instead of that mini moulinette.");
	addTestCaseArgv(test, "");
	addTestCaseArgv(test, "OneParamOnly");
	test.addTestCase("Here comes the unprintables: '\222\356\3\5\7\322\t\r\b'", "\222\356\3\5\7\322\t\r\b\nunprintables:\nthe\ncomes\nHere\n");
	addTestCaseArgv(test, "C h o p p e d S t r i n g A s U s u a l");
	addTestCaseArgv(test, "fair~ Scarborough to going you Are");
}