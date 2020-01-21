#include "doc.h"

void doc::get()
{
	section::get();
	std::cout << "name of doc: " << name_of_doc << std::endl;
	std::cout << "code doc: " << code_of_doc << std::endl;
}

void doc::set()
{
	section::set();
	std::cout << "put name doc" << std::endl;
	getline(std::cin, name_of_doc);
	std::cout << "put kod doc" << std::endl;
	getline(std::cin, code_of_doc);
}

std::ostream& operator<<(std::ostream& os, const doc& obj)
{
	os << (section const&)obj << std::setw(20) << obj.name_of_doc << "|" << std::setw(8) << obj.code_of_doc << "|";
	return os;
}

std::istream& operator>>(std::istream& is, doc& obj)
{
	is >> (section&)obj;
	std::cout << "put name doc" << std::endl;
	std::cin.ignore();
	getline(is, obj.name_of_doc);
	std::cout << "put kod doc" << std::endl;
	getline(is, obj.code_of_doc);
	return is;
}
