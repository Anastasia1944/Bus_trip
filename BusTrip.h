#ifndef _BUS_TRIP_
#define _BUS_TRIP_

#include <iostream>
#include <string>
#include "Driver.h"
using namespace std;
class BusTrip {
private:
	string destination_;	// Пункт назначения
	int time_;		// Время отправления
	int code_;		// Номер маршрута
	Driver driver_;
	int time(string s);	//Преобразование времени в минуты
public:
	// Исключения в названии города
	class ExceptionDestination
	{
	public:
		int numberOfStr_;
		ExceptionDestination(int numberOfStr) : numberOfStr_(numberOfStr) {};
	};
	// Исключение в номере маршрута
	class ExceptionCode
	{
	public:
		int numberOfStr_;
		ExceptionCode(int numberOfStr) : numberOfStr_(numberOfStr) {};
	};
	// Исключение во времени отправления
	class ExceptionTime
	{
	public:
		int numberOfStr_;
		ExceptionTime(int numberOfStr) : numberOfStr_(numberOfStr) {};
	};
	// Класс исключения имени файла
	class ExceptionFileName {};
	// Класс исключения пустого файла
	class ExceptionFileEmpty {};
	class ExceptionBusTrip {};
	// Конструктор пустого элемента массива
	BusTrip() : time_(0), destination_(""), code_(0) {};
	// Конструктор непустого элемента массива
	BusTrip(const string& s);
	// Конструктор непустого элемента массива
	BusTrip(const string& s, int i);
	// Конструктор копирования
	BusTrip(const BusTrip& src);
	// Перегрузка оператора отношения <
	bool operator< (BusTrip* s);
	// Перегрузка оператора отношения >
	bool operator> (BusTrip* s);
	// Бинарный оператор +
	void operator+ (int i);
	// Бинарный оператор -
	void operator- (int i);
	BusTrip& operator=(string s);
	// Оператор присваивания
	BusTrip& operator=(BusTrip& s);
	// Доступ к времени отправления рейса
	string time() const;
	// Доступ к номеру маршрута
	int code() const;
	// Доступ к названию пункта назначения
	string destination() const;
	// Префиксный оператор ++ 
	BusTrip& operator++();
	// Префиксный оператор --
	BusTrip& operator--();
	// Постфиксный оператор ++ через дружественную функцию
	friend BusTrip operator++(BusTrip& s, int);
	// Постфиксный оператор -- через дружественную функцию
	friend BusTrip operator--(BusTrip& s, int);
	// Ввод автобусного рейса
	friend istream& operator>> (istream& in, BusTrip& s);
	// Вывод автобусного рейса 
	friend ostream& operator<< (ostream& out, BusTrip& s);
	//Деструктор элемента
	~BusTrip();
};

#endif