/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
public:
	//default constructor
	Person();

	//overloaded constructir
	Person(const string& fName, const string& lName);

	//sets name member variables to the ones passed into the funciton
	void setName(const string &newFirstName, const string &newLastName);

	//retrieves last name
	string getLastName() const;

	//resets the parameters to the values stored in the member variables
	void getName(string &fName, string &lName) const;

	//prints name in Smith, Jane format
	void printName() const;

	~Person();


private:
	string firstName;
	string lastName;
};

#endif
