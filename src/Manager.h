#ifndef MANAGER_H
#define MANAGER_H
#include "Management.h"
class Manager :public Management
{
private:
	/*Variables*/
	string Branch;

public:
	/*Constructors*/
	Manager();
	Manager(long ID, string name, float salary, Date dateOfEmployment, string branch, bool car = true, bool office = true);
	/*Destructor*/
	~Manager(){}

	/*Methods*/
	virtual ostream& generalEmployeeInfo(ostream& out) const;

	/*Sets*/
	void setBranch(string branch);
	/*Gets*/
	string getBranch() const { return this->Branch; }

	/*Operator*/
};
#endif  

