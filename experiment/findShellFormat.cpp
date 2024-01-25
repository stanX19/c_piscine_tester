#include "UnitTest.hpp"

int main(void) {
	TemporaryFile result;
	std::vector<unsigned char> normal;
	std::vector<unsigned char> slash;
	std::vector<unsigned char> impossible;

	for (int c = 0; c <= 255; c++) {
		std::string subject(1, (unsigned char)c);

		std::string command1 = "echo '@" + subject + "@' > " + result.filename();
		std::system(command1.c_str());
		if (result.readContent()[0] == '@' && result.readContent()[1] == subject[0] && result.readContent()[2] == '@') {
			std::cout << c << ": normal\n";
			normal.push_back(c);
			continue ;
		}
		std::string command2 = "echo '@\\" + subject + "@' > " + result.filename();
		std::system(command2.c_str());
		if (result.readContent()[0] == '@' && result.readContent()[1] == subject[0] && result.readContent()[2] == '@') {
			std::cout << (int)c << ": slash\n";
			slash.push_back(c);
			continue ;
		}
		std::cout << (int)c << ": impossible\n";
		impossible.push_back(c);
	}
	std::cout << "\nNormal: \n" << std::oct;
	for (unsigned char c : normal) {
		if (c <= 32 || c >= 127)
			std::cout << "\\" << (int)c << " ";
		else
			std::cout << c << " ";
	}
	std::cout << "\nSlash: \n" << std::oct;
	for (unsigned char c : slash) {
		if (c <= 32 || c >= 127)
			std::cout << "\\" << (int)c << " ";
		else
			std::cout << c << " ";
	}
	std::cout << "\nImpossible: \n" << std::oct;
	for (unsigned char c : impossible) {
		if (c <= 32 || c >= 127)
			std::cout << "\\" << (int)c << " ";
		else
			std::cout << c << " ";
	}
	std::cout << '\n';
}