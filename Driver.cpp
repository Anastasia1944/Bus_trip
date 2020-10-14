#include <iostream>
#include <string>
#include "BusTrip.h"
using namespace std;

Driver::Driver(string name, string sex, int experience) {
	name_ = name;
	experience_ = experience;
	if (sex == "male")
		sex_ = 1;
	else sex_ = 0;
}

string Driver::name() const
{
	if (this != nullptr)
		return name_;
	return "";
}

int Driver::experience() const
{
	if (this != nullptr)
		return experience_;
	return -1;
}

string Driver::sex() const
{
	if (this != nullptr)
		if (sex_)
			return "male";
		else return "female";
	return "";
}

Driver::~Driver() {
	if (experience_ != 0)
		experience_ = 0;
	if (name_ != "")
		name_ = "";
}
