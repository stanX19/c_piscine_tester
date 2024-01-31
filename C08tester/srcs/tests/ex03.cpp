#include "C08tester.hpp"

UnitTest getEx03test()  {
	UnitTest test("ex03", 1);
	test.addTemporaryMainFile(
	"#include \"ft_point.h\"\n"
	"void set_point(t_point *point)\n"
	"{\n"
	"	point->x = 42;\n"
	"	point->y = 21;\n"
	"}\n",

	"t_point point;\n"
	"set_point(&point);\n"
	"return (0);\n"
	);
	test.addRequiredFile("ft_point.h");

	return test;
}
