#pragma once
#include "Staff.h"
class LifeGuard :public Staff
{
private:
	/*Variables*/
	bool swimmingInstructor;

public:
	/*Constructors*/
	LifeGuard();
	LifeGuard(int experience, long id, string name,
		float salary, Date dateOfEmployment, bool swimmingInstructor);

	/*Destructor*/
	virtual ~LifeGuard(){}
	/*Methods*/
	virtual ostream& generalEmployeeInfo(ostream& out) const;
	/*Sets*/
	void setSwimmingInstructor(bool swimmingInstructor) { this->swimmingInstructor = swimmingInstructor; }
	/*Gets*/
	bool getSwimmingInstructor() const { return this->swimmingInstructor; }
	/*Operators*/
	virtual bool operator==(const Employee& obj) const;

};

