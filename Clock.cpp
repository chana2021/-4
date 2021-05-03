#include "Clock.h"
//#include<string>
//#include <iostream>
#include <cstring>
using namespace std;
Clock:: Clock(int x) {
	hour = x;
	minute = 0;
	second = 0;
}
void Clock::setHour(int myHour) {
	hour = myHour;
}
void Clock::setMinute(int myMinuye) {
	minute = myMinuye;
}
void Clock::setSecond(int mySecond) {
	second = mySecond;
}
int Clock::getHour() { return hour; }
int Clock::getMinute() { return minute; }
int Clock::getSecond() { return second; }
Clock::Clock() {//1.	default
	hour = 00;
	minute = 00;
	second = 00;
}
Clock:: ~Clock() {
	hour = 00;
	minute = 00;
	second = 00;
}
Clock:: Clock(int myHour, int myMinute, int mySecond) {
	if (myHour > 23) {
		hour = 00;
		minute = 00;
		second = 00;
		cout << "Invalid time - more than 24 hours." << endl;
	}
	if (myHour < 0) {
		hour = 00;
		minute = 00;
		second = 00;
		cout << "Invalid time - negative number of hours." << endl;
	}
	if ((myHour < 24) && (myHour > 0))//true
		hour = myHour;
	
	if (myMinute > 59) {
		hour = 00;
		minute = 00;
		second = 00;
		cout << "Invalid time - more than 60 minutes." << endl;
	}	
	if (myMinute < 0)
	{
		hour = 00;
		minute = 00;
		second = 00;
		cout << "Invalid time - negative number of minutes." << endl;
	}
	
	if((myMinute>0)&&(myMinute<60))//true
		minute = myMinute;
	
	if (mySecond > 59) {
		hour = 00;
		minute = 00;
		second = 00;
		cout << "Invalid time - more than 60 seconds." << endl;
	}
	if (mySecond < 0)
	{
		hour = 00;
		minute = 00;
		second = 00;
		cout << "Invalid time - negative number of seconds." << endl;
	}

	if ((mySecond > 0) && (mySecond < 60))//true
		second = mySecond;
}
Clock::Clock(const Clock& ms) //copy constructor
{
	
	hour = ms.hour;
	minute = ms.minute;
	second = ms.second;
}
Clock& Clock:: operator+=(const int mySecond) {
	int min, sec, ho;
	ho = mySecond / 60 / 60;
	min = mySecond- ho* 3600;
	min /= 60;
	sec = mySecond - min * 60- ho * 3600;
	int ezer = sec + second;
	if (ezer > 59) {
		second = ezer - 60;
		minute++;
	}
	else
		second += sec;
	if (minute + min > 59) {
		minute = minute + min - 60;
		hour++;
	}
	else
		minute += min;
	if (hour + ho > 23) {
		hour = hour + ho - 24;
	}
	else
		hour += ho;
	return *this;
}

ostream& operator<<(ostream& os, const Clock& r)//pelet
{
	if (r.hour<9)
		os<<"0" << r.hour <<":";
	else
		os<< r.hour << ":";
	if (r.minute<9)
		os << "0" << r.minute << ":";
	else
		os << r.minute << ":";
	if (r.second <9)
		os << "0" << r.second;
	else
		os << r.second ;
	return os;
}
 istream& operator>>(istream& is, Clock& r)//
{
	
	is >> r.hour;
	if (r.hour > 23) {
		r.hour = 0;
		cout << "Invalid time - more than 24 hours." << endl;
	}
	if (r.hour < 0) {
		r.hour = 0;
		cout << "Invalid time - negative number of hours." << endl;
	}
	
	is >> r.minute;
	if (r.minute > 59) {
		r.minute = 0;
		cout << "Invalid time - more than 60 minutes." << endl;
	}
	if (r.minute < 0)
	{
		r.minute = 0;
		cout << "Invalid time - negative number of minutes." << endl;
	}

	
	is >> r.second;
	if (r.second > 59) {
		r.second = 0;
		cout << "Invalid time - more than 60 seconds." << endl;
	}
	if (r.second < 0)
	{
		r.second = 0;
		cout << "Invalid time - negative number of seconds." << endl;
	}
	return is;
}