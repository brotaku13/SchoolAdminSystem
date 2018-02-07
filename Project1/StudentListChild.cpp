/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#include "StudentListChild.h"

StudentListChild::StudentListChild()
{

}

void StudentListChild::printStudentInOrder() const
{
	map<string, int> studentMap;
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();

	string fName, lName;
	string fullName;

	for (iter; iter != iterEnd; iter++)
	{
		iter->getName(fName, lName);
		fullName = lName + ", " + fName;

		studentMap.insert(make_pair(fullName, iter->getID()));
	}

	auto iterMap = studentMap.cbegin();
	auto iterMapEnd = studentMap.cend();

	for (iterMap; iterMap != iterMapEnd; iterMap++)
	{
		cout << iterMap->second << " - " << iterMap->first << endl;
	}

}

StudentListChild::~StudentListChild()
{

}