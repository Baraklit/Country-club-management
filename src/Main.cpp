#include "CountryClub.h"
#include <cstdlib>

#define PAUSE system("pause")

void mainMenu(); /*Menu*/
void staffManagerMenu(StaffManager &sm); /*Staff Manager Menu*/
void managerMenu(CountryClub &cc); /*Country Club Manager Menu*/
void employeeSearch(CountryClub &cc); /*Search Employee in CountryClub*/
void employeeSearch(StaffManager &sm, bool wageFlag = false); /*Search Employee for Staff Manager*/
void addEmployee(CountryClub &cc); /*Insert Employee to country club*/
Employee& newEmployee(int selection); /*Create new Object with proper value*/

int main()
{
	mainMenu();

	return 0;
}

void mainMenu()
{
	CountryClub cc("Pardesiya");
	StaffManager *sm;

	int selection;
	do {
		system("cls");
		cout << "Welcome to "<<cc.getAddress()<<" Country Club" << endl
			<< "Please Select The Relevant Menu:" << endl
			<< "1. Manager" << endl
			<< "2. Staff Manager" << endl
			<< "3. Exit" << endl
			<< "Selection : ";
		cin >> selection;

		switch (selection)
		{
		case 1:
			managerMenu(cc);
			break;
		case 2:
			long id;
			cout << "Please enter your id: ";
			cin >> id;
			try
			{
				sm = dynamic_cast<StaffManager*>(&cc.searchEmployee(id));
				if (sm)
					staffManagerMenu(*sm);
				else
					throw exception("Access Denied!"); /*If The Staff Manager Not Exsits*/
			}
			catch (exception ex)
			{
				cout << ex.what() << endl;
				PAUSE;
			}

			break;
		case 3:
			exit(0);
		default:
			cout << "Invalid Selection!" << endl;
			break;
		}
	} while (true);

}

void staffManagerMenu(StaffManager &sm)
{
	bool wageFlag = true;
	int selection;
	do {
		system("cls");
		cout << "Staff Manager Menu" << endl
			<< "Please Select The Relevant Action:" << endl
			<< "1. Search Employee" << endl
			<< "2. Increase Employee Wage" << endl
			<< "3. Print Employee List" << endl
			<< "4. Sort My Employees List By Wage" << endl
			<< "5. Exit" << endl
			<< "Selection : ";
		cin >> selection;


		switch (selection)
		{
		case 1:
			employeeSearch(sm);
			PAUSE;
			break;
		case 2:
			employeeSearch(sm, true);
			PAUSE;
			break;
		case 3:
			sm.printMyEmployees();
			PAUSE;
			break;
		case 4:
			try { sm.sortMyEmployeesByWage(); }
			catch (exception ex) { cout << ex.what() << endl; }
			PAUSE;
			break;
		case 5:
			return;
		default:
			cout << "Invalid Selection!" << endl;
			PAUSE;
			break;
		}
	} while (true);

}

void managerMenu(CountryClub &cc)
{
	int selection;

	do {
		system("cls");
		cout << "Manager Menu" << endl
			<< "Please Select The Relevant Action:" << endl
			<< "1. Add New Employee " << endl
			<< "2. Remove Employee by ID" << endl
			<< "3. Search Employee" << endl
			<< "4. Total Expense on Wages Report" << endl
			<< "5. Print Employee List" << endl
			<< "6. Exit" << endl
			<< "Selection : ";
		cin >> selection;

		switch (selection)
		{
		case 1:
			addEmployee(cc);
			PAUSE;
			break;
		case 2:
		{
			long id;
			cout << "Please Enter Employee's ID: ";
			cin >> id;

			try
			{
				cc.removeByID(id); /*Remove only by id beacuse its Unique identify*/
			}
			catch (exception ex)
			{
				cout << ex.what() << endl;
			}
			PAUSE;
			break;
		}
		case 3:
		{
			employeeSearch(cc);
			PAUSE;
			break;
		}
		case 4:
			cout << "The total expense on wages for all employees a month is: " << cc.getTotalEmployeeWageExpense() << endl;
			PAUSE;
			break;
		case 5:
			system("cls");
			cout << cc;
			PAUSE;
			break;
		case 6:
			PAUSE;
			return;
		default:
			cout << "Invalid Selection!" << endl;
			PAUSE;
			break;
		}
	} while (true);

}

void employeeSearch(CountryClub &cc)
{
	string name;
	long id;
	int selection;

	system("cls");

	cout << "Which parameter would you like to use?" << endl
		<< "1. Search by ID" << endl
		<< "2. Search by Name" << endl;
	cin >> selection;

	switch (selection)
	{
	case 1:
		cout << "Please enter ID to search: ";
		cin >> id;
		try
		{
			cout << cc.searchEmployee(id) << endl;
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
		}
		break;

	case 2:
		cout << "Please enter name to search: ";
		cin.ignore();
		getline(cin, name);
		try
		{
			cout << cc.searchEmployee(name) << endl;
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
		}
		break;
	default:
		cout << "Invalid Selection!" << endl;
		break;
	}

}

