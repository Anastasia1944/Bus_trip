#ifndef _BUS_TRIP_
#define _BUS_TRIP_

#include <iostream>
#include <string>
#include "Driver.h"
using namespace std;
class BusTrip {
private:
	string destination_;	// ����� ����������
	int time_;		// ����� �����������
	int code_;		// ����� ��������
	Driver driver_;
	int time(string s);	//�������������� ������� � ������
public:
	// ���������� � �������� ������
	class ExceptionDestination
	{
	public:
		int numberOfStr_;
		ExceptionDestination(int numberOfStr) : numberOfStr_(numberOfStr) {};
	};
	// ���������� � ������ ��������
	class ExceptionCode
	{
	public:
		int numberOfStr_;
		ExceptionCode(int numberOfStr) : numberOfStr_(numberOfStr) {};
	};
	// ���������� �� ������� �����������
	class ExceptionTime
	{
	public:
		int numberOfStr_;
		ExceptionTime(int numberOfStr) : numberOfStr_(numberOfStr) {};
	};
	// ����� ���������� ����� �����
	class ExceptionFileName {};
	// ����� ���������� ������� �����
	class ExceptionFileEmpty {};
	class ExceptionBusTrip {};
	// ����������� ������� �������� �������
	BusTrip() : time_(0), destination_(""), code_(0) {};
	// ����������� ��������� �������� �������
	BusTrip(const string& s);
	// ����������� ��������� �������� �������
	BusTrip(const string& s, int i);
	// ����������� �����������
	BusTrip(const BusTrip& src);
	// ���������� ��������� ��������� <
	bool operator< (BusTrip* s);
	// ���������� ��������� ��������� >
	bool operator> (BusTrip* s);
	// �������� �������� +
	void operator+ (int i);
	// �������� �������� -
	void operator- (int i);
	BusTrip& operator=(string s);
	// �������� ������������
	BusTrip& operator=(BusTrip& s);
	// ������ � ������� ����������� �����
	string time() const;
	// ������ � ������ ��������
	int code() const;
	// ������ � �������� ������ ����������
	string destination() const;
	// ���������� �������� ++ 
	BusTrip& operator++();
	// ���������� �������� --
	BusTrip& operator--();
	// ����������� �������� ++ ����� ������������� �������
	friend BusTrip operator++(BusTrip& s, int);
	// ����������� �������� -- ����� ������������� �������
	friend BusTrip operator--(BusTrip& s, int);
	// ���� ����������� �����
	friend istream& operator>> (istream& in, BusTrip& s);
	// ����� ����������� ����� 
	friend ostream& operator<< (ostream& out, BusTrip& s);
	//���������� ��������
	~BusTrip();
};

#endif