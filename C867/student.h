#pragma once
#include <array>
#include "degree.h"
#include <iostream>
#include <string>

using std::string;

class Student {
	public:
		Student(string studentID, string firstName, string lastName,
			string emailAddress, int age, int sDaysInCourse[3], DegreeProgram degreeprogram);
		~Student();
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int getDaysToComplete(int index);
		DegreeProgram getDegreeProgram();
		void print();
		string stringifyEnum(DegreeProgram degree);

		void setStudentID(string newID);
		void setFirstName(string fName);
		void setLastName(string lName);
		void setEmailAddress(string email);
		void setAge(int newAge);
		void setDaysToComplete(int days1, int days2, int days3);
		void setDegreeProgram(DegreeProgram degree);
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int sDaysInCourse[3] = {};
		DegreeProgram degreeProgram;
};