#include<iostream>
#include<string>
using namespace std;

int main() {
	string noun1;
	string noun2;
	string noun3;
	string verb1;
	string verb2;
	string verb3;
	string adjective1;
	string adjective2;
	string adverb;
	string person1;
	string person2;
	int number;

	cout << "Welcome to Bad Jibs, the Mad Libs clone just for you and me." << endl;
	cout << " " << endl;
	cout << "Press enter to begin." << endl;

	cin.get();

	cout << " " << endl;

	cout << "Please enter the name of a person." << endl;
	getline(cin, person1);

	cout << "Please enter a noun." << endl;
	getline(cin, noun1);

	cout << "Please enter a verb ending in 'ing'." << endl;
	getline(cin, verb1);

	cout << "Please enter a noun." << endl;
	getline(cin, noun2);

	cout << "Please enter an adjective" << endl;
	getline(cin, adjective1);

	cout << "Please enter a verb." << endl;
	getline(cin, verb2);

	cout << "Please enter an adverb" << endl;
	getline(cin, adverb);

	cout << "Please enter a noun." << endl;
	getline(cin, noun3);

	cout << "Please enter an adjective" << endl;
	getline(cin, adjective2);

	cout << "Please enter the name of another person." << endl;
	getline(cin, person2);

	cout << "Please enter a verb." << endl;
	getline(cin, verb3);

	cout << "Please enter a whole number between 0 and 9001." << endl;
	cin >> number;

	cout << " " << endl;
	cout << "You have completed the Bad Jib. Here is the result: " << endl;
	cout << " " << endl;
	cout << "One day, " << person1 << " was " << verb1 << " their way to the local " << noun1 << " salon." << endl;
	cout << "Unfortunately, there was a giant " << noun2 << " in the middle of the road and it smelled very " << adjective1 << "."<< endl;
	cout << person1 << " began to " << verb2 <<" " << adverb << ", until they ran into a " << noun3 << "." << endl;
	cout << "The resulting injury was extremely " << adjective2 << " and caused " << person2 << " to " << verb3 << " for "<< number<< " days."<<endl;

	return 0;
}