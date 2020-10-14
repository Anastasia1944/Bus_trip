#include <iostream>
#include <string>
#include <fstream>
#include "BusTrip.h"
#include "ArrayBusTrip.h"
using namespace std;

// Конструктор массива
ArrayBusTrip::ArrayBusTrip(int size) {
	array_ = new BusTrip[size];
	if (array_ == NULL)
		throw "Ошибка выделения памяти";
	size_ = size;
}

// Оператор взятия адреса
BusTrip& ArrayBusTrip:: operator[] (int i) {
	return array_[i]; // возврат ссылки на a[i]
}

// Поиск максимальной длины пункта назначения
int ArrayBusTrip::maxLength() {
	int maxLength = array_[0].destination().length();
	int k = 0;
	for (int i = 1; i < size_; i++) {
		k = array_[i].destination().length();
		if (k > maxLength)
			maxLength = k;
	}
	return maxLength;
}

// Поиск элемента массива с минимальным временем отправления
BusTrip& ArrayBusTrip::minElement() {
	BusTrip *min = &array_[0];
	for (int i = 1; i < size_; i++) {
		if (array_[i] < min)
			min = &array_[i];
	}
	return *min;
}

// Минимальный номер маршрута 
int ArrayBusTrip::minNumber() {
	int min = array_[0].code();
	for (int i = 1; i < size_; i++) {
		if (array_[i].code() < min)
			min = array_[i].code();
	}
	return min;
}

// Заполнение массива из файла
int ArrayBusTrip::input() {
	string file;
	cout << "Введите название файла для ввода: ";
	cin >> file;
	ifstream F(file);
	if (!F.is_open())
		throw BusTrip::ExceptionFileName();
	const int SIZE = 100;
	char s[SIZE];
	int count = 0;
	while (F.getline(s, SIZE + 1)) {
		if (s == "")
			throw BusTrip::ExceptionFileEmpty();
		char *p = s;
		char *& c = p;
		BusTrip Trip1(s, count);
		array_[count] = Trip1;
		count++;
	}
	size_ = count;
	F.close();
	return count;
}

// Добавление в строку s пробелов в кол-ве k для вывода в виде таблицы
string addition(string s, int k) {
	for (int i = 0; i < k; i++)
		s += " ";
	s += " ";
	return s;
}

// Вывод в файл таблицы автобусных рейсов, сортированной по времени
void ArrayBusTrip::outputSortingTime(string file) {
	ofstream F(file, ios::app);
	this->arraySorting();
	int maxL = this->maxLength();
	string s = "";
	// Вывод отсортированной таблицы 
	s = "Название ПН";
	s = addition(s, maxL - 11);
	s += "  Номер маршрута   Время отправления";
	F << s << endl;
	F << "-----------------------------------------------------" << endl;
	s = "";
	for (int i = 0; i < size_; i++) {
		s = array_[i].destination();
		s = addition(s, maxL - s.length() + 2);
		s += to_string(array_[i].code());
		if (to_string(array_[i].code()).length() == 2)
			s += " ";
		s = addition(s, 13);
		s += array_[i].time();
		F << s << endl;
		s = "";
	}
	F.close();
}

// Вывод в файл отсортированный список кодов городов 
void ArrayBusTrip::outputSortingNumber(string file) {
	ofstream F(file, ios::app);
	this->arraySortingNumber();
	string s = "";
	F << endl << "Список пунктов назначения: " << endl;
	for (int i = 0; i < size_; i++) {
		s = to_string(array_[i].code());
		s += " - ";
		s += array_[i].destination();
		F << s << endl;
		s = "";
	}
	F.close();
}

// Вывод отсортированного массива в файл
void ArrayBusTrip::output() {
	string file;
	cout << "Введите название файла для вывода: ";
	cin >> file;
	ofstream F(file);
	if (!F.is_open())
		throw BusTrip::ExceptionFileName();
	F.close();
	this->outputSortingTime(file);
	this->outputSortingNumber(file);
	ofstream F2(file, ios::app);
	F2 << endl << "Минимальный номер маршрута: " << endl;
	F2 << this->minNumber();
	F2.close();
}

// Сортировка массива автобусных рейсов вставками 
void ArrayBusTrip::arraySorting() {
	BusTrip key;
	int j = 0;
	for (int i = 1; i < size_; i++) {
		j = i - 1; key = array_[i];
		while (key < &array_[j] && j >= 0) {
			array_[j + 1] = array_[j];
			j--;
		}
		array_[j + 1] = key;
	}
}

// Сортировка массива автобусных рейсов по номеру маршрута
void ArrayBusTrip::arraySortingNumber() {
	BusTrip key;
	int j = 0;
	for (int i = 1; i < size_; i++) {
		j = i - 1; key = array_[i];
		while (key.code() < array_[j].code() && j >= 0) {
			array_[j + 1] = array_[j];
			j--;
		}
		array_[j + 1] = key;
	}
}

// Ввод массива автобусных рейсов
istream& operator>> (istream& in, ArrayBusTrip& s) {
	for (int i = 0; i < s.size_; i++) {
		in >> s.array_[i];
	}
	return in;
}

// Вывод масива автобусных рейсов
ostream& operator<< (ostream& out, ArrayBusTrip & s) {
	for (int i = 0; i < s.size_; i++) {
		out << s.array_[i];
	}
	return out;
}

ArrayBusTrip::~ArrayBusTrip() {
	if (size_ != 0)
		size_ = 0;
	if (array_ != nullptr)
		array_ = nullptr;
}
