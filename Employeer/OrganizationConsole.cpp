#include "OrganizationConsole.h"
#include<iomanip>


OrganizationConsole::OrganizationConsole()
	:org("", 0) {
	//startMenu();
	//mainMenu();
}

void OrganizationConsole::start()
{
	mainMenu();
}

void OrganizationConsole::startMenu()
{
	system("cls");
	cout << "Welcome!";
	Sleep(2000);
	this->setOrgNameMenu();
	this->setSalaryMenu();
}

void OrganizationConsole::mainMenu()
{
	int choise = 0;
	while (choise != 5) {
		system("cls");
		cout << "Organization name: " << org.getName();
		cout << "\nSalary: " << org.getBaseSalary();
		cout << "\nCount of employee: " << org.getCountOfEmployee();
		cout << "\n\n----------------------------\n\n";
		cout << "\n\t1. Add new employee\n\t2. Dismiss employee\n\t3. Show organization info\n\t4. Show employee info\n\t5. Exit\n";
		cin >> choise;
		switch (choise)
		{

		case 1:
			addEmpMenu();
			break;
		case 2:
			removeEmpMenu();
			break;
		case 3:
			showInfo();
			system("pause");
			break;
		case 4:
			setEmpInfoMenu();
			pause();
			break;
		case 5:
			break;
		default:
			cout << "Unknown command\npress any key to continue\n";
			system("pause");
			system("cls");
			break;
		}
	}
	cout << "Bye bye\n";
}

void OrganizationConsole::addEmpMenu()
{
	size_t ch;

	while (1) {
		system("cls");
		cout << "choose position\n";
		cout << "1. Accounter\n2. Proger\n3. Director\n4. HR-Manager\n5. Main menu\n";
		cin >> ch;
		if (ch > 4) {
			cout << "uknown position\n";
			system("pause");
		}
		else
			break;

	}
	if (ch == 5)
		return;
	string name;
	int age;
	string sex;
	int exp;
	system("cls");
	cout << "Set employee name\n";
	cin >> name;
	cout << "set employee age\n";
	cin >> age;
	cout << "set employee sex\n";
	cin >> sex;
	cout << "set employee experience\n";
	cin >> exp;
	Employee*emp = nullptr;
	switch (ch)
	{
	case 1:
		bool k1c;
		cout << "1c experience? 1 or 0\n";
		cin >> k1c;
		emp = new Acounter(name, age, sex, exp, k1c);
		break;
	case 2:
		int cntLang;
		bool edu;
		cout << "Set count of known languages\n";
		cin >> cntLang;
		cout << "High education? 1 or 0\n";
		cin >> edu;
		emp = new Proger(name, age, sex, exp, cntLang, edu);
		break;
	case 3:
		emp = new Director(name, age, sex, exp);
		break;
	case 4:
//		bool edu;
		cout << "Special ducation? 1 or 0\n";
		cin >> edu;
		emp = new HR_manager(edu,name, age, sex, exp);
		break;
	}
	system("cls");
	org.addEmployee(emp);
	cout << "Employee added!\n";
	system("pause");
}

void OrganizationConsole::removeEmpMenu()
{

	while (1) {
		system("cls");
		cout << "Choose Id of employee to remove" << endl;
		for (int i = 0; i < org.getCountOfEmployee(); i++)
		{
			cout << setw(3) << left << org[i].getId()
				<< setw(12) << left << string(typeid(org[i]).name()).substr(6)
				<< setw(12) << left << org[i].getName() << endl;

		}
		int ch;
		cin >> ch;
		if (!org.removeEmployeeById(ch)) {
			cout << "incorrect id!\n";
			system("pause");
			continue;
		}
		cout << "Employee dismissed!\n";
		system("pause");
		return;
	}

}

void OrganizationConsole::showInfo() const
{
	system("cls");
	org.getInfo();
}

void OrganizationConsole::setOrgNameMenu()
{
	system("cls");
	cout << "Set organization name\n";
	string name;
	cin >> name;
	org.setName(name);
}

void OrganizationConsole::setSalaryMenu()
{
	system("cls");
	cout << "Set salary\n";
	int sal;
	cin >> sal;
	org.setBaseSalary(sal);
}

void OrganizationConsole::setEmpInfoMenu()
{
	while (1) {
		clearScreen();
		cout << "choose employee\'s id\n\n";
		showShortInfo();
		cout << "0 - go back\n";

		int ch;
		cin >> ch;
		if (ch == 0) break;
		Employee *e = org.getEmployeeById(ch);
		if (e == nullptr) {
			cout << "incorrect id!\n";
			pause();
			continue;
		}

		editEmployeeMenu(e);
		//break;
	}

}

