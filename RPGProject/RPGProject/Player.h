#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

enum Race{ HUMAN, ELF, DWARF, ORC, TROLL };

class Player
{
	public:
		Player(string name, Race race, int hitPoints, int magicPoints);
		string getName() const;
		Race setRace() const;
		string whatRace() const;
		int getHitPoints() const;
		int getMagicPoints() const;
		void setName(string name);
		void setRace(Race race);
		void setHitPoints(int hitPoints);
		void setMagicPoints(int magicPoints);
		virtual string attack() const = 0;

	private:
		string name;
		Race race;
		int hitPoints;
		int magicPoints;
};

#endif // !PLAYER_H
