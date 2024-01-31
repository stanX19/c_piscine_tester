#include "C08tester.hpp"

void setEx01test(UnitTest &test)  {
	test.configure("ex01", 1);
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
	"}\n"
	);
	test.addRequiredFile("ft_boolean.h");

	test.addTestCase("None", "ft_putchar ran; ft_swap ran; ft_putstr ran; ft_strlen ran; ft_strcmp ran; ");
}
