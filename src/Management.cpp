#include "Management.h"
/*Constructors*/
Management::Management() :Employee(), hasCar(false), hasOffice(false) {}
Management::Management(long id, string name, float salary, Date dateOfEmployment, bool hasOffice, bool hasCar) :
	Employee(id, name, salary, dateOfEmployment), hasOffice(hasOffice), hasCar(hasCar) {}
Management::Management(long id, string name, float salary, Date dateOfEmployment) : Employee(id, name, salary, dateOfEmployment) 
{
	setHasOffice(true);
	setHasCar(true);
} 



