#include "section.h"

void section::get()
{
	std::cout << "name of section: " << name_of_section << std::endl;
}

void section::set()
{
	std::cout << "new name " << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_section);
}

std::ostream& operator<<(std::ostream& os, const section& obj)
{
	os << "|" << std::setw(15) << obj.name_of_section << "|";
	return os;
}

std::istream& operator>>(std::istream& is, section& obj)
{
	std::cout << "name of section" << std::endl;
	std::cin.ignore();
	getline(is, obj.name_of_section);
	return is;
}
