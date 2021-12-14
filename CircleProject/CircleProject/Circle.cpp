#define _USE_MATH_DEFINES
#include <iostream>
#include "Circle.h"
#include <cmath>

using namespace std;

Circle::Circle()
{
	this->radius = radius;
	this->circumference = circumference;
	this->area = area;
}
Circle::Circle(double radius)
{
	this->radius = radius;
	this->circumference = M_PI * (2 * radius);
	this->area = M_PI * (radius * radius);
}
void Circle::setRadius(double newRadius)
{
	radius = newRadius;
	area = M_PI * (radius * radius);
	circumference = M_PI * (2 * radius);
}
double Circle::getRadius() const
{
	return radius;
}
double Circle::getArea() const
{
	return area;
}
double Circle::getCircumference() const
{
	return circumference;
}