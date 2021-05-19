#include "StaffManager.h"

/*Constructors*/
StaffManager::StaffManager() : Management(), managedEmployees() {}
StaffManager::StaffManager(long ID, string Name, float Salary, Date dateOfEmployment, bool car, bool office, string department) :
	Management(ID, Name, Salary, dateOfEmployment, car, office), managedEmployees() 
{
	setDepartment(department);
}
/*Destructor*/
StaffManager::~StaffManager()
{
	managedEmployees.clear();
}

/*Sets*/
void StaffManager::setDepartment(string department)
{
	if (validateString(department))
		this->department = department;
	else
		throw exception("Error Department: Invalid String ");
}

/*Methods*/
ostream& StaffManager::generalEmployeeInfo(ostream& out) const
{
	out << "Staff Manager of " << getDepartment() << endl;
	if (getHasCar() && getHasOffice())
		out << "He has a car and an office!" << endl;
	else if (!getHasCar() && getHasOffice())
		out << "He has a office" << endl;
	else if (getHasCar() && !getHasOffice())
		out << "He has a car" << endl;
	return out;
}

void StaffManager::printMyEmployees()
{
	/*if The list is empty*/
	if (this->managedEmployees.empty()) 
	{ 
		cout << this->getName() << " Has No Employees!" << endl << endl;
		return;
	}

	list<Staff*>::iterator iter = this->managedEmployees.begin();
	for (; iter!= this->managedEmployees.end(); iter++)
		cout << **iter;
}

void StaffManager::removeMyEmployee(Staff& emp)
{
	if (managedEmployees.empty()) /*list is empty!*/
		return;
	
	managedEmployees.remove(&emp);
}

Staff& StaffManager::searchEmployee(long id)
{
	Staff* temp = NULL; /*return null when id no found or list is empty*/
	if (managedEmployees.empty())
		throw exception("The List Is Empty!");
	else
	{
		list<Staff*>::iterator iter = this->managedEmployees.begin();
		for (; iter != managedEmployees.end(); iter++)
		{
			if ((*iter)->getID() == id)
				return **iter;
		}
		throw exception("The employee does not exsists");
	}

	return *temp;


}

Staff& StaffManager::searchEmployee(string name)
{
	Staff* temp = NULL; /*return null when id no found or list is empty*/
	if (managedEmployees.empty())
		throw exception("The List Is Empty!");

	else
	{
		list<Staff*>::iterator iter = this->managedEmployees.begin();
		for (; iter != managedEmployees.end(); iter++)
		{
			if ((*iter)->getName() == name)
				return **iter;
		}
		throw exception("The employee does not exsists");
	}
	return *temp;
}

void StaffManager::increaseEmployeeWage(int increaseAmount, long id)
{
	try 
	{
		Staff *emp = &this->searchEmployee(id);
		emp->setWage(emp->getWage() + increaseAmount);
	}
	catch(exception ex)
	{
		cout << ex.what();
	}
	
}

void StaffManager::increaseEmployeeWage(int increaseAmount, string name)
{
	try
	{
		Staff *emp = &this->searchEmployee(name);
		emp->setWage(emp->getWage() + increaseAmount);
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
}

float StaffManager::getTotalEmployeesWage() const 
{
	float sum = this->getWage();
	
		list<Staff*>::const_iterator iter = this->managedEmployees.begin();
		for (; iter != managedEmployees.end(); iter++)
		{
			sum += (*iter)->getWage();
		}
	
		return sum;
}

void StaffManager::sortMyEmployeesByWage()
{
	if (this->managedEmployees.empty())/*Sort Employees By Wage*/
		throw exception("The List is Empty!");

	this->managedEmployees.sort(PComp<Staff>);
	cout << "Done!		Sort High->Low" << endl;
}


bool StaffManager::operator==(const Employee& obj) const
{
	if (Employee::operator==(obj))
	{
		auto SM = static_cast<const StaffManager*>(&obj);
		if (SM->getDepartment()==this->getDepartment())
		{
			return true;
		}
	}
	return false;
}
