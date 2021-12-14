#include <iostream>
#include "Circle.h"
#include <string>
#include <cmath>

using namespace std;

void printCircleAttributes(const Circle& circle);
void circleNameInput();
void circleRadiusInput();

string circleName;
double radiusInput;

int main()
{
	circleNameInput();
	
	//-----Test Code-----//
	//Circle circle1(5);
	//printCircleAttributes(circle1);

	//circle1.setRadius(12);
	//printCircleAttributes(circle1);
	return 0;
}

void printCircleAttributes(const Circle& circle)
{
	cout << "Attributes of a circle with a radius of " << circle.getRadius() << " units:" << endl
		<< "Area: " << circle.getArea() << endl
		<< "Diameter: " << circle.getCircumference() << endl;
}

void circleNameInput()
{
	cout << "Enter the name of the circle you would like to create." << endl;
	getline(cin, circleName);
	circleRadiusInput();
}
void circleRadiusInput()
{
	cout << "Enter the radius of the circle you would like to create." << endl;
	cin >> radiusInput;
	if (radiusInput != 0)
	{
		Circle circleName(radiusInput);
		printCircleAttributes(circleName);
	}
	else
	{
		cout << "Please pick a number greater than 0." << endl;
		circleRadiusInput();
	}
}