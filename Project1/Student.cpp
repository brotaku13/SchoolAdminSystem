/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#include "Student.h"

// default constructor
Student::Student()
{
	studentID = 0;
	numberOfCourses = 0;
	tuitionWasPaid = false;
}

// setStudentInfo
void Student::setStudentInfo(const string &fName, const string &lName, int newID, bool tuitionPaid, const vector<Course> &courseVector)
{
	setName(fName, lName);
	studentID = newID;
	tuitionWasPaid = tuitionPaid;
	coursesEnrolled = courseVector;
	numberOfCourses = static_cast<int>(courseVector.size());
}

// getID
int Student::getID() const
{
	return studentID;
}


// getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}

// getCreditsEnrolled
int Student::getCreditsEnrolled() const
{
	int credits = 0;
	for (Course course : coursesEnrolled)
	{
		credits += course.getCourseCredits();
	}

	return credits;
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

// isEnrolledInCourse
bool Student::isEnrolledInCourse(const string &courseNumber) const
{
	if (numberOfCourses == 0)
	{
		return false;
	}
	else
	{
		for (Course course : coursesEnrolled)
		{
			if (course.getCourseNumber() == courseNumber)
			{
				return true;
			}
		}
		return false;
	}
}

// getGpa
double Student::getGpa() const
{
	double totalUnitScore = 0.0;
	for (Course course : coursesEnrolled)
	{
		switch(course.getCourseGrade())
		{
			case 'A': 
				totalUnitScore += 4.0 * course.getCourseCredits();
				break;
			case 'B': 
				totalUnitScore += 3.0 * course.getCourseCredits();
				break;
			case 'C': 
				totalUnitScore += 2.0 * course.getCourseCredits();
				break;
			case 'D': 
				totalUnitScore += course.getCourseCredits();
				break;
			default:
				break;
		}
	} 
	return (totalUnitScore / getCreditsEnrolled());
}

// billingAmount
double Student::billingAmount(double tuition) const
{
	return getCreditsEnrolled() * tuition;
}

// printStudentInfo
void Student::printStudentInfo() const
{
	cout << studentID << " - ";
	Person::printName();
	
}

// printStudentInfo (overloaded)
void Student::printStudentInfo(double tuition) const
{
	cout << "Student Name: ";
	Person::printName();
	cout << endl;

	
	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses enrolled: " << numberOfCourses << endl << endl;
	
	
	cout<< left << setw(11) << "Course No" << setw(13) << "Course Name"  << setw(8) << "Credits" << "Grade" << endl;
	for (Course course : coursesEnrolled)
	{
		course.printCourseInfo(tuitionWasPaid);
	}
	
	cout << endl << "Total numbr of credit hours: " << getCreditsEnrolled() << endl;
	if (tuitionWasPaid)
	{
		cout << "Current term GPA: " << getGpa() << endl;
	}
	else
	{
		cout << "*** Grades are being held for not paying the tuition. ***" << endl;
		cout << "Amount due: $" << billingAmount(tuition) << endl;
	}
	cout << endl;
	for (int i = 0; i < 25; i++)
	{
		cout << "-*";
	}
	cout << endl << endl;
}

// getCoursesEnrolled
vector<Course> Student::getCoursesEnrolled() const
{
	return coursesEnrolled;
}

void Student::printStudentInfoToFile(ofstream& out, double tuitionRate) const
{
	string fName;
	string lName;

	getName(fName, lName);
	out << "Student Name: ";
	out << lName << ", " << fName << endl;
	out << endl;

	out << "Student ID: " << studentID << endl;
	out << "Number of courses enrolled: " << numberOfCourses << endl << endl;

	
	out << left << setw(11) << "Course No" << setw(13) << "Course Name" << setw(8) << "Credits" << "Grade" << endl;

	for (Course course : coursesEnrolled)
	{
		out << left << setw(12) << course.getCourseNumber();
		out << setw(16) << course.getCourseName();
		out << setw(3) << course.getCourseCredits();
		if (tuitionWasPaid)
			out << right << setw(5) << course.getCourseGrade() << endl;
		else
			out << right << setw(5) << "***" << endl;
	}

	out << endl << "Total numbr of credit hours: " << getCreditsEnrolled() << endl;

	out << setprecision(3) << showpoint;

	if (tuitionWasPaid)
	{
		out << "Current term GPA: " << getGpa() << endl;
	}
	else
	{
		out << "*** Grades are being held for not paying the tuition. ***" << endl;
		out << "Amount due: $" << billingAmount(tuitionRate) << endl;
	}

	out << endl;

	for (int i = 0; i < 25; i++)
	{
		out << "-*";
	}

	out << endl << endl;
}

// destructor
Student::~Student()
{

}