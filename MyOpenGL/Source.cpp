#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
	std::ifstream ifs("C:\\Users\\ymmta\\source\\repos\\MyOpenGL\\MyOpenGL\\a.txt");
	if (ifs.fail()) {
		return 1;
	}
	size_t a;
	ifs.operator>>(a);
};