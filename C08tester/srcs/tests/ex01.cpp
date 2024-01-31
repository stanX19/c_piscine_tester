#include "C08tester.hpp"

void setEx01test(UnitTest &test)  {
	test.configure("ex01", 1, true);
	test.addTemporaryMainFile(
	"#include \"ft_boolean.h\"\n"
	"\n"
	"void ft_putstr(char *str)\n"
	"{\n"
	"	while (*str)\n"
	"	write(1, str++, 1);\n"
	"}\n"
	"t_bool ft_is_even(int nbr)\n"
	"{\n"
	"	return ((EVEN(nbr)) ? TRUE : FALSE);\n"
	"}\n",

	"if (ft_is_even(argc - 1) == TRUE)\n"
	"	ft_putstr(EVEN_MSG);\n"
	"else\n"
	"	ft_putstr(ODD_MSG);\n"
	"return (SUCCESS);\n"
	);
	test.addRequiredFile("ft_boolean.h");
	test.addTestCase("One Two Three", "I have an odd number of arguments.\n");
	test.addTestCase("One Two Three Four", "I have an even number of arguments.\n");
}
