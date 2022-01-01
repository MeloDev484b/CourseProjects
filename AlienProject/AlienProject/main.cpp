#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Alien.h"
using namespace std;

int main()
{
	srand(time(NULL));

	Alien alien1(20, 50, 'f');
	Alien alien2(50, 15, 'm');
	Alien alien3(15, 15, 'f');

	cout << "Parent Alien stats: " << endl;
	cout <<"mom: " << endl;
	cout << alien1.getGender() << endl;
	cout << alien1.getHeight() << endl;
	cout << alien1.getWeight() << endl;
	cout << alien1.getPrestige(alien1.getGender()) << endl;
	cout << endl;
	cout << "dad: " << endl;
	cout << alien2.getGender() << endl;
	cout << alien2.getHeight() << endl;
	cout << alien2.getWeight() << endl;
	cout << alien2.getPrestige(alien2.getGender()) << endl;

	Alien babyAlien = alien1 + alien2;
	cout << endl;
	cout << "Baby Alien stats: " << endl;
	cout << babyAlien.getGender() << endl;
	cout << babyAlien.getHeight() << endl;
	cout << babyAlien.getWeight() << endl;
	cout << babyAlien.getPrestige(babyAlien.getGender()) << endl;
	cout << endl;
	cout<<boolalpha<<(alien1 == alien2);
	return 0;
}