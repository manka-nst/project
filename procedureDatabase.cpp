#include "procedureDatabase.h"

void procedureDatabase::set()
{
	procedure::set();
	std::cout << "put ward" << std::endl;
	getline(std::cin, ward);
	std::cout << "put date" << std::endl;
	getline(std::cin, date);
}

void procedureDatabase::get()
{
	procedure::get();
	std::cout << "ward: " << ward << std::endl;
	std::cout << "date: " << date << std::endl;
}

std::ostream& operator<<(std::ostream& os, const procedureDatabase& obj)
{
	os << (procedure const&)obj << std::setw(10) << obj.date << "|" << std::setw(10) << obj.ward << "|";
	return os;
}

std::istream& operator>>(std::istream& is, procedureDatabase& obj)
{
	is >> (procedure&)obj;
	std::cout << "put ward" << std::endl;
	getline(is, obj.ward);
	std::cout << "put date" << std::endl;
	getline(is, obj.date);
	return is;
}

void procedureDatabase::edit()
{
	bool power = true;
	int code;
	do
	{
		std::cout << "choose parametr for edit: " << std::endl << "1.name of section\n2.name of doc\n3.code of doc\n4. name proc\n5.date\n6.ward\n7.all\n0.back" << std::endl;
		std::cin >> code;
		switch (code)
		{
		case 1:
			changenamesection();
			break;
		case 2:
			changenamespec();
			break;
		case 3:
			changecode();
			break;
		case 4:
			changenameproc();
			break;
		case 5:
			changeward();
			break;
		case 6:
			changedate();
			break;
		case 7:
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

void procedureDatabase::changenamesection()
{
	std::cout << "new name section" << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_section);
}

void procedureDatabase::changenamespec()
{
	std::cout << "new name of doc" << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_doc);
}

void procedureDatabase::changecode()
{
	std::cout << "new kod of doc" << std::endl;
	std::cin.ignore();
	getline(std::cin, code_of_doc);
}

void procedureDatabase::changenameproc()
{
	std::cout << "new name proc" << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_proc);
}

void procedureDatabase::changedate()
{
	std::cout << "new date" << std::endl;
	std::cin.ignore();
	std::cin >> date;
}

void procedureDatabase::changeward()
{
	std::cout << "new ward" << std::endl;
	std::cin.ignore();
	getline(std::cin, ward);
}

void procedureDatabase::top()
{
	std::cout << "¹ |section        |name doc            |code doc|name of proc        |date      |ward      |" << std::endl;
}

void procedureDatabase::line()
{
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
}

void procedureDatabase::read(std::ifstream& fin)
{
	getline(fin, name_of_section);
	getline(fin, name_of_doc);
	getline(fin, code_of_doc);
	getline(fin, name_of_proc);
	getline(fin, ward);
	getline(fin, date);
}

void procedureDatabase::write(std::ofstream& fout)
{
	fout << name_of_section << std::endl;
	fout << name_of_doc << std::endl;
	fout << code_of_doc << std::endl;
	fout << name_of_proc << std::endl;
	fout << ward << std::endl;
	fout << date << std::endl;
}

