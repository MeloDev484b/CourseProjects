#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

using namespace std;

const int DATA_SIZE = 5;
const string COURSE_INFO = "Course title: Scripting and Programming - Applications – C867\nProgramming language used: C++\nStudent ID: #009880493\nStudent name: Dylan Melone\n";
const string studentData[DATA_SIZE] =
{ 
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Dylan,Melone,dmelone@wgu.edu,28,7, 7, 7,SOFTWARE" 
};

int main()
{
	cout << COURSE_INFO << endl;
	Roster classRoster = Roster();

	classRoster.add("A1", "Dylan", "Melone", "dybmelone@gmail.com", 28, 4, 5, 6, SOFTWARE);
	classRoster.add("A2", "Halima", "Khan  ", "hk@gm ail.com", 25, 7, 8, 9, NETWORK);
	classRoster.add("A3", "Tyler", "Melone", "tm@gmail.com", 25, 66, 7, 79, SOFTWARE);
	classRoster.add("A4", "Connor", "Melone", "cmgmail.com", 22, 22, 15, 61, SECURITY);
	classRoster.add("A5", "Mango", "Bango", "mb@gmailcom", 2, 43, 54, 69, SOFTWARE);

	classRoster.printAll();
	classRoster.printInvalidEmails();

	cout << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.studentIDfromRoster(i));
	}

	cout << endl << endl;

	classRoster.printByDegreeProgram(SOFTWARE);

	cout << endl << endl;

	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	classRoster.~Roster();

}

