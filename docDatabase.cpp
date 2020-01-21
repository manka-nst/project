#include "docDatabase.h"

void docDatabase::set()
{
	doc::set();
	std::cout << "new stage" << std::endl;
	getline(std::cin, stage);
}

void docDatabase::get()
{
	doc::get();
	std::cout << "stage: " << stage << std::endl;
}

std::ostream& operator<<(std::ostream& os, const docDatabase& obj)
{
	os << (doc const&)obj << std::setw(8) << obj.stage << "|";
	return os;
}

std::istream& operator>>(std::istream& is, docDatabase& obj)
{
	is >> (doc&)obj;
	std::cout << "put stage" << std::endl;
	getline(is, obj.stage);
	return is;
}

void docDatabase::edit()
{
	bool power = true;
	int code;
	do
	{
		std::cout << "put parametr for edit: " << std::endl << "1.name section\n2.name doc\n3.code doc\n4. stage\n5.all\n0.exit" << std::endl;
		std::cin >> code;
		switch (code)
		{
		case 1:
			changenamecaf();
			break;
		case 2:
			changenamespec();
			break;
		case 3:
			changecode();
			break;
		case 4:
			changestage();
			break;
		case 5:
			set();
		case 0:
			power = false;
			break;
		default:
			std::cout << "uncorrect putting" << std::endl;
			break;
		}
	} while (power);
}

void docDatabase::changenamecaf()
{
	std::cout << " put new section name" << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_section);
}

void docDatabase::changenamespec()
{
	std::cout << "put new doc name" << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_doc);
}

void docDatabase::changecode()
{
	std::cout << "put new code doc" << std::endl;
	std::cin.ignore();
	getline(std::cin, code_of_doc);
}

void docDatabase::changestage()
{
	std::cout << "put new stage" << std::endl;
	std::cin.ignore();
	getline(std::cin, stage);
}

void docDatabase::top()
{
	std::cout << "¹ |section        |name doc            |code doc|stage   |" << std::endl;
}

void docDatabase::line()
{
	std::cout << "----------------------------------------------------------" << std::endl;
}

void docDatabase::read(std::ifstream& fin)
{
	getline(fin, name_of_section);
	getline(fin, name_of_doc);
	getline(fin, code_of_doc);
	getline(fin, stage);
}

void docDatabase::write(std::ofstream& fout)
{
	fout << name_of_section << std::endl;
	fout << name_of_doc << std::endl;
	fout << code_of_doc << std::endl;
	fout << stage << std::endl;
}
