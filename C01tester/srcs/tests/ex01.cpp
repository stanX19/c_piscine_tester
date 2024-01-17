#include "C01tester.hpp"

UnitTest getEx01test() {
	UnitTest test("ex01");
	test.addRequiredFile("ft_ultimate_ft.c");
	test.addTemporaryMainFile(
		"void	ft_ultimate_ft(int *********nbr);",
		"int nbr = atoi(argv[1]);"
		"int *ptr1 = &nbr;"
		"int **ptr2 = &ptr1;"
		"int ***ptr3 = &ptr2;"
		"int ****ptr4 = &ptr3;"
		"int *****ptr5 = &ptr4;"
		"int ******ptr6 = &ptr5;"
		"int *******ptr7 = &ptr6;"
		"int ********ptr8 = &ptr7;"
		"int *********ptr9 = &ptr8;"
		"ft_ultimate_ft(ptr9);"
		"printf(\"%i\", nbr);"
	);
	for (char c = '0'; c <= '9'; c++)
		test.addTestCase(std::string(1, c), "42");
	return test;
}
