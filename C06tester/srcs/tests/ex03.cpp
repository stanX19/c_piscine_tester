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
	addTestCaseArgv(test, "z y x w v u t s r q p o n m l k j i h g f e d c b a Z Y X W V U T S R Q P O N M L K J I H G F E D C B A");
	addTestCaseArgv(test, "aba abb aaa aab ABB AAB ABA AAA ZYZ zYZ zyZ zZZ");
	test.addTestCase("'\13' '\11' '\10' '\07' '\06' '\177'", "\06\n\07\n\10\n\11\n\13\n\177\n");
}