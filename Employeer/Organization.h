#pragma once
#include "Employee.h"
#include <vector>
#include <memory>

using namespace std;
class Organization
{
	string name;
	vector<unique_ptr<Employee>>employees;
	int baseSalary;
public:

	Organization(string name, int baseSalary);
	void addEmployee(Employee* employee);
	void delEmployee(Employee* employee);

	void setName(string name);
	void setBaseSalary(int baseSalary);
	int getBaseSalary()const { return this->baseSalary; }
	string getName()const { return this->name; }

	void getInfo()const;
	double getSalaryFund()const;

	bool removeEmployeeById(int id);
	int getCountOfEmployee()const { return employees.size(); }
	Employee& operator [](int index) {
		return *employees[index];
	}
	const Employee& operator [](int index) const {
		return *employees[index];
	}
	void showEmpInfo(int index)const;
	void changeEmpInfo(int index);
	Employee* getEmployeeById(int id);
	const Employee* getEmployeeById(int id)const;
};

