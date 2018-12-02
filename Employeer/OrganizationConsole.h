#pragma once
#include "Organization.h"
#include "Acounter.h"
#include "Director.h"
#include "Proger.h"
#include "HR_manager.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

class OrganizationConsole
{

public:
	Organization org;
	OrganizationConsole();
	void start();
private:
	void startMenu();
	void mainMenu();
	void addEmpMenu();
	void removeEmpMenu();
	void showInfo()const;

	void setOrgNameMenu();
	void setSalaryMenu();

	void setEmpInfoMenu();
	void showShortInfo()const;
	void clearScreen()const { system("cls"); }
	void pause()const { system("pause"); }
	void editEmployeeMenu(Employee* emp);
	void editEmployeeInfo(Employee* emp);
	void changePosition(Employee* emp);
};

