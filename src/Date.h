#ifndef DATE_H
#define DATE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Date
{
private:
	/*Variables*/
	int day;
	int month;
	int year;

public:
	/*Constructors*/
	Date();
	Date(int day, int month, int year);
	/*Desturctor*/
	~Date(){}
	/*Methods*/
	/*Sets*/
	void setDay(int)throw(...);
	void setMonth(int)throw(...);
	void setYear(int)throw(...);
	
	/*Gets*/
	int getDay() const { return this->day; }
	int getMonth() const { return this->month; }
	int getYear() const { return this->year; }

	/*Operators*/
	friend ostream& operator <<(ostream& out,const Date& obj);
	Date& operator=(const Date& obj);

};
#endif
