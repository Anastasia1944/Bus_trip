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
	BusTrip* array_; // ������ ���������� ������
	int size_; // ������ �������
public:
	// ����������� �� ���������
	ArrayBusTrip() :size_(0) {};
	// �����������
	ArrayBusTrip(int size);
	/*���� ������� � ����������*/
	friend istream& operator>> (istream& in, ArrayBusTrip & s);
	/* ����� ������� */
	friend ostream& operator<< (ostream& out, ArrayBusTrip & s);
	/* ������� � ����������� ������� ��������*/
	BusTrip& minElement();
	/* �������� ������ ������ */
	BusTrip& operator[] (int i);
	/* ����� � ���� ��������������� ������� �� �������*/
	void outputSortingTime(string file);
	/* ����� � ���� ���������������� ������ �� ������ ��������*/
	void outputSortingNumber(string file);
	/* ������������ ����� ������ ����������*/
	int maxLength();
	/* ����������� ����� ��������*/
	int minNumber();
	/* ���� ������� � �����*/
	int input();
	/* ���������� ������� �� �������*/
	void arraySorting();
	/* ���������� ������� �� ������ ��������*/
	void arraySortingNumber();
	/* ����� � ����*/
	void output();
	~ArrayBusTrip();
};

#endif

