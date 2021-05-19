#pragma once
#include "Employee.h"


class Staff :public Employee /*Abstract Class*/
{
protected:
	/*Variables*/
	bool hasCertification;
	int experience; /*In years*/

public:
	/*Constructors*/
	Staff();
	Staff(bool certification, int experience, long id, string name, float salary, Date dateOfEmployment);
	/*Destructor*/
	virtual ~Staff() {}
	/*Methods*/
	virtual ostream& generalEmployeeInfo(ostream& out) const = 0;

	/*Sets*/
	void setExperience(int experience)throw(...);
	void setHasCertification(bool certification) { this->hasCertification = certification; }
	
	/*Gets*/
	int getExperience() const { return this->experience; }
	bool getHasCertification() const { return this->hasCertification; }
};

