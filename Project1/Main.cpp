/*************************
	PierceTheHeavens

	Caulfield, Brian
	Cao, Paul
	Ali, Ahmed
	Huynh, Ryan

	CS A250 - Fall 2017

	Project 2
*************************/

#include "InputHandler.h"
#include "OutputHandler.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void displayMenu();

void processChoice(const StudentListChild& studentList, double tuitionRate);

int main()
{
	StudentListChild studentList;
	double tuitionRate = 0.0;

	readStudentData(studentList, tuitionRate);
	displayMenu();
	processChoice(studentList, tuitionRate);

	cout << endl;
	system("Pause");
	return 0;

}

void displayMenu()
{
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nSelect one of the following:\n\n";
	cout << "    1: Print all students" << endl;
	cout << "    2: Print student information" << endl;
	cout << "    3: Search student by last name" << endl;
	cout << "    4: Print students by course" << endl;
	cout << "    5: Print students on hold" << endl;
	cout << "    6: Print students to file" << endl;
	cout << "    7: Print roster" << endl;
	cout << "    8: To exit" << endl;

}

void processChoice(const StudentListChild& studentList, double tuitionRate)
{
	int choice = 0, id = 0;
	string courseNumber, lastName;

	

	cout << fixed << showpoint << setprecision(2);

	do
	{
		cout << "\nEnter your choice: ";
		cin >> choice;
		cout << endl;

		string fName, lName;
		int ssn = 0;
		double donation = 0.0;

		if (choice != 8)
		{
			switch (choice)
			{

				// Print all students
			case 1:
				if (studentList.getNoOfStudents() != 0)
				{
					studentList.printAllStudents(tuitionRate);
				}
				else
				{
					cerr << "There are no students in the list." << endl;
				}
				break;

				// Print student information
			case 2:
				if (studentList.getNoOfStudents() != 0)
				{
					cout << "Please enter student's ID: ";
					cin >> id;
					cout << endl;

					studentList.printStudentByID(id, tuitionRate);
					cout << endl;

				}
				else
				{
					cerr << "There are no students in the list." << endl;
				}
				break;

				// Search student by last name
			case 3:
				if (studentList.getNoOfStudents() != 0)
				{
					cout << "Please enter the student's last name: ";
					cin >> lastName;
					cout << endl;

					studentList.printStudentByName(lastName);
					cout << endl;

				}
				else
				{
					cerr << "There are no students in the list." << endl;
				}
				break;

				// Print students by course 
			case 4:
				if (studentList.getNoOfStudents() != 0)
				{
					cout << "Please enter the course number: ";
					cin >> courseNumber;
					cout << endl;

					studentList.printStudentsByCourse(courseNumber);
					cout << endl;

				}
				else
				{
					cerr << "There are no students in the list." << endl;
				}
				break;

				// Print students on hold
			case 5:
				if (studentList.getNoOfStudents() != 0)
				{
					studentList.printStudentsOnHold(tuitionRate);
					cout << endl;
				}
				else
				{
					cerr << "There are no students in the list." << endl;
				}
				break;

				//print students to file
			case 6:
				if (studentList.getNoOfStudents() != 0)
				{
					printAllStudentsToFile(studentList, tuitionRate);
					cout << endl;
				}
				else
				{
					cerr << "There are no students in the list." << endl;
				}
				break;

			case 7:
				if (studentList.getNoOfStudents() != 0)
				{
					studentList.printStudentInOrder();
					cout << endl;
				}
				else
				{
					cerr << "There are no students in the list." << endl;
				}
				break;

				// Incorrect selection
			default:

				cout << "Sorry. That is not a selection." << endl << endl;
				break;
			}

			system("Pause");
			displayMenu();

		}
		else
		{
			cout << "Thank you for using the OCC Gradebook. Good-bye!" << endl;
		}

	} while (choice != 8);

}
