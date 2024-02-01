#include "C08tester.hpp"

static void addTestCaseArgv(UnitTest &test, const char *argv) {
	std::istringstream iss(argv);
	std::ostringstream oss_out;
	std::ostringstream oss_in;
	std::string arg;
	int idx = 0;
	while (iss >> arg) {
		oss_out << arg << "\n" << arg.size() << "\n" << arg << "\n";
		oss_in << "'" << arg << "' ";
		idx++;
	}
	test.addTestCase(oss_in.str(), oss_out.str());
}

UnitTest getEx05test() {
	UnitTest test("ex05", 1, true);
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
	test.addTemporaryCodeFile(
		"#include \"ft_stock_str.h\"\n"
		"\n"
		"struct s_stock_str	*argv_to_tab(int ac, char **av, t_stock_str *c)\n"
		"{\n"
		"	int			i;\n"
		"\n"
		"	ac--;\n"
		"	av++;\n"
		"	i = -1;\n"
		"	if (c == NULL)\n"
		"		return (NULL);\n"
		"	while (++i < ac)\n"
		"	{\n"
		"		c[i].size = strlen(av[i]);\n"
		"		c[i].str = av[i];\n"
		"		c[i].copy = av[i];\n"
		"	}\n"
		"	c[i].str = 0;\n"
		"	return (c);\n"
		"}\n"
	);
	test.addRequiredFile("ft_show_tab.c");
	test.addTemporaryMainFile(
		"#include \"ft_stock_str.h\"\n"
		"struct s_stock_str	*argv_to_tab(int ac, char **av, t_stock_str *c);\n"
		"void	ft_show_tab(struct s_stock_str *par);\n",

		"t_stock_str c[100];\n"
		"argv_to_tab(argc, argv, c);\n"
		"ft_show_tab(c);\n"
	);
	addTestCaseArgv(test, "str1 str2 str3 str4");
	addTestCaseArgv(test, "OneWord");
	addTestCaseArgv(test, "C h");
	test.addTestCase("", "");
	test.addTestCase("''", "\n0\n\n");
	addTestCaseArgv(test, "OuchhhHHHHHHHHHHHHHHH");
	addTestCaseArgv(test, "\277\2\3 \4\5\200");

	return test;
}
