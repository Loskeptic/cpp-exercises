/*
Nathan Melton
CISP II
Create object to represent employees
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int COL_WIDTH = 15;

// Employee class with function protoypes
class Employee
{
public:
	Employee(string name, int idNumber, string department, string position);
	Employee(string name, int idNumber);
	Employee();
	string getName();
	int getIdNumber();
	string getDepartment();
	string getPosition();
	void setName(string name);
	void setIdNumber(int idNumber);
	void setDepartment(string department);
	void setPosition(string position);
private:
	string name;
	int idNumber;
	string department;
	string position;
};

// Function prototypes without class
void printEmployee(Employee employee);

int main()
{
	// Create 3 employee objects and give them data
	Employee employee1 = Employee("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee employee2 = Employee("Mark Jones", 39119, "IT", "Programmer");
	Employee employee3 = Employee("Joy Rogers", 81774, "Manufacturing", "Engineer");

	// Print each employee
	printEmployee(employee1);
	printEmployee(employee2);
	printEmployee(employee3);

	system("pause");
    return 0;
}

// Prints all fields of employee argument
void printEmployee(Employee employee) {
	cout << left << setw(COL_WIDTH) << "Name" << ": " << employee.getName() << '\n';
	cout << setw(COL_WIDTH) << "ID Number" << ": " << employee.getIdNumber() << '\n';
	cout << setw(COL_WIDTH) << "Department" << ": " << employee.getDepartment() << '\n';
	cout << setw(COL_WIDTH) << "Position" << ": " << employee.getPosition() << "\n\n";
}

// Employee constructors
Employee::Employee(string name, int idNumber, string department, string position)
{
	Employee::name = name;
	Employee::idNumber = idNumber;
	Employee::department = department;
	Employee::position = position;
}

Employee::Employee(string name, int idNumber)
{
	Employee::name = name;
	Employee::idNumber = idNumber;
	department = "";
	position = "";
}

Employee::Employee() {
	name = "";
	idNumber = 0;
	department = "";
	position = "";
}

// Employee accessors
string Employee::getName() {
	return Employee::name;
}

int Employee::getIdNumber() {
	return Employee::idNumber;
}

string Employee::getDepartment() {
	return Employee::department;
}

string Employee::getPosition() {
	return Employee::position;
}

// Employee mutators
void Employee::setName(string name) {
	Employee::name = name;
}

void Employee::setIdNumber(int idNumber) {
	Employee::idNumber = idNumber;
}

void Employee::setDepartment(string department) {
	Employee::department = department;
}

void Employee::setPosition(string position) {
	Employee::position = position;
}
