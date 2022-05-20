#include "Date.h"

//#define DEBUG

bool Date::defaultSet = false;
Date Date::defaultDate = Date();

bool Date::leapYear(int y)
{
	return y % 4 == 0;
}

void Date::fillDate(int d, Month m, int y)
{	
	switch (m) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (d < 1 || d > 31)
			throw BadDate(d, m, y);
		_day = d; _month = m; _year = y;
		break;
	case 4: case 6: case 9: case 11:
		if (d < 1 || d > 30)
			throw BadDate(d, m, y);
		_day = d; _month = m; _year = y;
		break;
	case 2:
		if (d < 1 || d > 28+leapYear(y))
			throw BadDate(d, m, y);
		_day = d; _month = m; _year = y;
		break;
	default:
		throw BadDate(d, m, y);
	}
}

Date::Date(int d, Month m, int y)
{
	fillDate(d, m, y);
#ifdef DEBUG 
	cout << "Constract date: " << *this << endl;
#endif
}

Date::Date(int d, int m, int y)
{
	fillDate(d, Month(m), y);
#ifdef DEBUG 
	cout << "Constract date: " << *this << endl;
#endif
}

Date::Date(const Date& that) : _day(that._day), _month(that._month), _year(that._year)
{
#ifdef DEBUG 
	cout << "Copy date: " << *this << endl;
#endif
}

Date::~Date()
{
#ifdef DEBUG 
	cout << "Deconstract date: " << *this << endl;
#endif
}

const string Date::getMonthName() const
{
	switch (_month) {
	case 1: return "January";
		break;
	case 2: return "February";
		break;
	case 3: return "March";
		break;
	case 4: return "April";
		break;
	case 5: return "May";
		break;
	case 6: return "June";
		break;
	case 7: return "July";
		break;
	case 8: return "August";
		break;
	case 9: return "September";
		break;
	case 10: return "October";
		break;
	case 11: return "November";
		break;
	case 12: return "December";
		break;
	}
}

void Date::setDay(int d)
{
	fillDate(d, Month(_month), _year);
}

void Date::setMonth(int m)
{
	fillDate(_day, Month(m), _year);
}

void Date::setDYear(int y)
{
	fillDate(_day, Month(_month), y);
}

void Date::setDefault(int d, Month m, int y)
{
	defaultDate = Date(d, m, y);
	defaultSet = true;
}

void Date::setDefault()
{
	defaultDate = Date(1, 1, 2000);
}

void Date::showDefault()
{
	if (defaultSet)
		cout << defaultDate << endl;
	else
		cout << "Default date is not set" << endl;
}

const Date& Date::operator++()
{
	switch (_month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (++_day > 31) {
			_day = 1;
			_month++;
		}
		break;
	case 4: case 6: case 9: case 11:
		if (++_day > 30) {
			_day = 1;
			_month++;
		}
		break;
	case 2:
		if (++_day > 28+leapYear(_year)) {
			_day = 1;
			_month++;
		}
		break;
	}

	if (_month > 12) {
		_month = 1;
		_year++;
	}

	return *this;
}

const Date Date::operator++(int)
{
	Date temp = *this;
	++(*this);
	return temp;
}

const Date& Date::operator--()
{
	if (--_day < 1)
	{
		_month--;
		if (_month < 1) {
			_month = 12;
			_year--;
		}

		switch (_month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			_day = 31;
			break;
		case 4: case 6: case 9: case 11:
			_day = 30;
			break;
		case 2:
			_day = 18 + leapYear(_year);
			break;
		}
	}
	return *this;
}

const Date Date::operator--(int)
{
	Date temp = *this;
	--(*this);
	return temp;
}

ostream& operator<<(ostream& os, const Date& d)
{
	os << d.day() << " " << d.getMonthName() << " " << d.year();
	return os;
}

ostream& operator<<(ostream& os, const Date::BadDate& bd)
{
	os << bd._day << "." << bd._month << "." << bd._year;
	return os;
}
