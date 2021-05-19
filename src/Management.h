#pragma once
#include "Employee.h"
class Management : public Employee /*Abstract Class*/
{
protected:
	/*Variables*/
	bool hasOffice;
	bool hasCar;

public:
	/*Constructors*/
	Management();
	Management(long id, string name, float salary, Date, bool office, bool car);
	Management(long id, string name, float salary, Date);
	/*Destructor*/
	virtual ~Management() {}

	/*Methods*/
	virtual ostream& generalEmployeeInfo(ostream& out) const = 0;

	/*Sets*/
	void setHasOffice(bool hasOffice) { this->hasOffice = hasOffice; }
	void setHasCar(bool hasCar) { this->hasCar = hasCar; }

	/*Gets*/
	bool getHasOffice() const { return this->hasOffice; }
	bool getHasCar() const { return this->hasCar; }
};

