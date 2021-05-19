#include "Instructor.h"
/*Constructors*/
Instructor::Instructor() :Staff(), classInstructor(false), gymInstructor(true){}
Instructor::Instructor(int experience, long id, string name,
	float salary, Date dateOfEmployment, bool gym, bool certification, bool classTrainer)
	: Staff(certification, experience, id, name, salary, dateOfEmployment), classInstructor(true), gymInstructor(gym) {}

/*Methods*/
ostream& Instructor::generalEmployeeInfo(ostream& out) const
{
	out << "Experience: " << getExperience() << " Years" << endl;
	out << "Job: ";
	if (getClassInstructor() && getGymIInstructor())
		out << "Gym Trainer and Class Instructor.";
	else
		out << "Class Instructor.";
	out << endl;
	return out;

}

bool Instructor::operator==(const Employee& obj) const
{
	if (Employee::operator==(obj))
	{
		auto SM = static_cast<const Instructor*>(&obj);
		if (SM->getClassInstructor() == this->getClassInstructor())
		{
			return true;
		}
	}
	return false;
}