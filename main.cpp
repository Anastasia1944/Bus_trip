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
		cerr << endl << "������� ������� ��� ����� ��� ���� � ����";
		return -1;
	}
	catch (BusTrip::ExceptionFileEmpty)
	{
		cerr << endl << "���� ����";
		return -1;
	}
	catch (BusTrip::ExceptionBusTrip)
	{
		cerr << endl << "�� ���������� ������ ��������";
		return -1;
	}
	catch (BusTrip::ExceptionDestination& error)
	{
		if (error.numberOfStr_ == 0)
			cerr << endl << "������ � �������� ������! ����������� ������ �������� ������ ����������.";
		else
			cerr << endl << "������ � ������ � " << error.numberOfStr_
			<< ". ����������� ������ �������� ������ ����������. " << endl;
		return -1;
	}
	catch (BusTrip::ExceptionCode& error)
	{
		if (error.numberOfStr_ == 0)
			cerr << endl << "������ � �������� ������! ����������� ����� ����� ��������.";
		else
			if (error.numberOfStr_ == -1)
				cerr << endl << "������ � ���������� ���������! "
				<< "����� ����� �� ����� ���� ������ ��� ������ �����������";
			else
				cerr << endl << "������ � ������ � " << error.numberOfStr_
				<< ". ����������� ����� ����� ��������. " << endl;
		return -1;
	}
	catch (BusTrip::ExceptionTime& error)
	{
		if (error.numberOfStr_ == 0)
			cerr << endl << "������ � �������� ������! ����������� ������ ����� �����������" << endl;
		else
			if (error.numberOfStr_ == -1)
				cerr << endl << "������ � �������� ��������� +! "
				<< "����� ����������� �� ����� ���� ������ ��� ������ �����������" << endl;
			else
				cerr << endl << "������ � ������ � " << error.numberOfStr_
				<< ". ����������� ������ ����� �����������. " << endl;
		return -1;
	}
	catch (const char* errorString) {
		cerr << endl << errorString << endl;
		return -1;
	}
	return 0;
}