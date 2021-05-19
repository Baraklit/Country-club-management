#include "CountryClub.h"

using namespace std;


/*Constructors*/
CountryClub::CountryClub() :branch("Unknown"), managerList() {}
CountryClub::CountryClub(string address) : managerList(), branch(address) {}

CountryClub::~CountryClub()
{
	list<Management*>::iterator iter = this->managerList.begin();
	for (; iter != managerList.end(); iter++)
	{
		delete *iter;
	}
}

bool CountryClub::isExists(Employee& emp)
{
	try 
	{
		if (&searchEmployee(emp.getID()) == NULL) /*Return null if not exists*/
			return false;
		
		return true;
	}
	catch (exception ex){ return false; }
	
}

void CountryClub::insertEmployee(Employee& emp)
{
	if (isExists(emp))
		throw exception("Employee Already Exists!");

	StaffManager *sm = dynamic_cast<StaffManager*>(&emp);
	if (sm)
		insertEmployee(*sm);
	else
	{
		string name;
		Staff *s = dynamic_cast<Staff*>(&emp);

		cout << "Manager Name: ";
		cin.ignore();
		getline(cin, name);
		try
		{
			insertEmployee(*s, name);
		}
		catch(exception ex)
		{
			throw ex;
		}
	}
}

void CountryClub::insertEmployee(Management& emp)
{
	this->managerList.push_back(&emp); /*insert new Staff Manager to the list of Staff Managers*/
}

void CountryClub::insertEmployee(Staff& emp, string name)
{
	if (managerList.empty())
		throw exception("No Registered Managers!"); /*Cant insert new Employee with Staff Manager*/
	else
	{
		list<Management*>::iterator iter = this->managerList.begin();
		for (; iter != managerList.end(); iter++)
		{
			if ((*iter)->getName() == name)
				break;
		}

		if (iter == managerList.end())
			throw exception("Manager Does Not Exists");
		
		((StaffManager*)(*iter))->privateInsert(emp);
	}
}

Employee& CountryClub::searchEmployee(long id)
{
	Employee *emp = NULL; /*Return NULL if the employee not found*/
	
	if (managerList.empty())
		throw exception("The List Is Empty!");

	else
	{	/*Search Staff Manager*/
		list<Management*>::iterator iterManagers = this->managerList.begin();
		for (; iterManagers != managerList.end(); iterManagers++)
		{
			if ((*iterManagers)->getID() == id)
				emp = *iterManagers;

			else
			{	/*Search Employee in Staff Manager list*/
				list<Staff*> *tempList = ((StaffManager*)(*iterManagers))->getList();
				if (!tempList->empty())
				{
					list<Staff*>::iterator iterStaff = tempList->begin();
					for (; iterStaff != tempList->end(); iterStaff++)
					{
						if ((*iterStaff)->getID() == id)
							emp = *iterStaff;
					}
				}
			}
		}
	}

	return *emp;
}

void CountryClub::removeByID(long id)
{
	Employee *emp = &searchEmployee(id);

	StaffManager *sm = dynamic_cast<StaffManager*>(emp); /*if we need to remove the Staff Manager*/
	if (sm)
	{
		if (this->managerList.size() == 1) 
			throw exception("There is one manager, Cannot leave employees without manager");
		
		long idOfNewManager;
		cout << "You need to transfer the employees to another manager list!" << endl << "Insert Manager ID : ";
		cin >> idOfNewManager;
		StaffManager* newSm = dynamic_cast<StaffManager*>(&searchEmployee(idOfNewManager));
		if (newSm)	
		{
			newSm->getList()->merge(*sm->getList()); /*Merging the list of the Staff Manager that will remove*/
			this->managerList.remove(sm);/*Remove the Staff Manager */
		}
		else
			throw exception("Cannot Find The New Manager, Please Try Again!");
		return;
	}

	Staff *st = dynamic_cast<Staff*>(emp); /*Remove Employee*/
	if (st)
	{
		list<Management*>::iterator iterManagers = this->managerList.begin();
		for (; iterManagers != managerList.end(); iterManagers++)/*Search The Manager Of the Employee*/
		{
			list<Staff*>::iterator iterStaff = ((StaffManager*)(*iterManagers))->getList()->begin();
			/*The Casting is ok because its Management List*/
			for (; iterStaff != ((StaffManager*)(*iterManagers))->getList()->end(); iterStaff++)
			{
				if ((*iterStaff)->getID() == id) /*Find The Employee under the Staff Manager*/
				{
					((StaffManager*)(*iterManagers))->getList()->remove(*iterStaff);
					/*Remove is also call to destructor*/
					return;
				}
			}
		}
	}
}

Employee& CountryClub::searchEmployee(string name)
{
	Employee *emp = NULL; /*Return NULL if the employee not found*/

	if (managerList.empty())
		throw exception("The List Is Empty!");

	else
	{	/*Search Staff Manager*/
		list<Management*>::iterator iterManagers = this->managerList.begin();
		for (; iterManagers != managerList.end(); iterManagers++)
		{
			if ((*iterManagers)->getName() == name)
				emp = *iterManagers;

			else
			{	/*Search Employee in Staff Manager list*/
				list<Staff*> *tempList = ((StaffManager*)(*iterManagers))->getList();
				if (!tempList->empty())
				{
					list<Staff*>::iterator iterStaff = tempList->begin();
					for (; iterStaff != tempList->end(); iterStaff++)
					{
						if ((*iterStaff)->getName() == name)
							emp = *iterStaff;
					}
				}
			}
		}
	}

	return *emp;
}

float CountryClub::getTotalEmployeeWageExpense() const
{	/*Calculate the Wages of all employees*/
	float sum = 0.0;
	
	list<Management*>::const_iterator iterManagers = this->managerList.begin();
	for (; iterManagers != managerList.end(); iterManagers++)
	{
		sum += ((StaffManager*)(*iterManagers))->getTotalEmployeesWage();
	}

	return sum;
}

/*Operators*/
ostream& operator<<(ostream& out, const CountryClub& obj)
{
	list<Management*>::const_iterator iterManagers = obj.managerList.begin();
	for (; iterManagers != obj.managerList.end(); iterManagers++)
	{
		out << **iterManagers << endl; /*Print StaffManager Info*/
		/*No need dynamic cast*/
		((StaffManager*)(*iterManagers))->printMyEmployees();
	}
	
	return out;
}