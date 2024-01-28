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
	test.addTestCase(std::string("2147483647 '\001\002\003\004\005\006\007\010\011\012\013\014\015\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037\040\041\042\043\044\045\046\050\051\052\054\056\057\060\061\062\063\064\065\066\067\070\071\072\073\074\075\076\077\100\101\102\103\104\105\106\107\110\111\112\113\114\115\116\117\120\121\122\123\124\125\126\127\130\131\132\133\134\135\136\137\140\141\142\143\144\145\146\147\150\151\152\153\154\155\156\157\160\161\162\163\164\165\166\167\170\171\172\173\174\175\176\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372\373\374\375\376\377'", 265), "\2124\204\203");
	return test;
}