void OrganizationConsole::showShortInfo() const
{
	for (int i = 0; i < org.getCountOfEmployee(); i++)
	{
		cout << setw(3) << left << org[i].getId()
			<< setw(12) << left << string(typeid(org[i]).name()).substr(6)
			<< setw(12) << left << org[i].getName() << endl;

	}
}

void OrganizationConsole::editEmployeeMenu(Employee * emp)
{
	while (1) {
		clearScreen();
		cout << string(typeid(*emp).name()).substr(6) << endl;
		emp->info();
		cout << "\n1. change employee info";
		cout << "\n2. dismiss employee";
		cout << "\n3. change position";
		cout << "\n0. back\n";
		int ch;
		cin >> ch;

		switch (ch)
		{
		case 0:
			return;
		case 1:
			editEmployeeInfo(emp);
			break;
		case 2:
			org.removeEmployeeById(emp->getId());
			cout << "\nEmployee dismissed!\n";
			pause();
			return;
			break;
		case 3:
			changePosition(emp);
			return;
			break;
		default:
			cout << "Unknown command";
			break;
		}
	}

}

void OrganizationConsole::editEmployeeInfo(Employee * emp)
{
	//((Proger*)emp)->getCntLang();
	while (1) {
		clearScreen();
		emp->info();
		int index = 0;
		cout << "\nchoose information to change\n";
		cout << ++index << ". name\n";
		cout << ++index << ". age\n";
		cout << ++index << ". sex\n";
		cout << ++index << ". experience in years\n";
		int pos;
		if (typeid(*emp) == typeid(Proger)) {
			pos = 1;
			cout << ++index << ". count of known languages\n";
			cout << ++index << ". education\n";
		}
		if (typeid(*emp) == typeid(Acounter)) {
			pos = 2;
			cout << ++index << ". 1c experience\n";
		}
		if (typeid(*emp) == typeid(HR_manager)) {
			pos = 3;
			cout << ++index << ". education\n";
		}		
		cout << "0. go back";

		int ch;
		cin >> ch;
		if (ch < 0 || ch > index) {
			cout << "unknown command\n";
			pause();
			continue;
		}
		switch (ch)
		{
		case 0:
			return;
		case 1:
		{
			cout << "\nEnter new name\n";
			string name;
			cin >> name;
			emp->setName(name);
			break;
		}
		case 2:
		{
			cout << "\nEnter new age\n";
			int age;
			cin >> age;
			emp->setAge(age);
			break;
		}
		case 3:
		{
			cout << "\nEnter new sex\n";
			string sex;
			cin >> sex;
			emp->setSex(sex);
			break;
		}
		case 4:
		{
			cout << "\nEnter new experience in years\n";
			int exp;
			cin >> exp;
			emp->setWorkYears(exp);
			break;
		}
		default:
		{
			switch (pos)
			{
			case 1:
				if (ch == 5) {
					cout << "enter new count of known languages\n";
					int cnt;
					cin >> cnt;
					((Proger*)emp)->setCntLang(cnt);
				}
				else {
					cout << "Education? 0 or 1\n";
					bool ed;
					cin >> ed;
					((Proger*)emp)->setHasEdu(ed);
				}
				break;
			case 2:
				if (ch == 5)
				{
					cout << "Know 1C?  0 or 1\n";
					bool know1C;
					cin >> know1C;
					((Acounter*)emp)->setKnow1C(know1C);
				}
				break;				
			case 3:
				if (ch == 5)
				{
					cout << "Education (1-yes, 0-no)";
					bool edu;
					cin >> edu;
					((HR_manager*)emp)->setEducation(edu);
				}
				break;
			}
		}
		break;
		}

	}
	pause();
}

void OrganizationConsole::changePosition(Employee* emp)
{
	while (1) {
		clearScreen();
		cout << "Choose new position of "
			<< emp->getPosition() << " " << emp->getName();
		cout << "\n1. Proger\n";
		cout << "2. Accounter\n";
		cout << "3. Director\n";
		cout << "4. HR manager\n";
		cout << "0. go back\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch>5) {
			cout << "unknown command\n";
			pause();
			continue;
		}
		Employee *e = nullptr;
		switch (ch)
		{
		case 1:
			e = new Proger(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0);
			break;
		case 2:
			e = new Acounter(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			break;
		case 3:
			e = new Director(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears());
			break;
		case 4:
			e = new HR_manager(0, emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears());
			break;		
		}
		org.addEmployee(e);
		org.removeEmployeeById(emp->getId());
		return;
	}
}
