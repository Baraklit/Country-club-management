#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <typeinfo>
#include "Date.h"
#include "Templates.h"
using namespace std;

class Employee /*Abstract Class*/
{
protected:
	/*Variables*/
	float wage;
	long ID;
	string name;
	Date dateOfEmployment;

public:

	/*Constructors*/
	Employee();
	Employee(long, string, float, Date);
	Employee(long, string, float);
	
	/*Destructor*/
	virtual ~Employee() {}
	/*Methods*/
	bool validateString(string str);
	virtual ostream& generalEmployeeInfo(ostream& out) const = 0;
	/*Sets*/

	void setID(long id);
	void setName(string name)throw(...);
	void setWage(float wage)throw(...);
	void setDateOfEmployment(Date dateOfEmployment);

	/*Gets*/
	long getID() const { return this->ID; }
	string getName() const { return this->name; }
	float getWage() const { return this->wage; }
	Date getDateOfEmployment() const { return this->dateOfEmployment; }

	/*Operators*/
	friend ostream& operator<<(ostream& out, const Employee& obj);
	virtual bool operator==(const Employee& obj) const;
	virtual bool operator<(const Employee &obj) const;


};
