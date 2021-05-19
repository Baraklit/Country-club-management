#include "Employee.h"

/*Constructors*/
Employee::Employee() : ID(0), name("Empty"), wage(0)
{
	Date def(1, 1, 2000); //def==Default
	dateOfEmployment = def;
}
Employee::Employee(long id, string name, float salary, Date dateOfEmployment)
{
	setID(id);
	setName(name);
	setWage(salary);
	setDateOfEmployment(dateOfEmployment);
}
Employee::Employee(long id, string name, float salary) 
{ 
	Date temp;
	setID(id);
	setName(name);
	setWage(salary);
	setDateOfEmployment(temp);
}

/*Methods*/

/*Sets*/
void Employee::setID(long id)
{
	this->ID = id;
}
void Employee::setName(string name)
{
	if (validateString(name))
		this->name = name;
	else
		throw exception("Error Name: Invalid String ");
}
void Employee::setWage(float salary)
{
	if (negativeNumber<float>(salary))
		throw exception ("Error Wage: Negative Number ");

	this->wage = salary;
}
void Employee::setDateOfEmployment(Date dateOfEmployment)
{
	this->dateOfEmployment = dateOfEmployment;
}

bool Employee::validateString(string str)
{
	/*Check if the string is empty*/
	if (str.empty()) 
		return false;
	/*Search for digits in the string*/
	for (unsigned int index = 0; index < str.size(); index++)
	{
		if (str[index] >= '0' &&str[index] <= '9')
			return false;
	}
	
	return true; //The string is proper
}

/*Operators*/
ostream& operator<<(ostream& out, const Employee& obj)
{
	out << "Name: " << obj.getName() << endl << "ID: " << obj.getID() << endl << "Date of Employment: " << obj.getDateOfEmployment()
		<< "	Salary: " << obj.getWage() << endl;
	obj.generalEmployeeInfo(out);
	return out;
}

bool Employee::operator==(const Employee& obj) const
{
	if (this->ID == obj.getID())
		return true;

	return false;
}

bool Employee::operator<(const Employee &obj) const
{
	return this->getWage() > obj.getWage();
	/* > Cause the sort is High to Low */
}

