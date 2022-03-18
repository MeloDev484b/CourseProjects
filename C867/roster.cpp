#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

Roster::Roster(){};
// Release memory used by Student ptrs
Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
};

void Roster::add(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeprogram)
{
	int daysInCourseArray[3] = {0, 0, 0};
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, &daysInCourseArray[3], degreeprogram);
			classRosterArray[i]->setDaysToComplete(daysInCourse1, daysInCourse2, daysInCourse3);
			break;
		}
	}
}
//Check if student exists, remove if student exists, else print error statement that student was not found.
void Roster::remove(string studentID)
{
	bool exists = false;
	int index = 0;
	cout << "Removing " << studentID << ". . ." << endl;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
		}
		else if (classRosterArray[i]->getStudentID() == studentID)
		{
			index = i;
			exists = true;
		}
	}
	if (exists)
	{
		delete classRosterArray[index];
		classRosterArray[index] = nullptr;
		cout << studentID << " removed." << endl;
	}
	else
	{
		cout << studentID << " is not found." << endl;
	}
}

//Loop through rosterArray and print each student's info.
void Roster::printAll()
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i]->print();
		}
	}
}
//Print out the average days student was in courses.
void Roster::printAverageDaysInCourse(string studentID)
{
	int index = 0;
	float average = 0.0;
	int tempArray[3] = {};
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			if (classRosterArray[i]->getStudentID() == studentID)
			{
				index = i;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		tempArray[i] = classRosterArray[index]->getDaysToComplete(i);
	}
	for (int i = 0; i < 3; i++)
	{
		average += static_cast<float>(tempArray[i]);
	}
	average /= 3;
	cout << studentID << " Average days in class: " << average << endl;
}

//Check if student emails are valid. If an email is invalid, display it to the user.
void Roster::printInvalidEmails()
{
	string email;
	char at = '@';
	char spc = ' ';
	char per = '.';
	//Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			email = classRosterArray[i]->getEmailAddress();
			if (email.find(spc) != string::npos)
			{
				cout << email << endl;
			}
			else if (email.find(at) == string::npos || email.find(per) == string::npos)
			{
				cout << email << endl;
			}
		}
	}
}
//Print out all students with the same degreeprogram enum.
void Roster::printByDegreeProgram(DegreeProgram degreeSearched)
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
		}
		else if (classRosterArray[i]->getDegreeProgram() == degreeSearched)
		{
			classRosterArray[i]->print();
		}
	}
}

void Roster::setRosterToNullptr()
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i] = nullptr;
		}
	}
}
string Roster::studentIDfromRoster(int index)
{
	if (classRosterArray[index] != nullptr)
	{
		return classRosterArray[index]->getStudentID();
	}
}