#include "Alien.h"
#include<cstdlib>

char generateGender();

Alien::Alien(int weight, int height, char gender)
{
	this->weight = weight;
	this->height = height;
	this->gender = gender;
}
int Alien::getWeight() const
{
	return weight;
}
int Alien::getHeight() const
{
	return height;
}
char Alien::getGender() const
{
	return gender;
}
int Alien::getPrestige(char gender) const
{
	int prestige;
	if (int(gender) > 102)
	{
		prestige = height * weight * 2;
	}
	else
	{
		prestige = height * weight * 3;
	}
	return prestige;
}


bool Alien::operator==(const Alien& other) const
{
	return getPrestige(gender) == other.getPrestige(other.gender);
}
bool Alien::operator!=(const Alien& other) const
{
	return getPrestige(gender) != other.getPrestige(other.gender);
}
bool Alien::operator>(const Alien& other) const
{
	return getPrestige(gender) > other.getPrestige(other.gender);
}
bool Alien::operator>=(const Alien& other) const
{
	return getPrestige(gender) >= other.getPrestige(other.gender);
}
bool Alien::operator<(const Alien& other) const
{
	return getPrestige(gender) <= other.getPrestige(other.gender);
}
bool Alien::operator<=(const Alien& other) const
{
	return getPrestige(gender) <= other.getPrestige(other.gender);
}

void Alien::operator=(const Alien& other)
{
	weight = other.weight;
	height = other.height;
	gender = other.gender;
}
Alien Alien::operator+(const Alien& other) const
{
	Alien newAlien((weight + other.weight)/2, (height + other.height)/2, generateGender());
	return newAlien;
}

char generateGender()
{
	char genderChar;
	int chance = rand() % 10 + 1;
	if (chance <= 7)
	{
		genderChar = 'm';
	}
	else
	{
		genderChar = 'f';
	}
	return genderChar;
}