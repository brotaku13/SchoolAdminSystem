/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Course
{
public:

	// default constructor
	Course();

	//Parameters (in this order): a course name, a course number, a grade,
	//and the credits.
	//Re-sets all member variables to the given values passed by the
	//parameters
	// setCourseInfo
	void setCourseInfo(const string &courseName, const string &courseNumber, char grade, int credits);


	// printCourseInfo
	void printCourseInfo(bool tuitionPaid) const;


	// getCourseCredits
	int getCourseCredits() const;


	// getCourseNumber
	string getCourseNumber() const;

	// getCourseName
	string getCourseName() const;

	// getCourseGrade
	char getCourseGrade() const;

	// destructor
	~Course();

private:
    string courseName; 	
    string courseNo; 	
    char courseGrade;	
    int courseCredits;	
};

#endif
