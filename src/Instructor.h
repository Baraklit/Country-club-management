#pragma once
#include "Staff.h"
class Instructor :public Staff
{
private:
	/*Variables*/
	bool gymInstructor;
	bool classInstructor;

public:
	/*Constructors*/
	Instructor();
	Instructor(int experience, long id, string name,
		float salary, Date dateOfEmployment, bool gym, bool certification = true, bool classTrainer = true);
	/*Destructor*/
	virtual ~Instructor(){}
	/*Methods*/
	virtual ostream& generalEmployeeInfo(ostream& out) const;
	/*Gets*/
	bool getGymIInstructor() const { return this->gymInstructor; }
	bool getClassInstructor() const { return this->classInstructor; }
	/*Sets*/
	void setGymIInstructor(bool gymInstructor) { this->gymInstructor = gymInstructor; }
	void setClassInstructor(bool classInstructor) { this->classInstructor = classInstructor; }

	/*Operators*/
	virtual bool operator==(const Employee& obj) const;

};


