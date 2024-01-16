#include "C00tester.hpp"

static std::string ft_print_comb2(void)
{
	std::ostringstream oss;
	char	buf[6] = "00 01";

	while (buf[0] <= '9')
	{
		while (buf[1] <= '9')
		{
			while (buf[3] <= '9')
			{
				while (buf[4] <= '9')
				{
					oss << buf;
					if (!(buf[0] == '9' && buf[1] == '8'))
						oss << ", ";
					buf[4]++;
				}
				buf[4] = '0';
				buf[3]++;
			}
			buf[3] = buf[0];
			buf[4] = buf[1]++ + 2;
		}
		buf[1] = '0';
		buf[0]++;
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