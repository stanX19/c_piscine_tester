#include "C04tester.hpp"

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
	test.addTestCase("1 poneyvif", std_putnbr_base(1, "poneyvif"));
	test.addTestCase("-1 KMNOP", std_putnbr_base(-1, "KMNOP"));
	test.addTestCase("2 01", std_putnbr_base(2, "01"));
	test.addTestCase("-2 0123456789", std_putnbr_base(-2, "0123456789"));
	test.addTestCase("0 Zero?", "Z");
	test.addTestCase("-2147483648 0123456789", "-2147483648");
	test.addTestCase("2147483647 0123456789", "2147483647");
	test.addTestCase("2000000000 ZTc", std_putnbr_base(2000000000, "ZTc"));
	test.addTestCase("2000000000 0123456789ABCDEF", std_putnbr_base(2000000000, "0123456789ABCDEF"));
	test.addTestCase("2000000000 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", std_putnbr_base(2000000000, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	test.addTestCase("42 InvalidBase", "");
	test.addTestCase("42 @", "");
	test.addTestCase("42 \"\"", "");
	test.addTestCase("42 -Signed?", "");
	test.addTestCase("42 +Signed?", "");
	test.addTestCase("42 Back?+", "");
	test.addTestCase("42 BackNeg?-", "");
	test.addTestCase("1000000 MiLlIoN!", std_putnbr_base(1000000, "MiLlIoN!"));
	test.addTestCase("1636184836 p?usSerdi", "Supprised?");
	test.addTestCase("89676 \"Genius AIm\"", "Im A ");
	std::string base;
	for (int i = 1; i <= 33; i++) {
		char c = i;
		std::string str(1, c);
		base += str;
	}
	test.addTestCase("2147483647 " + qt + base + qt, std_putnbr_base(2147483647, base.c_str()));
	return test;
}