#include "student.h"

Student::Student(std::string studentID, std::string firstName, std::string lastName,
	std::string emailAddress, int age, int daysInCourse[DAYS_ARRAY_SIZE], DegreeProgram degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	// Copy data from array argument to this Student's sDaysInCourse[].
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) 
	{
		this->sDaysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeprogram;
}

Student::~Student() {};

std::string Student::getStudentID()
{
	return studentID;
}

std::string Student::getFirstName()
{
	return firstName;
}

std::string Student::getLastName()
{
	return lastName;
}

std::string Student::getEmailAddress()
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

// Prints formatted Student object data: firstName, lastName, age, sDaysInCourse[] contents contained in curly brackets, and degreeProgram.
void Student::print()
{
	std::cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << age << "\tDays in course: " << "{"<< sDaysInCourse[0] << ", " << sDaysInCourse[1] << ", " << sDaysInCourse[2] << "} " << "Degree Program: " << stringifyEnum(getDegreeProgram()) << std::endl;
}

void Student::setStudentID(std::string newID)
{
	studentID = newID;
}

void Student::setFirstName(std::string newFname)
{
	firstName = newFname;
}

void Student::setLastName(std::string newLname)
{
	lastName = newLname;
}

void Student::setEmailAddress(std::string newEmail)
{
	emailAddress = newEmail;
}

void Student::setAge(int newAge)
{
	age = newAge;
}

// Assigns days1, days2, and days3 to the appropriate index in sDaysInCourse[].
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
// Returns string version of a DegreeProgram enum.
std::string Student::stringifyEnum(DegreeProgram degree)
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