#pragma once
#include "degree.h"
#include "student.h"

class Roster
{
	public:
		Roster();
		~Roster();
		// Sets the instance variables from part D1 and updates the roster.
		void add(string studentID, string firstName, string lastName,
			string emailAddress, int age, int daysInCourse1, int daysInCourse2,
			int daysInCourse3, DegreeProgram degreeprogram);
		// Removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
		void remove(string studentID);
		// Prints a complete tab-separated list of student data in the provided format.
		void printAll();
		// Correctly prints a student’s average number of days in the three courses.
		void printAverageDaysInCourse(string studentID);
		// Verifies student email addresses and displays all invalid email addresses to the user.
		void printInvalidEmails();
		//  Prints out student information for a degree program specified by an enumerated type.
		void printByDegreeProgram(DegreeProgram degreeSearched);
		// Return student ID from classRosterArray as a string
		string studentIDfromRoster(int index);
	private:
		void setRosterToNullptr();
		Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

};