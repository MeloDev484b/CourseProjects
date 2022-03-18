#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

const int DATA_SIZE = 5;
const int TEMP_DATA_ARRAY_SIZE = 9;
const std::string COURSE_INFO = "Course title: Scripting and Programming Applications: C867\nProgramming language used: C++\nStudent ID: #999999999\nStudent name: Lorem Ipsum\n";
const std::string studentData[DATA_SIZE] =
{ 
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Lorem,Ipsum,lipsum@wgu.edu,28,7, 7, 7,SOFTWARE" 
};

std::string tempDataArray[TEMP_DATA_ARRAY_SIZE] = {};

// Returns an array of strings.
void parseData(std::string inString, int index);

int main()
{
	// Display class info.
	std::cout << COURSE_INFO << std::endl;

	// Create an instance of Roster called classRoster.
	Roster classRoster = Roster();

	parseData(studentData[0], 0);

	classRoster.add("A1", "Lorem", "Ipsum", "lipsum@gmail.com", 28, 4, 5, 6, SOFTWARE);
	classRoster.add("A2", "Dolar", "Sit   ", "hk@gm ail.com", 25, 7, 8, 9, NETWORK);
	classRoster.add("A3", "Amet", "Tellus", "tm@gmail.com", 25, 66, 7, 79, SOFTWARE);
	classRoster.add("A4", "Semper", "Vitae", "cmgmail.com", 22, 22, 15, 61, SECURITY);
	classRoster.add("A5", "Mango", "Bango", "mb@gmailcom", 2, 43, 54, 69, SOFTWARE);

	// Loop through Roster and print all Student data.
	classRoster.printAll();

	// Loop through Roster and print all invalid emails.
	classRoster.printInvalidEmails();

	// Loop through the Roster and print out each student's average days in their courses.
	for (int i = 0; i < DATA_SIZE; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.studentIDfromRoster(i));
	}

	// Print Students assigned with the SOFTWARE DegreeProgram enum.
	classRoster.printByDegreeProgram(SOFTWARE);

	// Remove Student assigned with "A3" as their studentID.
	classRoster.remove("A3");

	// Show the Student has been removed from the Roster.
	classRoster.printAll();

	// Show an error message when an attemp is made to remove a Student object that does not exist.
	classRoster.remove("A3");

	// Release dynamically allocated memory in Roster.
	classRoster.~Roster();

}

void parseData(std::string inString, int index)
{
	std::string container = inString;
	std::istringstream inSS(container);
	while (inSS >> tempDataArray[index])
	{
		inSS >> tempDataArray[index];
	}
	std::cout << tempDataArray[index] << std::endl;
}