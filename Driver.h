#ifndef _DRIVER_
#define _DRIVER_

#include <iostream>
#include <string>
using namespace std;
class Driver {
private:
	int experience_; // ���� ������
	string name_; // ���
	bool sex_; // ���
public:
	// ����������� ������� �������� �������
	Driver() : experience_(0), name_(""), sex_(1) {};
	Driver(string name, string sex, int experience);
	string name() const;
	int experience() const;
	string sex() const;
	~Driver();
};
#endif