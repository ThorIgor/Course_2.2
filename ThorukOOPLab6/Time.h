#include <iostream>
#include <Windows.h>
#include<ctime>
#include "Date.h"

using namespace std;

class Time {
private:
	unsigned int _hours;
	unsigned int _minutes;
	unsigned int _seconds;

	void normalizeTime();

public:
	Time(const unsigned int s = 0, const unsigned int m = 0, const unsigned int h = 0);
	Time(const Time&);

	~Time() {}

	Time& operator=(const Time&); 

	operator int() const;

	const unsigned int& hours() const { return _hours; }
	const unsigned int& minutes() const { return _minutes; }
	const unsigned int& seconds() const { return _seconds; }

	void setHours(const unsigned int h);
	void setMinutes(const unsigned int m);
	void setSeconds(const unsigned int s);
};

ostream& operator<<(ostream& os, const Time& t);

void Timer(Time t);
void Watch(Date d, Time t);