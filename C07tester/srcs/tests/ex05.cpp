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
	std::vector<std::string> new_result;
	for (auto &str : result)
		if (!str.empty())
			new_result.push_back(str);
    return new_result;
}

static void addTestCaseArgv(UnitTest &test, const char* str, const char *sep) {
	std::vector<std::string> words = splitString(str, sep);
	std::ostringstream oss;
	for (auto &word: words)
		oss << "\"" << word << "\", ";
	std::string answer = oss.str();
	answer = "[" + answer.substr(0, answer.size() - 2) + "]";
	test.addTestCase("'" + std::string(str) + "' '" + sep + "'", answer);
}

void setEx05test(UnitTest &test) {
	test.configure("ex05", 1);
	test.addRequiredFile("ft_split.c");
	test.addTemporaryMainFile(
		"char	**ft_split(char *str, char *charset);",
		"char **ret = ft_split(argv[1], argv[2]);\n"
		"if (!ret)\n"
		"	printf(\"NULL\");\n"
		"else {\n"
		"	printf(\"[\");\n"
		"	int i = 0;\n"
		"	while(ret[i] && ret[i + 1]) {\n"
		"		printf(\"\\\"%s\\\", \", ret[i]);\n"
		"		free(ret[i]);\n"
		"		++i;\n"
		"	}\n"
		"	if (ret[i]) {\n"
		"		printf(\"\\\"%s\\\"\", ret[i]);\n"
		"		free(ret[i]);\n"
		"	}\n"
		"	printf(\"]\");\n"
		"	free(ret);\n"
		"}\n"
	);
	addTestCaseArgv(test, "This is a string seperated by space", " ");
	addTestCaseArgv(test, "consequtive                  delim?", " ");
	addTestCaseArgv(test, "This is a string seperated by i", "i");
	addTestCaseArgv(test, "This is a string seperated by space and i", " i");
	addTestCaseArgv(test, "mixed consequtive ____ __ ____  ___   _delim?", "_ ");
	addTestCaseArgv(test, "This is a string with no designated delim", "|");
	addTestCaseArgv(test, "This is a string with no designated delim(s)", "\t\r\n\v\f");
	addTestCaseArgv(test, "This is a string full of delim", "angum hdeisrToftl");
	addTestCaseArgv(test, "", "delim");
	addTestCaseArgv(test, "", "");
	addTestCaseArgv(test, "Can you handle empty delim?", "");
	addTestCaseArgv(test, "|what if the middle chunck is full of delim?|", "soundalike cumhftw?");
	addTestCaseArgv(test, "lets see: \1\2\3\4\4\5\6\177, can you see it?", "elysian :,touc?");
	addTestCaseArgv(test, "Destory the unprintables!!! \1\2\3\4\4\5\6\177 Roarr!!", " \1\2\3\4\4\5\6\177");
	addTestCaseArgv(test, "Ratatatatatatatatatata", "a");
	addTestCaseArgv(test, "HahhaHahaaHahhhaaahahahaaHAHAHAAHHaHaHahahHAhaHAAHAHAhAh", "ha");
}