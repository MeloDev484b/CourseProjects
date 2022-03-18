#pragma once
#include "degree.h"
#include "student.h"

const int ROSTER_SIZE = 5;

class Roster
{
	public:
		Roster();
		~Roster();
		void add(std::string studentID, std::string firstName, std::string lastName,
			std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
			int daysInCourse3, DegreeProgram degreeprogram);
		void remove(std::string studentID);
		void printAll();
		void printAverageDaysInCourse(std::string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeSearched);
		std::string studentIDfromRoster(int index);
	private:
		void setRosterToNullptr();
		Student* classRosterArray[ROSTER_SIZE] = {nullptr, nullptr, nullptr, nullptr, nullptr};

};