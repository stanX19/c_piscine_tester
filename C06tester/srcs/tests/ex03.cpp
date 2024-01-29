#include "C06tester.hpp"
#include <cstring>

static int	ft_strcmp(const std::string &s1, const std::string &s2)
{
	int				i;
	unsigned int	s1i;
	unsigned int	s2i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	s1i = s1[i];
	s2i = s2[i];
	return (s1i < s2i);
}

static std::string genExpected(const std::string& inputString) {
    std::istringstream iss(inputString);
    std::vector<std::string> words;
    std::string word;

    while (std::getline(iss, word, ' ')) {
        words.push_back(word);
    }
    std::sort(words.begin(), words.end(), ft_strcmp);
    std::ostringstream oss;
    for (const auto& w : words) {
        oss << w << '\n';
    }
    return oss.str();
}

static void addTestCaseArgv(UnitTest &test, std::string str) {
	test.addTestCase(str, genExpected(str));
}

void setEx03test(UnitTest &test) {
	test.configure("ex03", 1, true);
	test.addRequiredFile("ft_sort_params.c");
	addTestCaseArgv(test, "Hello world");
	addTestCaseArgv(test, "My tester is better than that mini moulinette.");
	addTestCaseArgv(test, "");
	addTestCaseArgv(test, "OneParamOnly");
	addTestCaseArgv(test, "C h o p p e d S t r i n g A s U s u a l");
	addTestCaseArgv(test, "fair~ Scarborough to going you Are");
}