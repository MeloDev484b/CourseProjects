#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Mage.h"
#include "Priest.h"
#include "Warrior.h"
using namespace std;

vector <Player*> characterVect{};

Race getRace(int raceNum);

int classSelectionNum;
int raceSelectionNum;
string nameSelection;

void characterCreation();
Player* instanceCharacter(string name, int characterClassNum, int raceNum);
void finishedWithCreation();
void printCharacters();
void deleteCharacters();


int main()
{
	characterCreation();
	return 0;
}

Race getRace(int raceNum)
{
	Race race;

	if (raceNum == 1)
	{
		race = HUMAN;
	}
	else if (raceNum == 2)
	{
		race = ELF;
	}
	else if(raceNum == 3)
	{
		race = DWARF;
	}
	else if (raceNum == 4)
	{
		race = ORC;
	}
	else if (raceNum == 5)
	{
		race = TROLL;
	}

	return race;
}

void characterCreation()
{
	cout << "What type of character would you like to create? \n1 - Warrior\t2 - Priest\t3 - Mage\n";
	cin >> classSelectionNum;
	cout << "What race would you like your character to be? \n1 - Human\t2 - Elf\t3 - Dwarf\t4 - Orc\t5 - Troll";
	cin >> raceSelectionNum;
	cout << "What is the name of your character?\n";
	cin >> nameSelection;
	characterVect.push_back(instanceCharacter(nameSelection, classSelectionNum, raceSelectionNum));
	finishedWithCreation();
}
Player* instanceCharacter(string name, int characterClassNum, int raceNum)
{
	Race playerRace = getRace(raceNum);

	Player* playerCharacter = nullptr;

	if (characterClassNum == 1)
	{
		playerCharacter = new Warrior(name, playerRace);
	}
	else if (characterClassNum == 2)
	{
		playerCharacter = new Priest(name, playerRace);
	}
	else if (characterClassNum == 3)
	{
		playerCharacter = new Mage(name, playerRace);
	}
	return playerCharacter;
}
void finishedWithCreation()
{
	string input;
	cout << "Would you like to continue creating characters?\n";
	cout << "Y/N\n";
	cin >> input;
	if (input == "Y" || input == "y")
	{
		characterCreation();
	}
	else if (input == "N" || input == "n")
	{
		printCharacters();
		deleteCharacters();
	}
}
void printCharacters()
{
	for (Player* player: characterVect)
	{
		cout << "I'm a " << player->whatRace() <<
			" and my attack is: " << player->attack() << "\n";
	}
}
void deleteCharacters()
{
	for (Player* player : characterVect)
	{
		delete player;
	}
}