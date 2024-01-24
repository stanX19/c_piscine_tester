#include "C02tester.hpp"

static inline std::string qt("\"");
static inline std::string std_print_mem = "\n"
"static void	ft_puthex(unsigned long long nb, int len)\n"
"{\n"
"	int	temp;\n"
"\n"
"	if (len > 1)\n"
"		ft_puthex(nb / 16, len - 1);\n"
"	temp = nb % 16;\n"
"	if (temp < 10)\n"
"		temp = temp + '0';\n"
"	else\n"
"		temp = temp + 'a' - 10;\n"
"	write(1, &temp, 1);\n"
"}\n"
"\n"
"static void	ft_printhex(char *str, int size)\n"
"{\n"
"	int	i;\n"
"\n"
"	i = 0;\n"
"	while (i < size)\n"
"	{\n"
"		ft_puthex((unsigned char)str[i], 2);\n"
"		if (i % 2 == 1)\n"
"			write(1, \" \", 1);\n"
"		++i;\n"
"	}\n"
"	while (i < 16)\n"
"	{\n"
"		write(1, \"  \", 2);\n"
"		if (i % 2 == 1)\n"
"			write(1, \" \", 1);\n"
"		++i;\n"
"	}\n"
"}\n"
"\n"
"static int	ft_printreadable(char *str, int size)\n"
"{\n"
"	int	i;\n"
"\n"
"	i = 0;\n"
"	while (i < size)\n"
"	{\n"
"		if (str[i] < 32 || str[i] >= 127)\n"
"			write(1, \".\", 1);\n"
"		else\n"
"			write(1, str + i, 1);\n"
"		++i;\n"
"	}\n"
"	return (1);\n"
"}\n"
"\n"
"static void	*std_print_memory(void *addr, unsigned int size)\n"
"{\n"
"	unsigned int	i;\n"
"	int				len;\n"
"\n"
"	i = 0;\n"
"	while (i < size)\n"
"	{\n"
"		if (i + 16 < size)\n"
"			len = 16;\n"
"		else\n"
"			len = size - i;\n"
"		ft_puthex((unsigned long long)addr + i, 16);\n"
"		write(1, \": \", 2);\n"
"		ft_printhex((char *)addr + i, len);\n"
"		ft_printreadable((char *)addr + i, len);\n"
"		write(1, \"\\n\", 1);\n"
"		i += 16;\n"
"	}\n"
"	return (addr);\n"
"}";

UnitTestGenExpected getEx12test() {
	UnitTestGenExpected test("ex12", 5);
	test.addRequiredFile("ft_print_memory.c");
	test.addTemporaryMainFile(
		"void	*ft_print_memory(void *addr, unsigned int size);\n" + 
		std_print_mem,

		"char *ptr1 = std_print_memory(argv[2], atoi(argv[3]));\n"
		"printf(\" Return Index %li\", ptr1 - argv[2]);\n",

		"char *ptr2 = ft_print_memory(argv[2], atoi(argv[3]));\n"
		"printf(\" Return Index %li\", ptr2 - argv[2]);\n"
	);
	test.addTestCase(qt + "hello world" + qt + " 12");
	test.addTestCase(qt + "a b c d e f g h i j k l m n o p q r s t u v w x y z" + qt + " 52");
	test.addTestCase(qt + "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" + qt + " 52");
	test.addTestCase(qt + "ABCDEF GHIJKLMNOP QRSTUV WXYZ" + qt + " 30");
	test.addTestCase(qt + "abc defghij klmnopqr stuvwxyz" + qt + " 30");
	test.addTestCase(qt + qt + " 0");
	test.addTestCase(qt + qt + " 1");
	test.addTestCase(qt + qt + " 16");
	test.addTestCase(qt + qt + " 17");
	test.addTestCase("a 100");
	test.addTestCase("z 100");
	std::string buf;
	std::string buf2;
	for (int i = 1; i <= 33; i++) {
		char c = i;
		std::string str(1, c);
		buf += str;
		buf2 += str + utils::generateRandomString(i % 7);
	}
	for (int i = 125; i <= 255; i++) {
		char c = i;
		std::string str(1, c);
		buf += str;
		buf2 += str + utils::generateRandomString(i % 7);
	}
	test.addTestCase(qt + buf + qt + " 1000");
	test.addTestCase(qt + buf + qt + " 17");
	test.addTestCase(qt + buf + qt + " 0");
	test.addTestCase(qt + buf2 + qt + " 1000");
	test.addTestCase(qt + buf2 + qt + " 26");
	test.addTestCase(qt + buf2 + qt + " 1");
	return test;
}