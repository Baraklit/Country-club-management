#pragma once
#include "Management.h"
#include "Employee.h" /*For The Container!*/
#include "Staff.h" /*For The Container!*/
#include <list>
#include <iterator>
#include <algorithm>

class StaffManager : public Management
{
private:
	/*Variables*/
	string department;
	list<Staff*> managedEmployees; /* List of employees under the staff manager */

public:
	/*Constructors*/
	StaffManager();
	StaffManager(long id, string name, float salary, Date dateOfEmployment, bool car, bool office, string department);
	
	/*Destructor*/
	~StaffManager();
	
	/*Methods*/
	virtual ostream& generalEmployeeInfo(ostream& out) const;
	
	/*Gets*/
	list<Staff*> * getList() { return &managedEmployees; }
	string getDepartment() const { return this->department; }

	/*Sets*/
	void setDepartment(string department)throw(...);
	float getTotalEmployeesWage() const;

	/*List Of Employees Methods*/
	void privateInsert(Staff& emp) { managedEmployees.push_back(&emp); }
	void printMyEmployees(); 
	void removeMyEmployee(Staff& emp);
	void clearMyList() { managedEmployees.clear(); }
	Staff& searchEmployee(long id)throw(...);
	Staff& searchEmployee(string name)throw(...);
	void increaseEmployeeWage(int increaseAmount, long id);
	void increaseEmployeeWage(int increaseAmount, string name);
	void sortMyEmployeesByWage()throw(...);
	/*Operators*/
	virtual bool operator==(const Employee& obj) const;

};

