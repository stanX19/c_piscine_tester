#include "C07tester.hpp"

static std::vector<std::string> splitString(const char* input, std::string charset) {
    std::vector<std::string> result;
    result.push_back(input);

    for (auto &sep : charset) {
        std::vector<std::string> new_result;
        for (auto &line : result) {
            std::istringstream stream(line);
            std::string token;
            while (std::getline(stream, token, sep)) {
                new_result.push_back(token);
            }
        }
        result = new_result;
    }
    return result;
}

static void addTestCaseArgv(UnitTest &test, const char* str, const char *sep) {
	std::vector<std::string> words = splitString(str, sep);
	std::ostringstream oss;
	for (auto &word: words)
		oss << "\"" << word << "\", ";
	std::string answer = oss.str();
	answer = "[" + answer.substr(0, answer.size() - 2) + "]";
	test.addTestCase(std::string(str) + " " + sep, oss.str());
}

void setEx02test(UnitTest &test) {
	test.configure("ex02", 1, true);
	test.addRequiredFile("ft_ultimate_range.c");
	test.addTemporaryMainFile(
		"int	ft_ultimate_range(int **range, int min, int max);",
		"int a = atoi(argv[1]);"
		"int b = atoi(argv[2]);"
		"int *ret;"
		"int size = ft_ultimate_range(&ret, a, b);"
		"if (!ret)"
		"	printf(\"NULL \");"
		"else"
		"	for (int i = 0; i < size; i++) { printf(\"%i, \", ret[i]); }"
		"printf(\"size=%i\", size);"
		"free(ret);"
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
}