#include "HR_manager.h"

HR_manager::HR_manager(bool education, string name, int age, string sex, int workYears) 
	:Employee(name, age, sex, workYears)
{
	this->education = education;
}

void HR_manager::setEducation(bool education)
{
	this->education = education;
}

void HR_manager::info() const
{
	Employee::info();
	cout << "Special education: " << boolalpha << education << endl;
}

double HR_manager::getSalary() const
{
	double coef = getWorkYears()*0.15;
	coef += education * 0.05;
	return coef;
}
