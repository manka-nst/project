#pragma once
#include "procedure.h"

class patient :public procedure
{
protected:
    std::string FIO;//ФИО пациента
	std::string date_of_birth;//дата рождения
	std::string city;//город
	std::string illnes;//болезнь
	std::string datepos;//дата поступления 
	std::string sex;//пол
	std::string phone;//номер телефона
	std::string card;//номер карты в больнице
public:
	patient()//конструктор по умолчанию
	{
		name_of_section = "no info";
		name_of_doc = "no info";
		code_of_doc = "no info";
		name_of_proc = "no info";
		FIO = "no info";
		date_of_birth = "no info";
		city = "no info";
		illnes = "no info";
		sex = "no info";
		phone = "no info";
		card = "no info";
		datepos = "no info";
	}
	void set();//ввод/изменение данных объекта
	void get();//вывод на экран информации о объекте
	void edit();//редактирование данных
	void changenamesection();//изменение названия кафедры
	void changenamedoc();//изменение названия специальности
	void changecode();//изменение кода специальности
	void changenameproc();//изменение названия процедуры
	void changeFIO();//изменение ФИО пациента
	void changecity();//изменение города 
	void changeDateOfBirth();//изменение даты рождения
	void changesex();//изменение пола
	void changephone();//изменение номера телефона
	void changecard();//изменение номера карты
	void changedatepos();//изменения даты поступления
	void changeillnes();//изменение болезни
	friend std::ostream& operator<<(std::ostream& os, const patient& obj);//перегрузка оператора вывода
	friend std::istream& operator>>(std::istream& is, patient& obj);//перегрузка оператора ввода
	void top();//вывод шапки таблицы
	void line();//вывод разделяющей линии
	void read(std::ifstream& fin);//чтение из файла
	void write(std::ofstream& fout);//запись в файл
	static std::string returnTypeName()//возвращает имя класса для получения имени файла для хранения данных
	{
		return "patient";
	}
};
