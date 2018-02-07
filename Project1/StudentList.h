/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StudentList
{
public:

	// default constructor
	StudentList();

	// addStudent
	void addStudent(const Student& newStudent) const;

	// getNoOfStudents
	int getNoOfStudents() const;

	// printStudentByID
	void printStudentByID(int id, double tuition) const;

	// printStudentsByCourse
	void printStudentsByCourse(const string& courseNo) const;

	// printStudentByName
	void printStudentByName(const string& lastName) const;

	// printStudentsOnHold
	void printStudentsOnHold(double tuition) const;

	// printAllStudents
	void printAllStudents(double tuition) const;

	//printStudentInfoToFile
	void printStudentsToFile(ofstream& out, double tuitionRate) const;
	
	// destroyStudentList
	void destroyStudentList();

	// destructor
	~StudentList();


protected:
	vector<Student>* studentList;
};

#endif

