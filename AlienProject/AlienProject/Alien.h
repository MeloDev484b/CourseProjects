#ifndef ALIEN_H
#define ALIEN_H

class Alien
{
public:
	Alien(int weight, int height, char gender);
	int getWeight() const;
	int getHeight() const;
	char getGender() const;
	int getPrestige(char gender) const;

	bool operator==(const Alien& other) const;
	bool operator!=(const Alien& other) const;
	bool operator>(const Alien& other) const;
	bool operator>=(const Alien& other) const;
	bool operator<(const Alien& other) const;
	bool operator<=(const Alien& other) const;
	void operator=(const Alien& other);
	Alien operator+(const Alien& other) const;
private:
	int weight;
	int height;
	char gender;
};

#endif // !ALIEN_H

