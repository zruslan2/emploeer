#include "Organization.h"

Organization::Organization(string name, int baseSalary)
{
	this->name = name;
	this->baseSalary = baseSalary;
}

void Organization::addEmployee(Employee * employee)
{
	employees.push_back(unique_ptr<Employee>(employee));
}

void Organization::delEmployee(Employee * employee)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i].get() == employee) {
			employees.erase(begin(employees) + i);
			return;
		}
	}
}

void Organization::setName(string name)
{
	this->name = name;
}

void Organization::setBaseSalary(int baseSalary)
{
	this->baseSalary = baseSalary;
}

void Organization::getInfo() const
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		employees[i]->info();
		cout << "salary: " << employees[i]->getSalary()*baseSalary << endl;
	}
}

double Organization::getSalaryFund() const
{
	double res = 0;
	for (size_t i = 0; i < employees.size(); i++)
	{
		res += employees[i]->getSalary()*baseSalary;
	}
	return res;
}

bool Organization::removeEmployeeById(int id)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getId() == id) {
			employees.erase(begin(employees) + i);
			return true;
		}
	}
	return false;
}
void Organization::showEmpInfo(int index) const
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getId() == index)
		{

			employees[i]->info();
			cout << "salary: " << employees[i]->getSalary()*baseSalary << endl;

		}
	}
}
void Organization::changeEmpInfo(int index)
{
	system("cls");
	string newName;
	int newAge;
	string newSex;
	int newWorkYear;
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getId() == index)
		{
			cout << "Set new Name: ";
			cin >> newName;
			employees[i]->setName(newName);
			cout << "Set new age: ";
			cin >> newAge;
			employees[i]->setAge(newAge);
			cout << "Set new sex: ";
			cin >> newSex;
			employees[i]->setSex(newSex);
			cout << "Set new work year: ";
			cin >> newWorkYear;
			employees[i]->setWorkYears(newWorkYear);
		}
	}
}

Employee * Organization::getEmployeeById(int id)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getId() == id) {
			return employees[i].get();
		}
	}
	return nullptr;
}

const Employee * Organization::getEmployeeById(int id) const
{
	return nullptr;
}