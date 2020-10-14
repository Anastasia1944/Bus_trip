#ifndef _ARRAY_BUS_TRIP_
#define _ARRAY_BUS_TRIP_
#include <iostream>
#include <string>
#include "BusTrip.h"
#include "ArrayBusTrip.h"
using namespace std;

class ArrayBusTrip
{
private:
	BusTrip* array_; // Массив автобусных рейсов
	int size_; // Размер массива
public:
	// Конструктор по умолчанию
	ArrayBusTrip() :size_(0) {};
	// Конструктор
	ArrayBusTrip(int size);
	/*Ввод массива с класиатуры*/
	friend istream& operator>> (istream& in, ArrayBusTrip & s);
	/* Вывод массива */
	friend ostream& operator<< (ostream& out, ArrayBusTrip & s);
	/* Элемент с минимальным номером маршрута*/
	BusTrip& minElement();
	/* Оператор взятия адреса */
	BusTrip& operator[] (int i);
	/* Вывод в файл отсортированной таблицы по времени*/
	void outputSortingTime(string file);
	/* Вывод в файл отсортированного списка по номеру маршрута*/
	void outputSortingNumber(string file);
	/* Максимальная длина пункта назначения*/
	int maxLength();
	/* Минимальный номер маршрута*/
	int minNumber();
	/* Ввод массива с файла*/
	int input();
	/* Сортировка массива по времени*/
	void arraySorting();
	/* Сортировка массива по номеру маршрута*/
	void arraySortingNumber();
	/* Вывод в файл*/
	void output();
	~ArrayBusTrip();
};

#endif

