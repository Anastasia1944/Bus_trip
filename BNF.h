#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
using namespace std;
class BNF{
private:
	char*& s_; // Проверяемая строка
	int numberStr_; // Номер строки из файла 
	string destination_; // Пункт назначения в строке
	string time_; // Время в строке
	int code_;	// Номер маршрута в строке
	//<часы>::='0'<цифра>|'1'<цифра>|'2'<единицы часов>
	bool isHours();
	//<единицы часов>::=0|…|3
	bool isUnitsOfHours();
	//<минуты>::=<десятки минут><цифра>
	bool isMinutes();
	//<десятки минут>::=0|…|5
	bool isTensOfMinutes();
	//<заглавное слово>::=<заглавная буква><слово>
	bool isHeadWord();
	//<слово>::=<буква>|<буква><слово>
	bool isWord();
	//<заглавная буква>::=А|…|Я	
	bool isHeadLetter();
	//<буква>::=а|…|я
	bool isLetter();
	//<цифра>::=0|…|9
	bool isDigit();
public:
	// Конструктор без номера строки
	BNF(char*& st) :numberStr_(0), s_(st), time_(""), code_(0), destination_("") {
		isBusTrip();
	};
	// Конструктор с номером строки
	BNF(char*& st,int i):numberStr_(i), s_(st), time_(""), code_(0), destination_("") {
		isBusTrip();
	};
	// Доступ к времени в строке 
	string time() const;
	// Доступ к номеру маршрута в строке
	int code() const;
	// Доступ к пункту назначения в строке
	string destination() const;
	//<автобусный рейс>::=<название>'˽'<номер> '˽'<время> 
	bool isBusTrip();
	//<название>::=<заглавное слово>|<заглавное слово>'˽'<заглавное слово>|
	//<заглавное слово>'-'<заглавное слово>|
	//<заглавное слово>'-'<слово>'-'<заглавное слово>
	bool isTitle();
	//<номер>::=<цифра><цифра><цифра>|<цифра><цифра>
	bool isNumber();
	//<время>::=<часы>':'<минуты>
	bool isTime();
	//Деструктор элемента
	~BNF();
};
#endif
