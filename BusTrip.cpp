#include <iostream>
#include <string>
#include "BusTrip.h"
#include "BNF.h"
#include "ArrayBusTrip.h"
using namespace std;

// ������ � ������� ����������� ��������
string BusTrip::time() const
{
	if (this != nullptr) {
		string s = "";
		if (time_ / 600 == 0)
			s = "0" + s;
		s += to_string(time_ / 60);
		s += ":";
		if ((time_ % 60) / 10 == 0)
			s += '0';
		s += to_string(time_ % 60);
		return s;
	}
	return "-1";
}


// ������ � ������ �������� ��������
int BusTrip::code() const
{
	if (this != nullptr)
		return code_;
	return -1;
}

// ������ � ������ ���������� ��������
string BusTrip::destination() const
{
	if (this != nullptr)
		return destination_;
	return "-1";
}

// ����������� �����������
BusTrip::BusTrip(const BusTrip& src) {
	BusTrip* temp = new BusTrip;
	if (this != &src && &src != nullptr) {
		destination_ = src.destination_;
		code_ = src.code_;
		time_ = src.time_;
	}
}

// ������������ ������� � �������
int BusTrip::time(string s) {
	char* c = &s[0];
	if (s != "" && s.length() == 5) {
		int minutes = 0;
		string temp;
		minutes = stoi(temp.assign(s, 0, 2)) * 60 + stoi(temp.assign(s, 3, 2));
		return minutes;
	}
	return -1;
}

// �������� �������� 
BusTrip::BusTrip(const string& s)
{
	string m = s;
	char *p = &m[0];
	char *& c = p;
	BNF k(p);
	destination_ = k.destination();
	code_ = k.code();
	time_ = time(k.time());
}

// �������� �������� 
BusTrip::BusTrip(const string& s, int i)
{
	string m = s;
	char *p = &m[0];
	char *& c = p;
	BNF k(p, i);
	destination_ = k.destination();
	code_ = k.code();
	time_ = time(k.time());
}

// �������� ������������ ������ ����������� �����
BusTrip& BusTrip::operator=(string s) {
	BusTrip h(s);
	*this = h;
	return *this;
}

// ���������� ��������� ��������� <
bool BusTrip::operator< (BusTrip* s) {
	if (this != nullptr && s != nullptr) {
		if (this->time_ < s->time_)
			return true;
		else
			return false;
	}
	throw "�� �������� ������ (�������� <)";
	return false;
}

// ���������� ��������� ��������� >
bool BusTrip::operator> (BusTrip* s) {
	if (this != nullptr && s != nullptr) {
		if (this->time_ > s->time_)
			return true;
		else
			return false;
	}
	throw "�� �������� ������ (�������� >)";
	return false;
}

// ���������� ��������� ��������� +
void BusTrip::operator+ (int i) {
	if (this != nullptr) {
		time_ += i;
	}
}

// ���������� ��������� ��������� -
void BusTrip::operator- (int i) {
	if (this != nullptr) {
		time_ -= i;
	}
}

// �������� ������������
BusTrip& BusTrip::operator=(BusTrip& s) {
	if (&s != this) {
		if (s.destination_ != destination_)
			destination_ = s.destination_;
		if (s.time_ != time_)
			time_ = s.time_;
		if (s.code_ != code_)
			code_ = s.code_;
	}
	return *this;
}

// ���������� �������� ++
BusTrip& BusTrip::operator++() {
	if (this != nullptr) {
		code_++;
		string temp = to_string(code_);
	}
	return *this;
}

// ���������� �������� --
BusTrip& BusTrip::operator--() {
	if (this != nullptr) {
		code_--;
		string temp = to_string(code_);
	}
	return *this;
}

// ����������� �������� ++ ����� ������������� �������
BusTrip operator++(BusTrip& s, int) {
	if (&s != nullptr) {
		BusTrip temp1(s);
		++s.code_;
		string temp = to_string(s.code_);
		return temp1;
	}
	throw BusTrip::ExceptionBusTrip();
}

// ����������� �������� -- ����� ������������� �������
BusTrip operator--(BusTrip& s, int) {
	if (&s != nullptr) {
		BusTrip temp1(s);
		--s.code_;
		string temp = to_string(s.code_);
		return temp1;
	}
	throw BusTrip::ExceptionBusTrip();
}

// ����� ��������
ostream& operator<< (ostream& out, BusTrip& s)
{
	if (&s != nullptr) {
		out << s.destination_ << " ";
		out << s.code_ << " ";
		out << s.time() << " " << endl;
	}
	return out;
}

// ���� ��������
istream& operator>> (istream& in, BusTrip& s)
{
	cout << "������� ���������� ����, ���������� <;>: ";
	string temp;
	getline(cin, temp, ';');
	if (temp[0] == '\n')
		temp.erase(0, 1);
	char* p = &temp[0];
	char*& c = p;
	BNF k(c);
	s.destination_ = k.destination();
	s.code_ = k.code();
	s.time_ = s.time(k.time());
	return in;
}

// ���������� ��������
BusTrip::~BusTrip() {
	if (time_ != 0)
		time_ = 0;
	if (code_ != 0)
		code_ = 0;
	if (destination_ != "")
		destination_ = "";
}
