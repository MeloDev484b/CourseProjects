#pragma once
#include <iostream>
#include "degree.h"
#include <string>

const int DAYS_ARRAY_SIZE = 3;

class Student {
	public:
		Student(std::string studentID, std::string firstName, std::string lastName,
			std::string emailAddress, int age, int sDaysInCourse[DAYS_ARRAY_SIZE], DegreeProgram degreeprogram);
		~Student();
		std::string getStudentID();
		std::string getFirstName();
		std::string getLastName();
		std::string getEmailAddress();
		int getAge();
		int getDaysToComplete(int index);
		DegreeProgram getDegreeProgram();
		void print();
		std::string stringifyEnum(DegreeProgram degree);
		void setStudentID(std::string newID);
		void setFirstName(std::string fName);
		void setLastName(std::string lName);
		void setEmailAddress(std::string email);
		void setAge(int newAge);
		void setDaysToComplete(int days1, int days2, int days3);
		void setDegreeProgram(DegreeProgram degree);
	private:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		int age;
		int sDaysInCourse[DAYS_ARRAY_SIZE] = {};
		DegreeProgram degreeProgram;
};