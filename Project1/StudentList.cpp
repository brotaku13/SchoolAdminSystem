/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#include "StudentList.h"

// default constructor
StudentList::StudentList()
{
	studentList = new vector<Student>;
}


// addStudent
void StudentList::addStudent(const Student& newStudent) const
{
	studentList->push_back(newStudent);
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return static_cast<int>(studentList->size());
}


// printStudentByID
void StudentList::printStudentByID(int id, double tuition) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();
	bool found = false;

	while (iter != iterEnd && !found)
	{
		if (iter->getID() == id)
			found = true;
		else
			iter++;
	}

	if (found)
		iter->printStudentInfo(tuition);
	else
		cout << "No students with ID " << id << " found in the list." << endl;
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& courseNo) const
{

	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();
	bool courseFound = false;

	for (iter; iter != iterEnd; iter++)
	{
		if (iter->getNumberOfCourses() != 0 && iter->isEnrolledInCourse(courseNo))
		{
			iter->printStudentInfo();
			courseFound = true;
		}
	}

	if (!courseFound)
		cout << "No students enrolled in " << courseNo << "." << endl;
}


// printStudentByName
void StudentList::printStudentByName(const string& lastName) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();
	bool studentFound = false;

	for (iter; iter != iterEnd; iter++)
	{
		if (iter->getLastName() == lastName)
		{
			iter->printStudentInfo();
			studentFound = true;
		}
	}

	if (!studentFound)
		cout << "No students with last name " << lastName << " in the list." << endl;
}



// printStudentsOnHold
void StudentList::printStudentsOnHold(double tuition) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();
	bool studentFound = false;

	for (iter; iter != iterEnd; iter++)
	{
		if (!iter->isTuitionPaid())
		{
			studentFound = true;
			iter->printStudentInfo();
			cout << "    Amount Due: $" << iter->billingAmount(tuition) << endl;
		}
	}

	if (!studentFound)
		cout << "There are no students on hold." << endl;

}

// printAllStudents
void StudentList::printAllStudents(double tuition) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();

	for (iter; iter != iterEnd; iter++)
	{
		iter->printStudentInfo(tuition);
	}
}


// printStudentsToFile
void StudentList::printStudentsToFile(ofstream& out, double tuitionRate) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();

	for (iter; iter != iterEnd; iter++)
	{
		iter->printStudentInfoToFile(out, tuitionRate);
	}
}


// destroyStudentList
void StudentList::destroyStudentList()
{
	delete studentList;
}


// destructor
StudentList::~StudentList()
{
	destroyStudentList();
}
