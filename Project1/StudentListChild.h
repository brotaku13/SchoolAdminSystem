/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#ifndef STUDENTLISTCHILD_H
#define STUDENTLISTCHILD_H

#include "StudentList.h"

#include <map>

class StudentListChild : public StudentList
{
public:
	//default constructor
	StudentListChild();

	void printStudentInOrder() const;

	//destructor
	~StudentListChild();
private:

};

#endif
