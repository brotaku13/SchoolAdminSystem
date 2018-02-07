/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#include "Person.h"

Person::Person() 
{
	firstName = "N/A";
	lastName = "N/A";
}


Person::Person(const string& fName, const string& lName)
{
	firstName = fName;
	lastName = lName;
}

void Person::setName(const string &newFirstName, const string &newLastName) 
{
	firstName = newFirstName;
	lastName = newLastName;
}

string Person::getLastName() const 
{
	return lastName;
}

void Person::getName(string &fName, string &lName) const 
{
	fName = firstName;
	lName = lastName;
}

void Person::printName() const 
{
	cout << lastName << ", " << firstName << endl;
}

Person::~Person() 
{
}
