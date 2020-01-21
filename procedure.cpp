#include "procedure.h"

void procedure::set()
{
	doc::set();
	std::cout << "put name of proc" << std::endl;
	getline(std::cin, name_of_proc);
}

void procedure::get()
{
	doc::get();
	std::cout << "name of proc: " << name_of_proc << std::endl;
}

std::ostream& operator<<(std::ostream& os, const procedure& obj)
{
	os << (doc const&)obj << std::setw(20) << obj.name_of_proc << "|";
	return os;
}

std::istream& operator>>(std::istream& is, procedure& obj)
{
	is >> (doc&)obj;
	std::cout << "put name of proc" << std::endl;
	getline(is, obj.name_of_proc);
	return is;
}
