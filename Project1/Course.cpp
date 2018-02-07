/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#include "Course.h"

// default constructor
Course::Course() 
{
	courseCredits = 0;
	courseGrade = '*';
}

//Parameters (in this order): a course name, a course number, a grade,
//and the credits.
//Re-sets all member variables to the given values passed by the
//parameters
// setCourseInfo
void Course::setCourseInfo(const string &newCourseName, const string &newCourseNumber, char newGrade, int newCredits) 
{
	courseName = newCourseName;
	courseNo = newCourseNumber;
	courseGrade = newGrade;
	courseCredits = newCredits;
}


// printCourseInfo
void Course::printCourseInfo(bool tuitionPaid) const 
{
	cout <<  left << setw(11) << courseNo;
	cout << setw(17) << courseName;
	cout << setw(1) << courseCredits;
	cout << right << setw(7);
	if (tuitionPaid)
		cout  <<  courseGrade << endl;
	else
		cout << right << "***" << endl;
}


// getCourseCredits
int Course::getCourseCredits() const 
{
	return courseCredits;
}

// getCourseNumber
string Course::getCourseNumber() const 
{
	return courseNo;
}

// getCourseName
string Course::getCourseName() const 
{
	return courseName;
}

// getCourseGrade
char Course::getCourseGrade() const 
{
	return courseGrade;
}

// destructor
Course::~Course() 
{
}
