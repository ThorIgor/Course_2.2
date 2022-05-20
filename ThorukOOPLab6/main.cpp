#include "Time.h"



void main() {
	Timer(Time(5, 0, 0));

	Watch(Date(1,1,1999), Time(0,0,0));	
	Watch(Date(), Time(0,0,25));
	Watch(Date(), Time(0,0,0));

	Time now;
	time_t timer;
	time(&timer);
#pragma warning(suppress : 4996)
	struct tm* today = localtime(&timer);
	time(&timer);

	now.setHours(today->tm_hour);
	now.setMinutes(today->tm_min);
	now.setSeconds(today->tm_sec + 10);

	Watch(Date(), now);
}