#include "C04tester.hpp"
#include <string.h>
static std::string qt("\"", 1);

static std::ostringstream oss;

static void	ft_putchar(char c)
{
	oss << c;
}

static int	find_base(const char *base)
{
	int		i;
	char	hash[256];

	i = 0;
	while (i < 256)
		hash[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (hash[(int)base[i]])
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		hash[(int)base[i]] = 1;
		++i;
	}
	return (i);
}

static void	ft_putnbr_base(int nbr, const char *base)
{
	int				i;
	unsigned int	u_nbr;

	i = find_base(base);
	if (i < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		u_nbr = -1 * nbr;
	}
	else
		u_nbr = nbr;
	if (u_nbr >= (unsigned int)i)
		ft_putnbr_base(u_nbr / i, base);
	ft_putchar(base[u_nbr % i]);
}

static std::string std_putnbr_base(int nb, const char *base) {
	oss.str(std::string());
	ft_putnbr_base(nb, base);
	return oss.str();
}

UnitTest getEx04test() {
	UnitTest test("ex04");
	test.addRequiredFile("ft_putnbr_base.c");
	test.addTemporaryMainFile(
		"void ft_putnbr_base(int nb, char *base);",
		"ft_putnbr_base(atoi(argv[1]), argv[2]);"
	);

	for (int i = -10; i <= 10; i++)
	{
		test.addTestCase(std::to_string(i) + " 0123456789", std_putnbr_base(i, "0123456789"));
		test.addTestCase(std::to_string(i) + " poneyvif", std_putnbr_base(i, "poneyvif"));
		test.addTestCase(std::to_string(i) + " KMNOP", std_putnbr_base(i, "KMNOP"));
		test.addTestCase(std::to_string(i) + " 01", std_putnbr_base(i, "01"));
	}
	test.addTestCase("-2147483648 0123456789", "-2147483648");
	test.addTestCase("2147483647 0123456789", "2147483647");
	for (int i = 2000000000; i <= 2000000002; i++)
	{
		test.addTestCase(std::to_string(i) + " ZTc", std_putnbr_base(i, "ZTc"));
		test.addTestCase(std::to_string(i) + " 0123456789ABCDEF", std_putnbr_base(i, "0123456789ABCDEF"));
		test.addTestCase(std::to_string(i) + " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", std_putnbr_base(i, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	}
	test.addTestCase("42 InvalidBase", std_putnbr_base(42, "InvalidBase"));
	test.addTestCase("-42 -Signed?", std_putnbr_base(-42, "-Signed?"));
	test.addTestCase("+42 +Signed?", std_putnbr_base(42, "+Signed?"));
	test.addTestCase("42 Backw4rds?+", std_putnbr_base(42, "Backw4rds?+"));
	test.addTestCase("42 Backw4rdsNeg?-", std_putnbr_base(42, "Backw4rdsNeg?-"));
	test.addTestCase("0 Zero?", std_putnbr_base(0, "Zero?"));
	test.addTestCase("100 Zero!", std_putnbr_base(100, "Zero!"));
	test.addTestCase("10 @", std_putnbr_base(10, "@"));
	test.addTestCase("10 \"\"", std_putnbr_base(10, ""));
	std::string base;
	for (int i = 1; i <= 33; i++) {
		char c = i;
		std::string str(1, c);
		base += str;
	}
	test.addTestCase("2147483647 " + qt + base + qt, std_putnbr_base(2147483647, base.c_str()));
	return test;
}