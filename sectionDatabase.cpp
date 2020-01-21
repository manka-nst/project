#include "sectionDatabase.h"

std::ostream& operator<<(std::ostream& os, const sectionDatabase& obj)
{
	os << "|" << std::setw(15) << obj.name_of_section << "|" << std::setw(15) << obj.zavsection << "|" << std::setw(30) << obj.spisok_doc << "|" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, sectionDatabase& obj)
{
	is >> (section&)obj;
	std::cout << "fio zavedyuschego" << std::endl;
	getline(is, obj.zavsection);
	std::cout << "vvedite list of doc cherez zapyatyu" << std::endl;
	getline(is, obj.spisok_doc);
	return is;
}


void sectionDatabase::get()
{
	std::cout << "name of section: " << name_of_section << std::endl;
	std::cout << "fio zamsection: " << zavsection << std::endl;
	std::cout << "list of doc: " << spisok_doc << std::endl;
}

void sectionDatabase::set()
{
	std::cout << "name of section: " << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_section);
	std::cout << "fio zamsection" << std::endl;
	getline(std::cin, zavsection);
	std::cout << "vvedite list of doc cherez zapyatyu" << std::endl;
	getline(std::cin, spisok_doc);
}

void sectionDatabase::edit()
{
	int power = 1, code;
	do {
		std::cout << "choose parametr dlya izmeneniya: " << std::endl << "1.name of section\n2.fio zavsection\n3.list of doc\n4. all\n0.exit" << std::endl;
		std::cin >> code;
		switch (code)
		{
		case 1:
			changename();
			break;
		case 2:
			changenamezavsection();
			break;
		case 3:
			changespisokdoc();
			break;
		case 4:
			set();
			break;
		case 0:
			power = 0;
			break;
		default:
			std::cout << "uncorrect putting" << std::endl;
			break;
		}
	} while (power);
}

void sectionDatabase::changename()
{
	std::cout << "new section name" << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_section);
}

void sectionDatabase::changenamezavsection()
{
	std::cout << "new fio zavsection" << std::endl;
	std::cin.ignore();
	getline(std::cin, zavsection);
}

void sectionDatabase::changespisokdoc()
{
	std::cout << "vvedite list of doc cherez zapyatyu" << std::endl;
	std::cin.ignore();
	getline(std::cin, spisok_doc);
}

void sectionDatabase::top()
{
	std::cout << "¹ |section        |zavsection     |list of doc                   |" << std::endl;
}

void sectionDatabase::line()
{
	std::cout << "------------------------------------------------------------------" << std::endl;
}

void sectionDatabase::read(std::ifstream& fin)
{
	getline(fin, name_of_section);
	getline(fin, zavsection);
	getline(fin, spisok_doc);
}

void sectionDatabase::write(std::ofstream& fout)
{
	fout << name_of_section << std::endl;
	fout << zavsection << std::endl;
	fout << spisok_doc << std::endl;
}

