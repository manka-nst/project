#pragma once
#include "section.h"

class doc:public section
{
protected:
	std::string name_of_doc;//ФИО врача
	std::string code_of_doc;//код врача
public:
	
	void set();//ввод/изменение данных объекта
	void get();//вывод на экран информации о объекте
	friend std::ostream& operator<<(std::ostream& os, const doc& obj);//перегрузка оператора вывода
	friend std::istream& operator>>(std::istream& is, doc& obj);//перегрузка оператора ввода
};
