#include <windows.h>
#include "BusTrip.h"
#include "ArrayBusTrip.h"
#include "BNF.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		const int SIZE2 = 20;
		ArrayBusTrip array1(SIZE2);
		array1.input();
		array1.output();
	}
	catch (BusTrip::ExceptionFileName)
	{
		cerr << endl << "Неверно указано имя файла или путь к нему";
		return -1;
	}
	catch (BusTrip::ExceptionFileEmpty)
	{
		cerr << endl << "Файл пуст";
		return -1;
	}
	catch (BusTrip::ExceptionBusTrip)
	{
		cerr << endl << "Не существует такого элемента";
		return -1;
	}
	catch (BusTrip::ExceptionDestination& error)
	{
		if (error.numberOfStr_ == 0)
			cerr << endl << "Ошибка в веденной строке! Неккоректно задано название пункта назначения.";
		else
			cerr << endl << "Ошибка в строке № " << error.numberOfStr_
			<< ". Неккоректно задано название пункта назначения. " << endl;
		return -1;
	}
	catch (BusTrip::ExceptionCode& error)
	{
		if (error.numberOfStr_ == 0)
			cerr << endl << "Ошибка в веденной строке! Неккоректно задан номер маршрута.";
		else
			if (error.numberOfStr_ == -1)
				cerr << endl << "Ошибка в префиксном операторе! "
				<< "Номер рейса не может быть больше или меньше допустимого";
			else
				cerr << endl << "Ошибка в строке № " << error.numberOfStr_
				<< ". Неккоректно задан номер маршрута. " << endl;
		return -1;
	}
	catch (BusTrip::ExceptionTime& error)
	{
		if (error.numberOfStr_ == 0)
			cerr << endl << "Ошибка в веденной строке! Неккоректно задано время отправления" << endl;
		else
			if (error.numberOfStr_ == -1)
				cerr << endl << "Ошибка в бинарном операторе +! "
				<< "Время отправления не может быть больше или меньше допустимого" << endl;
			else
				cerr << endl << "Ошибка в строке № " << error.numberOfStr_
				<< ". Неккоректно задано время отправления. " << endl;
		return -1;
	}
	catch (const char* errorString) {
		cerr << endl << errorString << endl;
		return -1;
	}
	return 0;
}