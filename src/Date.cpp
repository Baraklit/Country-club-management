#include "Date.h"
/*Constructors*/
Date::Date()  
{
	time_t now = time(0);      
	tm *ltm = localtime(&now);
	/*Create current date*/
	day = ltm->tm_mday;
	month = ltm->tm_mon + 1;
	year = ltm->tm_year + 1900;
}
Date::Date(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

/*Methods*/
/*Sets*/
void Date::setDay(int day)
{
	if (day > 31 || day < 1)
		throw exception("Invalid day, Please try again");
	
	this->day = day;
}
void Date::setMonth(int month)
{
	if (month > 12 || month < 1)
		throw exception("Invalid month, Please try again");
	else
	this->month = month;
}
void Date::setYear(int year) 
{
	time_t now = time(0);      /*Cannot assign future year!*/
	tm *ltm = localtime(&now);

	if (year > (1900 + ltm->tm_year) || year < 1900)
		throw exception("Invalid year, Please try again");

	this->year = year;
}
/*Operators*/
ostream& operator <<(ostream& out, const Date& obj)
{
	out << obj.getDay() << "." << obj.getMonth() << "." << obj.getYear();
	return out;
}

Date& Date::operator=(const Date& obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;

	return *this;
}


