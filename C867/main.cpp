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
	"A5,Lorem,Ipsum,lipsum@wgu.edu,28,3, 20, 2,SOFTWARE" 
};

std::string tempDataArray[TEMP_DATA_ARRAY_SIZE] = {};

// Parse comma separated values from a string. Feeds values into tempDataArray[].
void parseData(std::string inString);

int main()
{
	// Display class info.
	std::cout << COURSE_INFO << std::endl;

	// Create an instance of Roster called classRoster.
	Roster classRoster = Roster();

	std::cout << "Populating class roster. . ." << std::endl;

	for (int i = 0; i < DATA_SIZE; i++)
	{
		parseData(studentData[i]);
		std::string tSid, tFirstName, tLastName, tEmail;
		int tAge, tDay1, tDay2, tDay3;
		DegreeProgram tDegreeProgram;
		tSid = tempDataArray[0];
		tFirstName = tempDataArray[1];
		tLastName = tempDataArray[2];
		tEmail = tempDataArray[3];
		tAge = stoi(tempDataArray[4]);
		tDay1 = stoi(tempDataArray[5]);
		tDay2 = stoi(tempDataArray[6]);
		tDay3 = stoi(tempDataArray[7]);
		if (tempDataArray[8] == "SECURITY")
		{
			tDegreeProgram = SECURITY;
		}
		else if (tempDataArray[8] == "NETWORK")
		{
			tDegreeProgram = NETWORK;
		}
		else if (tempDataArray[8] == "SOFTWARE")
		{
			tDegreeProgram = SOFTWARE;
		}
		else
		{
			tDegreeProgram = UNDERWATER_BASKET_WEAVING;
		}

		classRoster.add(tSid, tFirstName, tLastName, tEmail, tAge, tDay1, tDay2, tDay3, tDegreeProgram);
	}

	std::cout << "\nPrinting class roster. . ." << std::endl;

	// Loop through Roster and print all Student data.
	classRoster.printAll();

	std::cout << "\nPrinting invalid email addresses. . ." << std::endl;

	// Loop through Roster and print all invalid emails.
	classRoster.printInvalidEmails();

	std::cout << "\nPrinting average days in course for each student. . ." << std::endl;

	// Loop through the Roster and print out each student's average days in their courses.
	for (int i = 0; i < DATA_SIZE; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.studentIDfromRoster(i));
	}

	std::cout << "\nPrinting all students with the Software degree program. . ." << std::endl;

	// Print Students assigned with the SOFTWARE DegreeProgram enum.
	classRoster.printByDegreeProgram(SOFTWARE);

	std::cout << std::endl;

	// Remove Student assigned with "A3" as their studentID.
	classRoster.remove("A3");

	std::cout << "\nPrinting class roster. . ." << std::endl;

	// Show the Student has been removed from the Roster.
	classRoster.printAll();

	std::cout << std::endl;

	// Show an error message when an attemp is made to remove a Student object that does not exist.
	classRoster.remove("A3");

	// Release dynamically allocated memory in Roster.
	classRoster.~Roster();

}

void parseData(std::string inString)
{
	std::string container = inString;
	std::istringstream inSS(container);
	std::string token;
	int i = 0;
	while (getline(inSS, token, ','))
	{
		tempDataArray[i] = token;
		i++;
	}
}
