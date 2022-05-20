#include "Date.h"


string Date::monthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

bool Date::defaultSet = false;
	
Date::Date(int d, Month m, int y) { fillDate(d, m, y); }

Date::Date(int d, int m, int y) {
		fillDate(d, Month(m), y);
}

Date::Date(const Date& date) { fillDate(date.day(), date.month(), date.year()); }

void Date::fillDate(int d, Month m, int y) {
	if (!defaultSet)
	{
		setDefault();
	}
	_day = d ? d : defaultDate._day;
	_month = m ? m : defaultDate._month;
	_year = y ? y : defaultDate._year;
	int numberOfDays = 0;
	switch (_month) {
	case feb: numberOfDays = 28 + leapYear(y);
		break;
	case apr:
	case jun:
	case sep:
	case nov:
		numberOfDays = 30;
		break;
	case jan:
	case mar:
	case may:
	case jul:
	case aug:
	case oct:
	case dec:
		numberOfDays = 31;
		break;
	default: 
		throw BadDate(_day, _month, _year);
	}
	if ((_day < 1) || (numberOfDays < _day) || (_year < 1)) throw BadDate(_day, _month, _year);
}

void Date::setDefault(int d, Month m, int y)
{
	defaultSet = true;
	defaultDate = Date(d, m, y); 
}

#include <ctime>  
void Date::setDefault() {
	defaultSet = true;
	time_t timer;
	time(&timer); 
	#pragma warning(suppress : 4996)
	struct tm * today = localtime(&timer);
	defaultDate._day=today->tm_mday;    
	defaultDate._month=++(today->tm_mon);   
	defaultDate._year=today->tm_year+=1900; 
}
ostream& operator<<(ostream& os, const Date& d) 
{ 
	os << d.day() << ' ' << d.getMonthName() << ' ' << d.year(); 
	return os; 
}
ostream& operator<<(std::ostream& os, const Date::BadDate& bd) {
	os << bd._day << '.' << bd._month << '.' << bd._year;
	return os;
}
void Date::showDefault() 
{ 
	cout << defaultDate; 
}
Date Date::defaultDate = Date();

void Date::setDay(int d) {
	fillDate(d, Month(_month), _year);
}

void Date::setMonth(int m) {
	fillDate(_day, Month(m), _year);
}

void Date::setDYear(int y) {
	fillDate(_day, Month(_month), y);
}

bool Date::leapYear(int y) {
	return (y % 4 == 0);
}

const Date& Date::operator++() {
	int numberOfDays = 0;
	switch (_month) {
	case feb: numberOfDays = 28 + leapYear(_year);
		break;
	case apr:
	case jun:
	case sep:
	case nov:
		numberOfDays = 30;
		break;
	case jan:
	case mar:
	case may:
	case jul:
	case aug:
	case oct:
	case dec:
		numberOfDays = 31;
		break;
	}
	if (_day == numberOfDays) {
		if (_month==12)
		{
			fillDate(1,Month(1), year() + 1);
		}
		else
		{
			fillDate(1, Month(month()+1), _year);
		}
	}
	else {
		fillDate(day()+1, Month(_month), _year);
	}
	return *this;
}
const Date Date::operator++(int) {
	int numberOfDays = 0;
	switch (_month) {
	case feb: numberOfDays = 28 + leapYear(_year);
		break;
	case apr:
	case jun:
	case sep:
	case nov:
		numberOfDays = 30;
		break;
	case jan:
	case mar:
	case may:
	case jul:
	case aug:
	case oct:
	case dec:
		numberOfDays = 31;
		break;
	}
	if (_day == numberOfDays) {
		if (_month == 12)
		{
			fillDate(1, Month(1), year() + 1);
		}
		else
		{
			fillDate(1, Month(month() + 1), _year);
		}
	}
	else {
		fillDate(day() + 1, Month(_month), _year);
	}
	return *this;
}
const Date& Date::operator--() {
	int numberOfDays = 0;
	switch (month() - 1) {
	case feb: numberOfDays = 28 + leapYear(_year);
		break;
	case apr:
	case jun:
	case sep:
	case nov:
		numberOfDays = 30;
		break;
	case jan:
	case mar:
	case may:
	case jul:
	case aug:
	case oct:
	case dec:
	case 0:
		numberOfDays = 31;
		break;
	}
	if (_day == 1)
	{
		if (_month == 1)
		{
			fillDate(numberOfDays, Month(12), year() - 1);
		}
		else {
			fillDate(numberOfDays, Month(month() - 1), _year);
		}
	}
	else
	{
		fillDate(day() - 1, Month(_month), _year);
	}
	return *this;
}
const Date Date::operator--(int) {
	int numberOfDays = 0;
	switch (month() - 1) {
	case feb: numberOfDays = 28 + leapYear(_year);
		break;
	case apr:
	case jun:
	case sep:
	case nov:
		numberOfDays = 30;
		break;
	case jan:
	case mar:
	case may:
	case jul:
	case aug:
	case oct:
	case dec:
	case 0:
		numberOfDays = 31;
		break;
	}
	if (_day == 1)
	{
		if (_month == 1)
		{
			fillDate(numberOfDays, Month(12), year() - 1);
		}
		else {
			fillDate(numberOfDays, Month(month() - 1), _year);
		}
	}
	else
	{
		fillDate(day() - 1, Month(_month), _year);
	}
	return *this;
}

bool operator == (const Date& d1, const Date& d2) {
	return d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year();
}
bool operator != (const Date& d1, const Date& d2) {
	return !(d1 == d2);
}
bool operator < (const Date& d1, const Date& d2) {
	if (d1.year() < d2.year()) return true;
	if (d1.year() == d2.year() && d1.month() < d2.month()) return true;
	if (d1.year() == d2.year() && d1.month() == d2.month() && d1.day() < d2.day()) return true;
	return false;
}