#pragma once
#include "section.h"

class sectionDatabase :public section
{
protected:
	std::string spisok_doc;//список врачей
	std::string zavsection;//ФИО заведующего отделением
public:
	sectionDatabase()//конструктор по умолчанию
	{
		name_of_section = "no info";
		zavsection = "no info";
		spisok_doc = "no info";
	}
	void get();//вывод на экран информации о объекте
	void set();//ввод/изменение данных объекта
	friend std::ostream& operator<<(std::ostream& os, const sectionDatabase& obj);//перегрузка оператора вывода
	friend std::istream& operator>>(std::istream& is, sectionDatabase& obj);//перегрузка оператора ввода
	void edit();//редактирование данных
	void changename();//изменение названия отделения
	void changenamezavsection();//изменение ФИО завотделения
	void changespisokdoc();//изменение списка врачей
	void top();//вывод шапки таблицы
	void line();//вывод разделяющей линии
	void read(std::ifstream& fin);//чтение из файла очередного элемента
	void write(std::ofstream& fout);//запись в файл очередного элемента
	static std::string returnTypeName()//возвращает имя класса для получения имени файла для хранения данных
	{
		return "sectionDatabase";
	}
};
