#pragma once
#include "Employee.h"
#include "Management.h"
#include "Staff.h"
#include "StaffManager.h"
#include "Instructor.h"
#include "LifeGuard.h"
#include "Templates.h"
#include <algorithm>
#include <iomanip>
class CountryClub
{
private:
	/*Variables*/
	list<Management*> managerList; /*STL for Class Contains*/
	string branch;

	void insertEmployee(Staff& emp, string name); /*Access only from CountryClub Methods*/
	void insertEmployee(Management& emp);

public:
	/*Constructors*/
	CountryClub();
	CountryClub(string address);
	/*Destructor*/
	~CountryClub();
	/*Methods*/

	/*Gets*/
	string getAddress() { return this->branch; }
	float getTotalEmployeeWageExpense() const;
	/*Sets*/
	void setAddress(string address) { this->branch = address; }

	/*Container Methods*/
	bool isExists(Employee& emp);
	void insertEmployee(Employee& emp);
	Employee& searchEmployee(long id);
	Employee& searchEmployee(string name);
	void removeByID(long id);

	/*Operators*/
	friend ostream& operator<<(ostream& out, const CountryClub& obj);
};

