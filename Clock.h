#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
using namespace std;
class Clock
{
	int hour=00;
	int minute=00;
	int second=00;
	void setHour(int myHour);
	void setMinute(int myMinuye);
	void setSecond(int mySecond);

public:
	Clock(int x);
	int getHour();
	int getMinute();
	int getSecond();
	Clock(); //.Constructors
	~Clock();//destructor
	Clock(int myHour,int myMinute,int mySecond);//Constructors
	Clock(const Clock& ms); //copy constructor
	Clock& operator+=(const int mySecond);//+=
	friend ostream& operator<<(ostream& os, const Clock& r);
	friend istream& operator>>(istream& is, Clock& r);



};