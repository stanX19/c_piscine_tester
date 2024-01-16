#include "C00tester.hpp"

static std::string	ft_print_comb(void)
{
	std::ostringstream oss;
	char	i;
	char	j;
	char	k;

	i = '2';
	j = '1';
	k = '0';
	while (k <= '9')
	{
		while (j <= '9')
		{
			while (i <= '9')
			{
				oss << k << j << i;
				if (k != '7')
					oss << ", ";
				i++;
			}
			i = j++ + 2;
		}
		j = k++ + 1;
	}
	return oss.str();
}

UnitTest getEx05test() {
	std::string name = "ft_print_comb";
	UnitTest test("ex05");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(void);",
		name + "();"
	);
	test.addTestCase("None", ft_print_comb());
	return test;
}