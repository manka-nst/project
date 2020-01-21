#include "patient.h"

void patient::set()
{
	procedure::set();
	std::cout << "put fio stud" << std::endl;
	getline(std::cin, FIO);
	std::cout << "put date of birth" << std::endl;
	getline(std::cin, date_of_birth);
	std::cout << "put city" << std::endl;
	getline(std::cin, city);
	std::cout << "put sex" << std::endl;
	getline(std::cin, sex);
	std::cout << "put phone" << std::endl;
	getline(std::cin, phone);
	std::cout << "put datepos" << std::endl;
	getline(std::cin, datepos);
	std::cout << "put illnes" << std::endl;
	getline(std::cin, illnes);
	std::cout << "put card" << std::endl;
	getline(std::cin, card);
}

void patient::get()
{
	procedure::get();
	std::cout << "fio: " << FIO << std::endl;
	std::cout << "city: " << city << std::endl;
	std::cout << "city: " << city << std::endl;
	std::cout << "sex: " << sex << std::endl;
	std::cout << "phone: " << phone << std::endl;
	std::cout << "datepos: " << datepos << std::endl;
	std::cout << "illnes: " << illnes << std::endl;
	std::cout << "card: " << card << std::endl;
}

std::ostream& operator<<(std::ostream& os, const patient& obj)
{
	os << (procedure const&)obj << std::setw(15) << obj.FIO << "|" << std::setw(10) << obj.date_of_birth << "|" << std::setw(12) << obj.city << "|"
		<< std::setw(3) << obj.sex << "|" << std::setw(7) << obj.phone << "|" << std::setw(10) << obj.datepos << "|" << std::setw(10) << obj.illnes << "|"
		<< std::setw(4) << obj.card << "|";
	return os;
}

std::istream& operator>>(std::istream& is, patient& obj)
{
	is >> (procedure&)obj;
	std::cout << "put fio" << std::endl;
	getline(is, obj.FIO);
	std::cout << "put date birth" << std::endl;
	getline(is, obj.date_of_birth);
	std::cout << "put city" << std::endl;
	getline(is, obj.city);
	std::cout << "put sex" << std::endl;
	getline(is, obj.sex);
	std::cout << "put phone" << std::endl;
	getline(is, obj.phone);
	std::cout << "put datepos" << std::endl;
	getline(is, obj.datepos);
	std::cout << "put illnes" << std::endl;
	getline(is, obj.illnes);
	std::cout << "put card" << std::endl;
	getline(is, obj.card);
	return is;
}

void patient::edit()
{
	bool power = true;
	int code;
	do
	{
		std::cout << "choose parametr of change: " << std::endl << "1.section\n2.name doc\n3.code doc\n4. name proc\n5.fio\n6.date of birth\n7.city\n8.sex\n9.phone\n10.datepos\n11.illnes\n12.card\n13.all\n0.back" << std::endl;
		std::cin >> code;
		switch (code)
		{
		case 1:
			changenamesection();
			break;
		case 2:
			changenamedoc();
			break;
		case 3:
			changecode();
			break;
		case 4:
			changenameproc();
			break;
		case 5:
			changeFIO();
			break;
		case 6:
			changeDateOfBirth();
			break;
		case 7:
			changecity();
			break;
		case 8:
			changesex();
			break;
		case 9:
			changephone();
			break;
		case 10:
			changedatepos();
			break;
		case 11:
			changeillnes();
			break;
		case 12:
			changecard();
			break;
		case 13:
			set();
			break;
		case 0:
			power = false;
			break;
		default:
			std::cout << "uncorrect putting" << std::endl;
			break;
		}
	} while (power);
}

void patient::changenamesection()
{
	std::cout << "put new section" << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_section);
}

void patient::changenamedoc()
{
	std::cout << "put new doc" << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_doc);
}

void patient::changecode()
{
	std::cout << "put new kod" << std::endl;
	std::cin.ignore();
	getline(std::cin, code_of_doc);
}

void patient::changenameproc()
{
	std::cout << "put new name proc" << std::endl;
	std::cin.ignore();
	getline(std::cin, name_of_proc);
}

void patient::changeFIO()
{
	std::cout << "put new fio" << std::endl;
	std::cin.ignore();
	getline(std::cin, FIO);
}

void patient::changeDateOfBirth()
{
	std::cout << "put new birthday" << std::endl;
	std::cin.ignore();
	getline(std::cin, date_of_birth);
}

void patient::changecity()
{
	std::cout << "put new city" << std::endl;
	std::cin.ignore();
	getline(std::cin, city);
}

void patient::changesex()
{
	std::cout << "put new sex" << std::endl;
	std::cin.ignore();
	getline(std::cin, sex);
}

void patient::changephone()
{
	std::cout << "put new kurs" << std::endl;
	getline(std::cin, phone);
}

void patient::changedatepos()
{
	std::cout << "put datepos" << std::endl;
	getline(std::cin, datepos);
}

void patient::changeillnes()
{
	std::cout << "put illnes" << std::endl;
	getline(std::cin, illnes);
}

void patient::changecard()
{
	std::cout << "put new card" << std::endl;
	getline(std::cin, card);
}

void patient::top()
{
	std::cout << "¹ |section        |name doc            |code doc|name proc           |fio            |birthday  |city        |sex|phone  |datepos   |illness   |card|" << std::endl;
}

void patient::line()
{
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void patient::read(std::ifstream& fin)
{
	getline(fin, name_of_section);
	getline(fin, name_of_doc);
	getline(fin, code_of_doc);
	getline(fin, name_of_proc);
	getline(fin, FIO);
	getline(fin, date_of_birth);
	getline(fin, city);
	getline(fin, sex);
	getline(fin, phone);
	getline(fin, datepos);
	getline(fin, illnes);
	getline(fin, card);
}

void patient::write(std::ofstream& fout)
{
	fout << name_of_section << std::endl;
	fout << name_of_doc << std::endl;
	fout << code_of_doc << std::endl;
	fout << name_of_proc << std::endl;
	fout << FIO << std::endl;
	fout << date_of_birth << std::endl;
	fout << city << std::endl;
	fout << sex << std::endl;
	fout << phone << std::endl;
	fout << datepos << std::endl;
	fout << illnes << std::endl;
	fout << card << std::endl;
}
