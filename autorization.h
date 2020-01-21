#pragma once
#pragma once
#include "Interface.h"

class user
{
protected:
	std::string login;//логин пользовател€
	std::string password;//пароль пользовател€
public:
	bool autho(std::string, std::string);//функци€ дл€ проверки правильности введенных логина и парол€
	static void openfile();//чтение из файла
	static void closefile();//запись в файл
	static void authorization();//функци€,осуществл€юща€ авторизацию
	void write(std::ofstream& fout);//запись в файл очередного объекта класса
};

const std::string FILE_OF_USERS = "user.txt";
Ring<user> userRing;

void user::openfile()
{
	std::ifstream fin(FILE_OF_USERS, std::ios::in);
	user temp;
	if (((int)fin.eof() != fin.peek() + 1))
	{

		while (!fin.eof())
		{
			fin >> temp.login;
			fin >> temp.password;
			userRing.add_end(temp);
		}
	}
	fin.close();
}

void user::closefile()
{
	std::ofstream fout(FILE_OF_USERS, std::ios::out);
	userRing.write(fout);
	fout.close();
}

void user::authorization()
{
	user::openfile();
	std::string login, password;
	bool power = true;
	do
	{
		system("cls");
		std::cout << "\t\t--------------------------Welcome--------------------------" << std::endl;
		std::cout << "1 - autorize\n0 - exit" << std::endl;
		if (_getch() == '0') return;

		system("cls");
		std::cout << "\t\t--------------------------Autorization--------------------------" << std::endl;
		std::cout << "Login: ";
		std::cin >> login;
		std::cout << "Password: ";
		std::cin >> password;
		if (userRing.authorize(login, password))
		{
			Interface<void>::setType();
			power = false;
		}
		else
		{
			std::cout << "Uncorrect login and password! \n1 - try again\t0 - exit" << std::endl;
			std::cin >> power;
		}
	} while (power);
	user::closefile();
}

bool user::autho(std::string log, std::string pass)
{
	if (login == log)
	{
		if (password == pass)
			return true;
		else return false;
	}
	return false;
}
void user::write(std::ofstream& fout)
{
	fout << login << " " << password << std::endl;
}