void employeeSearch(StaffManager &sm, bool wageFlag)
{
	string name;
	long id;
	int selection;

	system("cls");

	cout << "Which parameter would you like to use?" << endl
		<< "1. Search by ID" << endl
		<< "2. Search by Name" << endl;
	cin >> selection;
	cin.clear();
	switch (selection)
	{
	case 1:
		cout << "Please enter ID to search: ";
		cin >> id;
		try
		{
			if (wageFlag)
			{
				int wage;
				cout << "Please enter the amount of the raise: ";
				cin >> wage;
				sm.increaseEmployeeWage(wage, id);
			}
			else
				cout << sm.searchEmployee(id) << endl;
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
		}

		break;

	case 2:
		cout << "Please enter name to search: ";
		cin >> name;
		try
		{
			if (wageFlag)
			{
				int wage;
				cout << "Please enter the amount of the raise: ";
				cin >> wage;
				cin.clear();
				sm.increaseEmployeeWage(wage, name);
			}
			else
				cout << sm.searchEmployee(name) << endl;
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
		}
		break;
	default:
		cout << "Invalid Selection!" << endl;

		break;
	}
}

void addEmployee(CountryClub &cc)
{
	int selection;
	Employee* newEmp;

	system("cls");
	cout << "Add Employee Menu" << endl
		<< "Which employee type you want to add?" << endl
		<< "1. Lifeguard" << endl
		<< "2. Instructor" << endl
		<< "3. StaffManager" << endl
		<< "4. Exit" << endl
		<< "Selection : ";
	cin >> selection;
	try
	{
		switch (selection)
		{
		case 1:
			newEmp = dynamic_cast<LifeGuard*>(&newEmployee(selection));
			if (newEmp)
				cc.insertEmployee(*newEmp);
			break;
		case 2:
			newEmp = dynamic_cast<Instructor*>(&newEmployee(selection));
			if (newEmp)
				cc.insertEmployee(*newEmp);
			break;
		case 3:
			newEmp = dynamic_cast<StaffManager*>(&newEmployee(selection));
			if (newEmp)
				cc.insertEmployee(*newEmp);
			break;
		case 4:
			return;
		default:
			cout << "Invalid Selection!" << endl;

			PAUSE;
			break;
		}
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
}

Employee& newEmployee(int selection)
{
	Employee* newEmployee = NULL;
	long id = 0;
	float wage = 0.0;
	string name, department;
	Date dateOfEmployment;
	bool hasCertificate = false, isInstructor = true, isGym = false, whileFlag = false, isOk = false,
		hasCar = false, hasOffice = false;
	int exp;
	char ch;

	system("cls");
	do
	{
		cout << "Please enter ID: ";
		cin >> id;
		cout << "Please enter Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Please enter his wage: ";
		cin >> wage;

		switch (selection)
		{
	case 1:	/*LifeGuard*/
		cout << "Please enter his experience (In years): ";
		cin >> exp;
		cout << name << " Is Also An Instructor? (Y/N): ";
		cin >> ch;

		isInstructor = (ch == 'y' || ch == 'Y') ? true : false;

		try
		{
			newEmployee = new LifeGuard(exp, id, name, wage, dateOfEmployment, isInstructor);
			isOk = true;
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
			PAUSE;
		}
		break;
	case 2:/*Instructor*/
		cout << "Please enter his experience (In years): ";
		cin >> exp;

		cout << name << " Is Also An Gym Trainer? (Y/N): ";
		cin >> ch;

		isGym = (ch == 'y' || ch == 'Y') ? true : false;

		cout << name << " Is Also An Class Trainer? (Y/N): ";
		cin >> ch;

		isInstructor = (ch == 'y' || ch == 'Y') ? true : false;

		try
		{
			newEmployee = new Instructor(exp, id, name, wage, dateOfEmployment, isGym);
			isOk = true;
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
			PAUSE;
		}
		break;
	case 3:/*StaffManager*/

		cout << "Please enter department: ";
		cin.ignore();
		getline(cin, department);

		cout << name << " Does the manager has a car? (Y/N): ";
		cin >> ch;

		hasCar = (ch == 'y' || ch == 'Y') ? true : false;

		cout << name << " Does the manager has an office? (Y/N): ";
		cin >> ch;

		hasOffice = (ch == 'y' || ch == 'Y') ? true : false;

		try
		{
			newEmployee = new StaffManager(id, name, wage, dateOfEmployment, hasCar, hasOffice, department);
			isOk = true;
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
			PAUSE;
		}
		break;

	default:
		break;
		}
	} while (!isOk);
	return *newEmployee;
}

