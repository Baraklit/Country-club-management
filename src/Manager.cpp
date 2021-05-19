#include "Manager.h"
/*Constructors*/
Manager::Manager() :Management(), Branch("Empty")
{
	setHasCar(true);
	setHasOffice(true);
}
Manager::Manager(long ID, string name, float salary, Date dateOfEmployment, string branch, bool car, bool office) :
	Management(ID, name, salary, dateOfEmployment, car, office)
{
	setBranch(branch);
}
/*Sets*/
void Manager::setBranch(string branch)
{
	if (!validateString(branch))
		this->Branch = branch;
	else
		throw exception("Error: Invalid String ");
}
/*Methods*/
ostream& Manager::generalEmployeeInfo(ostream& out) const
{
	out << "Manager of " << getBranch() << " Country Club" << endl << "He has a car and an office!" << endl;
	return out;
}
