#include "C04tester.hpp"
#include <string.h>

UnitTest getEx05test() {
	UnitTest test("ex05");
	test.addRequiredFile("ft_atoi_base.c");
	test.addTemporaryMainFile(
		"int ft_atoi_base(char *str, char *base);",
		"printf(\"%i\", ft_atoi_base(argv[1], argv[2]));"
	);
	// Basic cases
	test.addTestCase("'123456789' '0123456789'", "123456789");
	test.addTestCase("0 0123456789", "0");
	test.addTestCase("1 0123456789", "1");
	test.addTestCase("-1 0123456789", "-1");
	test.addTestCase("'   12345' '0123456789'", "12345");
	test.addTestCase("'  543.1' '0123456789'", "543");
	test.addTestCase("' 0000000000000000000000000000000000000001' '0123456789'", "1");
	test.addTestCase("       -------------------++--------+++---1 0123456789", "1");
	test.addTestCase("-------------------++--------+++-----+---12 0123456789", "-12");
	test.addTestCase("'   \n\f\r\t\v1234' '0123456789'", "1234");
	test.addTestCase("'   \n\f\r\t\v \n\f\r\t\v4321' '0123456789'", "4321");

	// invalid case
	test.addTestCase("CR ReapeatdChars", "0");
	test.addTestCase("' e' 'Space '", "0");
	test.addTestCase("'1' ''", "0");
	test.addTestCase("A A", "0");
	test.addTestCase("1 '\n1'", "0");
	test.addTestCase("1 '\f1'", "0");
	test.addTestCase("1 '\r1'", "0");
	test.addTestCase("1 '\t1'", "0");
	test.addTestCase("1 '\v1'", "0");
	test.addTestCase("1 ' 1'", "0");
	test.addTestCase("'   123' '\t\n\f\r\v123'", "0");

	// Different bases
	test.addTestCase("1234 01", "1");
	test.addTestCase("Supprised? p?usSerdi", "1636184836");
	test.addTestCase("186A0 0123456789ABCDEF", "100000");
	test.addTestCase("ZZZ 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", "46655");

	// Unprintable bases
	test.addTestCase("'--+--\xFF\xF0---123' '123\xF6\xFF\xF0'", "29");

	// Complex cases
	test.addTestCase("12112122212110202101 012", "2147483647");
	test.addTestCase("-10000000000000000000000000000000 01", "-2147483648");
	test.addTestCase("--1111111111111111111111111111111 01", "2147483647");
	test.addTestCase("-----zyxwv 0123456789ABCDEFGHIJKLMNOPQRTUVWXYZabcdefghijklmnopqrstuvwxyz", "-844361690");  // very long base test
	test.addTestCase(std::string("'\377\376' '\001\002\003\004\005\006\007\010\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037\041\042\043\044\045\046\050\051\052\054\056\057\060\061\062\063\064\065\066\067\070\071\072\073\074\075\076\077\100\101\102\103\104\105\106\107\110\111\112\113\114\115\116\117\120\121\122\123\124\125\126\127\130\131\132\133\134\135\136\137\140\141\142\143\144\145\146\147\150\151\152\153\154\155\156\157\160\161\162\163\164\165\166\167\170\171\172\173\174\175\176\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372\373\374\375\376\377'", 253), "60514");

	return test;
}