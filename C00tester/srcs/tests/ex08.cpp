#include "C00tester.hpp"

void	ft_putout(std::ostringstream &oss, int nb, int *tab, int pos)
{
	int i;

	if (pos == 1)
	{
		oss << ", ";
	}
	i = 0;
	while (i < nb)
	{
		oss << tab[i];
		i++;
	}
}

void	ft_print_combn_increment(int nb, int *tab)
{
	int i;
	int max;

	i = nb - 1;
	max = 9;
	while (tab[i] == max)
	{
		i -= 1;
		max -= 1;
	}
	tab[i] += 1;
	while (i < nb)
	{
		tab[i + 1] = tab[i] + 1;
		i += 1;
	}
}

std::string	ft_print_combn(int nb)
{
	std::ostringstream oss;
	int tab[10];
	int i;

	i = 0;
	while (i < nb)
	{
		tab[i] = i;
		i++;
	}
	ft_putout(oss, nb, tab, 0);
	while (tab[0] != 10 - nb || tab[nb - 1] != 9)
	{
		if (tab[nb - 1] != 9)
		{
			tab[nb - 1] += 1;
		}
		else
		{
			ft_print_combn_increment(nb, tab);
		}
		ft_putout(oss, nb, tab, 1);
	}
	return oss.str();
}

UnitTest getEx08test() {
	std::string name = "ft_print_combn";
	UnitTest test("ex08");
	test.addRequiredFile(name + ".c");
	test.addTemporaryMainFile(
		"void " + name + "(int i);",
		name + "(atoi(argv[1]));"
	);
	for (int i = 1; i < 10; i++)
		test.addTestCase(std::to_string(i), ft_print_combn(i));

	return test;
}