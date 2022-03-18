#include "student.h"

Student::Student(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++) 
	{
		this->sDaysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeprogram;
}

Student::~Student() {};

string Student::getStudentID()
{
	return studentID;
}
string Student::getFirstName()
{
	return firstName;
}
string Student::getLastName()
{
	return lastName;
}
string Student::getEmailAddress()
{
	return emailAddress;
}
int Student::getAge()
{
	return age;
}
int Student::getDaysToComplete(int index)
{
	return sDaysInCourse[index];
}
DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}
void Student::print()
{
	std::cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << age << "\tDays in course: " << "{"<< sDaysInCourse[0] << ", " << sDaysInCourse[1] << ", " << sDaysInCourse[2] << "} " << "Degree Program: " << stringifyEnum(getDegreeProgram()) << std::endl;
}

void Student::setStudentID(string newID)
{
	studentID = newID;
}
void Student::setFirstName(string newFname)
{
	firstName = newFname;
}
void Student::setLastName(string newLname)
{
	lastName = newLname;
}
void Student::setEmailAddress(string newEmail)
{
	emailAddress = newEmail;
}
void Student::setAge(int newAge)
{
	age = newAge;
}
void Student::setDaysToComplete(int days1, int days2, int days3)
{
	sDaysInCourse[0] = days1;
	sDaysInCourse[1] = days2;
	sDaysInCourse[2] = days3;
	
}
void Student::setDegreeProgram(DegreeProgram degree)
{
	degreeProgram = degree;
}

string Student::stringifyEnum(DegreeProgram degree)
{
	switch (degree)
	{
	case SECURITY:
		return "Security";
	case NETWORK:
		return "Network";
	case SOFTWARE:
		return "Software";
	}
}