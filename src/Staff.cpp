#include "Staff.h"
/*Constructors*/
Staff::Staff() : Employee(),hasCertification(false), experience(0){}
Staff::Staff(bool certification, int experience, long id, string name, float salary, Date dateOfEmployment) :
	Employee(id, name, salary, dateOfEmployment), hasCertification(certification)
{
	setExperience(experience);
}

void Staff::setExperience(int experience)
{
	if (negativeNumber<int>(experience))
		throw exception("Error : Experience Negative number");

	this->experience = experience;
}




