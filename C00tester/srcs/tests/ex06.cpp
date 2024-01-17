#include "C00tester.hpp"

static std::string ft_print_comb2(void)
{
	std::ostringstream oss;
    int    i;
    int    j;

    i = 0;
    j = 1;
    while (i <= 98)
    {
        j = i + 1;
        while (j <= 99)
        {
            oss << (i / 10)
            	<< (i % 10)
            	<< " "
       		 	<< (j / 10)
            	<< (j % 10);
            if (i != 98 || j != 99)
            {
                oss << ", ";
            }
            j++;
        }
        i++;
    }
	return oss.str();
}

UnitTest getEx06test() {
	std::string name = "ft_print_comb2";
	UnitTest test("ex06");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(void);",
		name + "();"
	);
	test.addTestCase("None", ft_print_comb2());
	return test;
}