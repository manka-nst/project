#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>


template <class T>
struct Struct
{
	T value;//информационная часть
	Struct* next;//указатель на следующий элемент
	Struct* prev;//указатель на предыдущий элемент
};

template <class T>
class Ring
{
protected:
	Struct<T>* first;//указатель на первый элемент
	Struct<T>* last;//указатель на последний элемент
	int size;//размер кольца
	Struct<T>* getElement(int pos);//получения указателя на элемент с индексом pos
public:
	Ring();//конструктор по умолчанию
	~Ring();//деструктор
	void show_straight();//вывод кольца на экран с начала
	void show_reverse();//вывод кольца на экран с конца
	void add_begin(T Value);//добавление элемента в начало кольца
	void add_end(T Value);//добавление элемента в конец кольца
	void del_begin();//удаление первого элемента кольца
	void del_end();//удаление последнего элемента кольца
	void del(int pos);//удаление элемента с индексом pos
	int getSize();//получение размера кольца
	void clear();//очистка кольца
	T& operator[](int pos);//перегрузка оператора индексирования
	T& getElem(int pos);//получения информационной части элемента с индексом pos
	Ring& operator=(const Ring<T>& object);//перегрузка оператора присваивания
	void write(std::ofstream& fout);//запись в файл
	bool authorize(std::string, std::string);//авторизация
};

template <class T>
Ring<T>& Ring<T>::operator=(const Ring& object)
{
	if (first) clear();
	for (int i = 0; i < object.getSize(); i++)
	{
		add_end(object[i]);
	}
	return *this;
}

template <class T>
Struct<T>* Ring<T>::getElement(int pos)
{
	Struct<T>* temp;
	temp = first;
	for (int i = 0; i < pos; i++)
		temp = temp->next;
	return temp;
}

template <class T>
Ring<T>::Ring()
{
	first = NULL;
	last = NULL;
	size = 0;
}
template<class T>
Ring<T>::~Ring()
{
	while (first != last)
	{
		Struct<T>* temp = first;
		first = first->prev;
		delete temp;
	}
	delete last;
}

template<class T>
void Ring<T>::show_straight()
{
	int number = 0;
	Struct<T>* temp = first;
	do
	{
		std::cout << number << ")" << temp->value << std::endl;
		temp = temp->next;
		number++;
	} while (temp != first);
}

template<class T>
void Ring<T>::show_reverse()
{
	int number = size - 1;
	Struct<T>* temp = last;
	if (last)
		do
		{
			std::cout << temp->value;
			temp = temp->prev;
		} while (temp != last);
}

template<class T>
void Ring<T>::add_begin(T Value)
{
	Struct<T>* temp = new Struct<T>;
	temp->value = Value;
	if (first)
	{
		temp->next = first;
		first->prev = last->next = temp;
		temp->prev = last;
		first = temp;
	}
	else
	{
		first = last = temp;
		first->next = first->prev = last;
		last->next = last->prev = first;
	}
	++size;
}

template<class T>
void Ring<T>::add_end(T Value)
{
	Struct<T>* temp = new Struct<T>;
	temp->value = Value;
	if (last)
	{
		temp->prev = last;
		last->next = first->prev = temp;
		temp->next = first;
		last = temp;
	}
	else
	{
		first = last = temp;
		first->next = first->prev = last;
		last->next = last->prev = first;
	}
	++size;
}

template<class T>
void Ring<T>::del_begin()
{
	del(0);
}

template<class T>
void Ring<T>::del_end()
{
	assert(size > 0);
	del(size);
}

template<class T>
void Ring<T>::del(int pos)
{
	if (!first) return;
	Struct<T>* temp = getElement(pos);
	if (temp->next == temp) first = last = NULL;
	else
	{
		if (temp == last) last = last->next;
		if (temp == first) first = first->prev;
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
	}
	--size;
}

template<class T>
int Ring<T>::getSize()
{
	return size;
}

template<class T>
void Ring<T>::clear()
{
	while (first->prev != last)
	{
		Struct<T>* temp = first->prev;
		first = first->prev;
		delete temp;
	}
	last = NULL;
	first = NULL;
	std::cout << "Ring cleaned" << std::endl;
}

template<class T>
T& Ring<T>::operator[](int pos)
{
	if (!first)
	{
		T empty;
		return empty;
	}
	return (getElement(pos))->value;
}

template <class T>
T& Ring<T>::getElem(int pos)
{
	Struct<T>* temp;
	temp = first;
	for (int i = 0; i < pos; i++)
		temp = temp->next;
	return temp->value;
}

template <class T>
void Ring<T>::write(std::ofstream& fout)
{
	Struct<T>* temp;
	temp = first;
	for (int i =0;i<getSize();i++)
	{
		temp->value.write(fout);
		temp = temp->next;
	}
}

template <class T>
bool Ring<T>::authorize(std::string login, std::string password)
{
	Struct<T>* temp = first;
	do
	{
		if (temp->value.autho(login, password))
			return true;
		temp = temp->next;
	} while (temp != first);
	return false;
}
