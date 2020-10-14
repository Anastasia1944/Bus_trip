#include <iostream>
#include <string>
#include "BNF.h"
#include "BusTrip.h"
#include "ArrayBusTrip.h"
using namespace std;

string BNF::time() const {
	if (time_ != "")
		return time_;
	else
		return "-1";
}

string BNF::destination() const {
	if (destination_ != "")
		return destination_;
	else
		return "-1";
}

int BNF::code() const {
	if (code_ != 0)
		return code_;
	else
		return -1;
}

//<автобусный рейс>::=<название>'˽'<номер> '˽'<время> 
bool BNF::isBusTrip() {
	if (isTitle()) {
		if (*s_ == ' ') {
			s_++;
			if (isNumber()) {
				if (*s_ == ' ') {
					s_++;
					if (isTime())
						return true;
					throw BusTrip::ExceptionTime(numberStr_);
				}
				throw BusTrip::ExceptionCode(numberStr_);
			}
			throw BusTrip::ExceptionCode(numberStr_);
		}
		throw BusTrip::ExceptionDestination(numberStr_);
	}
	throw BusTrip::ExceptionDestination(numberStr_);
}

//<название>::=<заглавное слово>|<заглавное слово>'˽'<заглавное слово>|
//<заглавное слово>'-'<заглавное слово>|
//<заглавное слово>'-'<слово>'-'<заглавное слово>	
bool BNF::isTitle() {
	if (isHeadWord()) {
		if (*s_ == ' ') {
			destination_ += *s_;
			s_++;
			if (isHeadWord()) {
				if (*s_ != '\0' && *s_ != ' ')
					return false;
				return true;
			}
			else {
				destination_.erase(destination_.length());
				s_--;
			}
		}
		if (*s_ == '-') {
			destination_ += *s_;
			s_++;
			if (isHeadWord()) {
				if (*s_ != '\0' && *s_ != ' ')
					return false;
				return true;
			}
			if (isWord()) {
				if (*s_ == '-') {
					destination_ += *s_;
					s_++;
					if (isHeadWord()) {
						if (*s_ != '\0' && *s_ != ' ')
							return false;
						return true;
					}
					return false;
				}
				return false;
			}
			return false;
		}
		return true;
	}
	return false;
}

//<номер>::=<цифра><цифра><цифра>|<цифра><цифра>
bool BNF::isNumber() {
	if (isDigit()) {
		code_ = code_ * 10 + atoi((s_ - 1));
		if (isDigit()) {
			if (isDigit()) {
				if (*s_ != '\0' && *s_ != ' ')
					return false;
				return true;
			}
			return true;
		}
		return false;
	}
	return false;
}

//<время>::=<часы>':'<минуты>
bool BNF::isTime() {
	if (isHours()) {
		if (*s_ == ':') {
			time_ += *s_;
			s_++;
			if (isMinutes())
				return true;
			return false;
		}
		return false;
	}
	return false;
}

//<часы>::='0'<цифра>|'1'<цифра>|'2'<единицы часов>
bool BNF::isHours() {
	if (*s_ == '0' || *s_ == '1') {
		time_ += *s_;
		s_++;
		if (isDigit())
			time_ += *(s_ - 1);
			return true;
		return false;
	}
	if (*s_ == '2') {
		time_ += *s_;
		s_++;
		if (isUnitsOfHours())
			time_ += *(s_ - 1);
			return true;
		return false;
	}
	return false;
}

//<единицы часов>::=0|…|3
bool BNF::isUnitsOfHours() {
	if (*s_ >= '0' && *s_ <= '3') {
		s_++;
		return true;
	}
	return false;
}

//<минуты>::=<десятки минут><цифра>
bool BNF::isMinutes() {
	if (isTensOfMinutes()){
		time_ += *(s_ - 1);
		if (isDigit()){
			time_ += *(s_- 1);
			return true;
		}
		return false;
	}
	return false;
}

//<десятки минут>::=0|…|5
bool BNF::isTensOfMinutes() {
	if (*s_ >= '0' && *s_ <= '5') {
		s_++;
		return true;
	}
	return false;
}

//<заглавное слово>::=<заглавная буква><слово>
bool BNF::isHeadWord() {
	if (isHeadLetter())
		return (isWord());
	return false;
}

//<слово>::=<буква>|<буква><слово>
bool BNF::isWord() {
	if (isLetter()) {
		isWord();
		return true;
	}
	return false;
}

//<заглавная буква>::=А|…|Я
bool BNF::isHeadLetter() {
	if (*s_ >= 'А' && *s_ <= 'Я') {
		destination_ += *s_;
		s_++;
		return true;
	}
	return false;
}

//<буква>::=а|…|я
bool BNF::isLetter() {
	if (*s_ >= 'а' && *s_ <= 'я') {
		destination_ += *s_; 
		s_++;
		return true;
	}
	return false;
}

//<цифра>::=0|…|9
bool BNF::isDigit() {
	if (*s_ >= '0' && *s_ <= '9') {
		s_++;
		return true;
	}
	return false;
}

BNF::~BNF() {
	if (s_ != 0)
		s_ = 0;
	if (numberStr_ != 0)
		numberStr_ = 0;
	if (time_ != "")
		time_ = "";
	if (code_ != 0)
		code_ = 0;
	if (destination_ != "")
		destination_ = "";
}