
#include "OrganizationConsole.h"

void main()
{

	OrganizationConsole e;
	e.org.addEmployee(new Acounter("Petya", 30, "male", 15, 1));
	e.org.addEmployee(new Proger("Masha", 40, "female", 20, 6, 1));
	e.org.addEmployee(new Director("Dinara", 35, "female", 15));
	e.org.addEmployee(new HR_manager(1,"Tanya", 45, "female", 15));
	
	e.start();

	system("pause");
	/*Employee *a = new Proger("",1,"",1,2,0);

	Proger p("", 1, "", 1, 2, 0);
	Employee &pp = p;
	pp.setName("asdasd");
	p.setCntLang(5);
	((Proger&)pp).setCntLang(7);


	Organization org("XXX", 100000);
	org.addEmployee(new Acounter("Petya", 30, "male", 15, 1));
	org.addEmployee(new Proger("Masha", 40, "female", 20, 6, 1));
	org.addEmployee(new Director("Dinara", 35, "female", 15));
	org.getInfo();*/
	
}