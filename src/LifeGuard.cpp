#include "LifeGuard.h"
/*Constructors*/
LifeGuard::LifeGuard() :Staff(), swimmingInstructor(false) 
{
	setHasCertification(true); //Life guard must have certification
}
LifeGuard::LifeGuard(int experience, long id, string name,
	float salary, Date dateOfEmployment, bool swimmingInstructor)
	: Staff(true, experience, id, name, salary, dateOfEmployment), swimmingInstructor(swimmingInstructor) {}

/*Methods*/
ostream& LifeGuard::generalEmployeeInfo(ostream& out) const
{
	out << "Experience: " << getExperience() << " Years" << endl;
	out << "Job: Life guard";
	if (getSwimmingInstructor())
		out << " and swimming instructor";
	out << "." << endl << endl;
	return out;
}

bool LifeGuard::operator==(const Employee& obj) const
{
	if (Employee::operator==(obj))
	{
		auto SM = static_cast<const LifeGuard*>(&obj);
		if (SM->getSwimmingInstructor() == this->getSwimmingInstructor())
		{
			return true;
		}
	}
	return false;
}