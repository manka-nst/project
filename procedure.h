
#include "doc.h"

class procedure :public doc
{
protected:
	std::string name_of_proc;//название процедуры
public:
	void set();//ввод/изменение данных объекта
	void get();//вывод на экран информации о объекте
	friend std::ostream& operator<<(std::ostream& os, const procedure& obj);//перегрузка оператора вывода
	friend std::istream& operator>>(std::istream& is, procedure& obj);//перегрузка оператора ввода
};
#pragma once
