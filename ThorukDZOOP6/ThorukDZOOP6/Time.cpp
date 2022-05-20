#include "Time.h"


Time::operator int() const { return _hours * 3600 + _minutes * 60 + _seconds; }
void Time::normalizeTime() {
	_hours += ((_minutes + (_seconds / 60)) / 60);
	_minutes = (_minutes + (_seconds / 60)) % 60;
	_seconds %= 60;
}
void Time::setHours(const unsigned int h) {
	_hours = h; 
	normalizeTime();
	return;
}
void Time::setMinutes(const unsigned int m) {
	_minutes = m; normalizeTime();
	return;
}
void Time::setSeconds(const unsigned int s) {
	_seconds = s; normalizeTime();
	return;
}
Time& Time::operator=(const Time& t) {
	_hours = t.hours();
	_minutes = t.minutes();
	_seconds = t.seconds();
	return *(this);
}
Time::Time(const unsigned int s, const unsigned int m, const unsigned int h): _seconds(s), _minutes(m), _hours(h){
	normalizeTime();
	return;
}
Time::Time(const Time& t) : _seconds(t.seconds()), _minutes(t.minutes()), _hours(t.hours()) {
	normalizeTime();
	return;
}
ostream& operator<<(ostream& os, const Time& t) {
	os << "(" << t.hours() << ":" << t.minutes() << ":" << t.seconds() << ")";
	return os;
}

void Timer(Time t) {
	Time timeGone = Time();
	cout << "Timer: " << t << endl;
	while ((int)t != 0) {
		Sleep(1000);
		t=(int)t-1;
		cout << "Left: " << t << endl;
	}
	cout << "Timer end" << endl;
}

void Watch(Date d, Time t) {
	if (d < Date()) {
		cout << "Error. Date must be in future" << endl;
		return;
	}
	if ((int)t > (int)Time(59,59,23)) {
		cout << "Error. Time must be from 00:00:00 to 23:59:59!" << endl;
		return;
	}
	Time now;
	time_t timer;
	time(&timer);
#pragma warning(suppress : 4996)
	struct tm* today = localtime(&timer);
	now.setSeconds(today->tm_sec);
	now.setMinutes(today->tm_min);
	now.setHours(today->tm_hour);
	if (d == Date() && (int)t < (int)now) {
		cout << "Error. Time must be in future" << endl;
		return;
	}
	cout << "Watch start in: " << Date() << " " << now << endl;
	cout << "Watch will end in: " << d << " " << t << endl;
	while (Date() != d) {
	}
	do {
		time(&timer);
#pragma warning(suppress : 4996)
		struct tm* today = localtime(&timer);
		now.setSeconds(today->tm_sec);
		now.setMinutes(today->tm_min);
		now.setHours(today->tm_hour);
	} while ((int)now!= (int)t);
	cout << "Watch end in: " << d << now << endl;
}