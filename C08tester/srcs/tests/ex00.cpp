#include "C08tester.hpp"

UnitTest getEx00test()  {
	UnitTest test("ex00", 1);
	test.addTemporaryMainFile(
		"#include \"ft.h\"",
		"ft_putchar('c');"
		"ft_swap(0, 0);"
		"ft_putstr(0);"
		"ft_strlen(0);"
		"ft_strcmp(0, 0);"
	);
	test.addRequiredFile("ft.h");
	test.addTemporaryCodeFile("void ft_putchar(char c) { (void)c; printf(\"ft_putchar ok; \"); }");
	test.addTemporaryCodeFile("void	ft_swap(int *a, int *b) { (void)a; (void)b; printf(\"ft_swap ok; \"); }");
	test.addTemporaryCodeFile("void	ft_putstr(char *str) { (void)str; printf(\"ft_putstr ok; \"); }");
	test.addTemporaryCodeFile("int ft_strlen(char *str) { (void)str; printf(\"ft_strlen ok; \"); return 0; }");
	test.addTemporaryCodeFile("int ft_strcmp(char *str) { (void)str; printf(\"ft_strcmp ok; \"); return 0; }");

	test.addTestCase("None", "ft_putchar ok; ft_swap ok; ft_putstr ok; ft_strlen ok; ft_strcmp ok; ");

	return test;
}
