#ifndef PRIEST_H
#define PRIEST_H

#include "Player.h"

class Priest : public Player
{
public:
	Priest(string name, Race race) : Player(name, race, 100, 200)
	{
	}

	string attack() const
	{
		return "I will mess you up with some holy-light!";
	}
};

#endif // !PRIEST_H

