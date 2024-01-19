#include "C03tester.hpp"

static inline std::string qt("\"");

UnitTest getEx09test() {
	UnitTest test("ex09");
	test.addRequiredFile("ft_strcapitalize.c");
	test.addTemporaryMainFile(
		"char*	ft_strcapitalize(char *str);",
		"printf(\"%s\", ft_strcapitalize(argv[1]));"
	);
	test.addTestCase(qt + "hello world!" + qt, "Hello World!");
	test.addTestCase(qt + "a b c d e f g h i j k l m n o p q r s t u v w x y z" + qt, "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	test.addTestCase(qt + "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" + qt, "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	test.addTestCase(qt + "AB CD EF GH IJ KL MN OP QR ST UV WX YZ" + qt, "Ab Cd Ef Gh Ij Kl Mn Op Qr St Uv Wx Yz");
	test.addTestCase(qt + "ab cd ef gh ij kl mn op qr st uv wx yz" + qt, "Ab Cd Ef Gh Ij Kl Mn Op Qr St Uv Wx Yz");
	test.addTestCase(qt + "A BC DE FG HI JK LM NO PQ RS TU VW XY Z" + qt, "A Bc De Fg Hi Jk Lm No Pq Rs Tu Vw Xy Z");
	test.addTestCase(qt + "a bc de fg hi jk lm no pq rs tu vw xy z" + qt, "A Bc De Fg Hi Jk Lm No Pq Rs Tu Vw Xy Z");
	test.addTestCase(qt + qt, "");
	test.addTestCase("a", "A");
	test.addTestCase("z", "Z");
	test.addTestCase("0123456789", "0123456789");
	test.addTestCase(qt + "0A 1B 2C 3D 4E 5F 6G 7X 8Y 9Z" + qt, "0a 1b 2c 3d 4e 5f 6g 7x 8y 9z");
	test.addTestCase(qt + "0a 1b 2c 3d 4e 5f 6g 7x 8y 9z" + qt, "0a 1b 2c 3d 4e 5f 6g 7x 8y 9z");
	test.addTestCase("\"@AZ[\\`az{\"", "@Az[`Az{");
	test.addTestCase("0A_1B_2C_3D_4E_5F_6G_7X_8Y_9Z", "0a_1b_2c_3d_4e_5f_6g_7x_8y_9z");
	test.addTestCase("a0a_b1b_c2c_d3d_e4e_f5f_g6g_x7x_y8y_z9z", "A0a_B1b_C2c_D3d_E4e_F5f_G6g_X7x_Y8y_Z9z");
	test.addTestCase(qt + "\a\b\t\n\v\f\r\x7F" + qt, "\a\b\t\n\v\f\r\x7F");
	test.addTestCase(qt + "a\ab\bc\td\ne\vf\fg\rh\x7Fi j" + qt, "A\aB\bC\tD\nE\vF\fG\rH\x7FI J");
	return test;
}