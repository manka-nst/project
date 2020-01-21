#pragma once
#include "procedure.h"

class procedureDatabase :public procedure
{
protected:
	std::string ward;//палата
	std::string date;//дата
public:
	void set();//ввод/изменение данных объекта
	void get();//вывод на экран информации о объекте
	procedureDatabase()//конструктор по умолчанию
	{
		name_of_section = "no info";
		name_of_doc = "no info";
		code_of_doc = "no info";
		name_of_proc = "no info";
		ward = "no info";
		date = "no info";
	}
	friend std::ostream& operator<<(std::ostream& os, const procedureDatabase& obj);//перегрузка оператора вывода
	friend std::istream& operator>>(std::istream& is, procedureDatabase& obj);//перегрузка оператора ввода
	void edit();//редактирование данных
	void changenamesection();//изменение названия отделения 
	void changenamespec();//изменение ФИО врача
	void changecode();//изменение кода врача
	void changenameproc();//изменение названия процедуры
	void changeward();//изменене палаты
	void changedate();//изменение даты
	void top();//вывод шапки таблицы
	void line();//вывод разделяющей линии
	void read(std::ifstream& fin);//чтение из файла очередного элемента
	void write(std::ofstream& fout);//запись в файл очередного элемента
	static std::string returnTypeName()//возвращает имя класса для получения имени файла для хранения данных
	{
		return "procedureDatabase";
	}
};
