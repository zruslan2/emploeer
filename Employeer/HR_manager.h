#pragma once
#include "Employee.h"
class HR_manager :
	public Employee
{
	bool education;
public:
	HR_manager(bool education, string name, int age, string sex, int workYears);

	void setEducation(bool education);
	bool getEducation()const { return this->education; }

	void info()const override;
	double getSalary()const override;
	
};

