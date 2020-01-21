#pragma once
#include "doc.h"

class docDatabase :public doc
{
protected:
	std::string stage;//стаж врача
public:
	void set();//ввод/изменение данных объекта
	void get();//вывод на экран информации о объекте
	docDatabase()//конструктор по умолчанию
	{
		name_of_section = "no info";
		name_of_doc = "no info";
		code_of_doc = "no info";
		stage = "no info";
	}
	friend std::ostream& operator<<(std::ostream& os, const docDatabase& obj);//перегрузка оператора вывода
	friend std::istream& operator>>(std::istream& is, docDatabase& obj);//перегрузка оператора ввода
	void edit();//редактирование данных
	void changenamecaf();//изменение названия отделения
	void changenamespec();//изменение ФИО врача
	void changecode();//изменение кода врача
	void changestage();//изменение стажа врача
	void top();//вывод шапки таблицы
	void line();//вывод разделяющей линии
	void read(std::ifstream& fin);//чтение из файла
	void write(std::ofstream& fout);//запись в файл
	static std::string returnTypeName()//возвращает имя класса для получения имени файла для хранения данных
	{
		return "docDatabase";
	}
};
