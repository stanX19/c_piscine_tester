#include "C08tester.hpp"

static void addTestCaseArgv(UnitTest &test, const char *argv) {
	std::istringstream iss(argv);
	std::ostringstream oss_out;
	std::ostringstream oss_in;
	std::string arg;
	int idx = 0;
	while (iss >> arg) {
		oss_out << "stocks[" << idx << "]: [" << arg.size() << ", \"" << arg << "\", \"" << arg << "\"]\n";
		oss_in << "'" << arg << "' ";
		idx++;
	}
	if (oss_out.str().empty())
		oss_out << "NULL";
	else
		oss_out << "stocks[" << idx << "]: NULL";
	test.addTestCase(oss_in.str(), oss_out.str());
}

void setEx04test(UnitTest &test) {
	test.configure("ex04", 1, true);
	test.addRequiredFile("ft_strs_to_tab.c");
		test.addTemporaryMainFile(
		"#include \"ft_stock_str.h\"\n",

		"struct s_stock_str *ret = ft_strs_to_tab(argc - 1, argv + 1);"
		"if (ret == 0) {"
		"	printf(\"NULL\");"
		"	return 0;"
		"}"
		"int i = 0;"
		"while(1) {"
		"	if (ret[i].str != 0) {"
		"		printf(\"stocks[%i]: [%i, \\\"%s\\\", \\\"%s\\\"]\\n\", i, ret[i].size, ret[i].str, ret[i].copy);"
		"		free(ret[i].copy);"
		"	} else {"
		"		printf(\"stocks[%i]: NULL\", i);"
		"		break ;"
		"	}"
		"	++i;"
		"}"
		"free(ret);"
	);
	test.addTemporaryHeaderFile(
		"#ifndef FT_STOCK_STR_H\n"
		"# define FT_STOCK_STR_H\n"
		"# include <stdlib.h>\n"
		"typedef struct s_stock_str\n"
		"{\n"
		"	int        size;\n"
		"	char    *str;\n"
		"	char    *copy;\n"
		"}            t_stock_str;\n"
		"int            ft_strlen(char *str);\n"
		"char        *ft_strdup(char *str, int size);\n"
		"t_stock_str    *ft_strs_to_tab(int ac, char **av);\n"
		"#endif\n",

		"ft_stock_str.h"
	);

	addTestCaseArgv(test, "This is the basic test string");
	addTestCaseArgv(test, "OneWord");
	addTestCaseArgv(test, "C h a r");
	test.addTestCase("", "stocks[0]: NULL");
	test.addTestCase("''", "stocks[0]: [0, \"\", \"\"]\nstocks[1]: NULL");
	addTestCaseArgv(test, "OuchhhHHHHHHHHHHHHHHH");
	addTestCaseArgv(test, "\277 \2 \3 \4 \5 \200");
}
