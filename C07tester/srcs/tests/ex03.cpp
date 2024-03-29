#include "C07tester.hpp"

static void addTestCaseArgv(UnitTest &test, std::string str, std::string sep) {
	std::istringstream iss(str);
	std::ostringstream out_oss;
	std::ostringstream in_oss;
	std::string buf;
	std::vector<std::string> strs;
	while(iss >> buf) {
		in_oss << "'" + buf + "' ";
		strs.push_back(buf);
	}
	for (int i = 0; i < (int)strs.size(); i++)
	{
		out_oss << strs[i];
		if (i != ((int)strs.size()) - 1)
			out_oss << sep;
	}
	test.addTestCase(in_oss.str() + " '" + sep + "'", out_oss.str());
}

UnitTest getEx03test() {
	UnitTest test("ex03", 1);
	test.addRequiredFile("ft_strjoin.c");
	test.addTemporaryMainFile(
		"char	*ft_strjoin(int size, char **strs, char *sep);",
		"char **strs = argv + 1;"
		"int size = argc - 2;"
		"char *ret = ft_strjoin(size, strs, argv[argc - 1]);"
		"printf(\"%s\", ret);"
		"free(ret);"
	);
	addTestCaseArgv(test, "this is a string, you should seperate it by space", " ");
	addTestCaseArgv(test, "Size1", "|");
	addTestCaseArgv(test, "All Of This Should Stick Together", "");
	addTestCaseArgv(test, "Very long sep", "---------------------------------------------------------------------------------------------------------------------------------------------");
	test.addTestCase("'' '' '' '' 'XoX'", "XoXXoXXoX");
	addTestCaseArgv(test, "OneVeryLongStringggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg", "Sep");
	addTestCaseArgv(test, "A B C D E F G H I J K L M N I O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L M N I O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9", ".");
	return test;
}