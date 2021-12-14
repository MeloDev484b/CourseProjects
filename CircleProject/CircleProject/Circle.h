#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
	public:
		Circle();
		Circle(double radius);
		void setRadius(double newRadius);
		double getRadius() const;
		double getArea() const;
		double getCircumference() const;
	private:
		int circumference;
		int area;
		int radius;
};


#endif // !CIRCLE_H

