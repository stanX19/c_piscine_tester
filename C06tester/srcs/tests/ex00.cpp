#include "C06tester.hpp"

void setEx00test(UnitTest &test) {
	test.configure("ex00", 1, true);
	test.addRequiredFile("ft_print_program_name.c");
	test.setExecutableName("This_Is_A_Name_That_You_Prob_Wont_Have_In_The_Cwd");
	test.addTestCase("None", "./This_Is_A_Name_That_You_Prob_Wont_Have_In_The_Cwd\n");
}