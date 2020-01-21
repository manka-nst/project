#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
class section
{
protected:
	std::string name_of_section;//название отделения
public:
	void get();//вывод на экран информации о объекте
	void set();//ввод/изменение данных объекта
	friend std::ostream& operator<<(std::ostream& os, const section& obj);//перегрузка оператора вывода
	friend std::istream& operator>>(std::istream& is, section& obj);//перегрузка оператора ввода
};
