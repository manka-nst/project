#pragma once
#include <iostream>
#include "Ring.h"
#include "sectionDatabase.h"
#include "docDatabase.h"
#include "procedureDatabase.h"
#include "patient.h"
#include <fstream>

template <class T>
class Interface
{
public:
	void menu(Ring<T>& ring);//основное меню работы с данными
	static void setType();//выбор типа данных дл€ работы
	void addMenu(Ring<T>& ring);//меню добавлени€ элемента
	void editMenu(Ring<T>& ring);//меню редактировани€
	void deleteMenu(Ring<T>& ring);//меню удалени€ элемента
	bool read(Ring<T>& ring);//чтение данных из файла
	bool write(Ring<T>& ring);//запись данных в файл
};

int inputNumber(int left_range, int right_range);//валидаци€ ввода целочисленных значений в заданных границах


template <class T>
void Interface<T>::setType()
{
	int choise;
	system("cls");
	do
	{
		std::cout << "-----------------------System of hospital-----------------------\n\n" << std::endl;
		std::cout << "choose type of date:\n1.section\n2.doc\n3.procedure\n4.patients\n0.exit" << std::endl;
		choise = inputNumber(0, 4);
		switch (choise)
		{
		case 1:
		{
			Interface<sectionDatabase> obj;
			Ring<sectionDatabase> tmp;
			obj.menu(tmp);
			break;
		}
		case 2:
		{
			Interface<docDatabase> obj1;
			Ring<docDatabase> tmp;
			obj1.menu(tmp);
			break;
		}
		case 3:
		{
			Interface<procedureDatabase> obj2;
			Ring<procedureDatabase> tmp;
			obj2.menu(tmp);
			break;
		}
		case 4:
		{
			Interface<patient> obj3;
			Ring<patient> tmp;
			obj3.menu(tmp);
			break;
		}
		}
	} while (choise);
}
template <class T>
void Interface<T>::menu(Ring<T>& obj)
{
	Ring<T> ring;
	read(ring);
	T element;
	int choise;
	do
	{
		element.top();
		element.line();
		ring.show_straight();
		std::cout << "\n1 - add\n2 - edit\n3 - delete\n\n0 - back" << std::endl;
		choise = inputNumber(0, 3);
		//std::cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
			this->addMenu(ring);
			break;
		case 2:
			this->editMenu(ring);
			break;
		case 3:
			this->deleteMenu(ring);
			break;
		case 0:
			break;
		}
	} while (choise != 0);
	write(ring);
}

template <class T>
void Interface<T>::addMenu(Ring<T>& obj)
{
	T element;
	std::cout << "\t\t--------------adding--------------" << std::endl;
	std::cin >> element;
	obj.add_begin(element);
}

template <class T>
void Interface<T>::editMenu(Ring<T>& obj)
{
	T element;
	int index;
	system("cls");
	std::cout << "\t\t\t\t--------------redact--------------" << std::endl;
	element.top();
	element.line();
	obj.show_straight();
	std::cout << "object of redacting: \n" << std::endl;
	index = inputNumber(0, obj.getSize() - 1);
	element = obj.getElem(index);
	element.edit();
	obj.del(index);
	obj.add_end(element);
}

template <class T>
void Interface<T>::deleteMenu(Ring<T>& obj)
{
	T element;
	int index;
	std::cout << "\t\t\t\t--------------deleting--------------" << std::endl;
	element.top();
	element.line();
	obj.show_straight();
	std::cout << "object of deleting" << std::endl;
	index = inputNumber(0, obj.getSize() - 1);
	obj.del(index);
}

int inputNumber(int left_range, int right_range)
{
	int number;
	while ((!(std::cin >> number)) || (number < left_range || number > right_range))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "uncorrent, put number from" << left_range << " to " << right_range << std::endl;
	}
	return number;
}

template<class T>
bool Interface<T>::read(Ring<T>& ring)
{
	std::string filename = "file" + T::returnTypeName() + ".txt";
	std::ifstream fin(filename, std::ios::in);
	//fin.open(filename);
	T element;
	//if ((int)fin.eof() != fin.peek() + 1)
	//{
		while (!fin.eof())
		{ 
			element.read(fin);
			ring.add_end(element);
		}
		
	//}
	fin.close();
	ring.del(ring.getSize()-1);
	return true;
}

template<class T>
bool Interface<T>::write(Ring<T>& ring)
{
	std::string filename = "file" + T::returnTypeName() + ".txt";
	std::ofstream fout(filename, std::ios::out);
	//fout.open(filename);
	ring.write(fout);
	fout.close();
	return true;
}

