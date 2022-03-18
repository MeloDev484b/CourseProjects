#include <iostream>
#include <string>
#include "roster.h"

Roster::Roster(){};

Roster::~Roster()
{
	for (int i = 0; i < ROSTER_SIZE; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
};

// Checks for a nullptr in the classRosterArray, then creates a student object and adds it to the classRosterArray[], if there is space.
void Roster::add(std::string studentID, std::string firstName, std::string lastName,
	std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeprogram)
{
	int daysInCourseArray[DAYS_ARRAY_SIZE] = {0, 0, 0};
	for (int i = 0; i < ROSTER_SIZE; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, &daysInCourseArray[DAYS_ARRAY_SIZE], degreeprogram);
			classRosterArray[i]->setDaysToComplete(daysInCourse1, daysInCourse2, daysInCourse3);
			break;
		}
	}
}

// Check if Student object exists by studentID, remove if student exists, else print error statement that Student was not found.
void Roster::remove(std::string studentID)
{
	bool exists = false;
	int index = 0;
	std::cout << "Removing " << studentID << ". . ." << std::endl;
	for (int i = 0; i < ROSTER_SIZE; i++)
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
		std::cout << "Student with ID " << studentID << " has been removed." << std::endl;
	}
	else
	{
		std::cout << "Student with ID " << studentID << " is not found." << std::endl;
	}
}

// Loop through classRosterArray[] and print each student's info.
void Roster::printAll()
{
	for (int i = 0; i < ROSTER_SIZE; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i]->print();
		}
	}
}

// Uses studentIDfromRoster() to access studentID and prints out the average days a Student object was in their courses.
void Roster::printAverageDaysInCourse(std::string studentID)
{
	int index = 0;
	float average = 0.0;
	int tempArray[DAYS_ARRAY_SIZE] = {};
	for (int i = 0; i < ROSTER_SIZE; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			if (classRosterArray[i]->getStudentID() == studentID)
			{
				index = i;
			}
		}
	}
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++)
	{
		tempArray[i] = classRosterArray[index]->getDaysToComplete(i);
	}
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++)
	{
		average += static_cast<float>(tempArray[i]);
	}
	average /= DAYS_ARRAY_SIZE;
	std::cout << studentID << " Average days in class: " << average << std::endl;
}

// Check if student emails are valid. If an email is invalid, display it to the user. 
// Valid emails are defined as including both a @ and a . char, but not a ' ' char.
void Roster::printInvalidEmails()
{
	std::string email;
	char at = '@';
	char spc = ' ';
	char per = '.';
	for (int i = 0; i < ROSTER_SIZE; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			email = classRosterArray[i]->getEmailAddress();
			if (email.find(spc) != std::string::npos)
			{
				std::cout << email << std::endl;
			}
			else if (email.find(at) == std::string::npos || email.find(per) == std::string::npos)
			{
				std::cout << email << std::endl;
			}
		}
	}
}

// Prints out all students with the same DegreeProgram enum.
void Roster::printByDegreeProgram(DegreeProgram degreeSearched)
{
	for (int i = 0; i < ROSTER_SIZE; i++)
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

// Set all indices in the classRosterArray[] to nullptr.
void Roster::setRosterToNullptr()
{
	for (int i = 0; i < ROSTER_SIZE; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i] = nullptr;
		}
	}
}

// Access studentID through the Roster object.
std::string Roster::studentIDfromRoster(int index)
{
	if (classRosterArray[index] != nullptr)
	{
		return classRosterArray[index]->getStudentID();
	}
}
