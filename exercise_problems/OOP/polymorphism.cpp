#include <iostream>

using namespace std;

class Player
{
protected:
	int health; 
	int experience;
	int gold;
	int level;
	int damage;
public:
	Player() : health(0), experience(0), gold(0), level(1), damage(0){};
	virtual void print(){};    // those are pure virtual functions in effect
	virtual void level_up(){}; // but it wouldn't compile cos of player object so I made em this way
};

class Dark_elf : public Player
{
public:
	Dark_elf() : Player()
	{
		health = 150;
		damage = 30;
	}
	void print()
	{
		cout << "DE's health: " << health << endl;
		cout << "DE's damage: " << damage << endl;
	}
	void level_up()
	{
		cout << "DE Level up!" << endl;
		level++;
		experience += 100;
		damage += 20;
	}
};

class Dwarf : public Player
{
public:
	Dwarf() : Player()
	{
		health = 200;
		damage = 40;
	}
	void print()
	{
		cout << "Dwarf's health: " << health << endl;
		cout << "Dwarf's damage: " << damage << endl;
	}
	void level_up()
	{
		cout << "Dwarf Level up!" << endl;
		level++;
		experience += 150;
		damage += 50;
	}
};

class Battle_mage : public Player
{
public:
	Battle_mage() : Player()
	{
		health = 100;
		damage = 25;
	}
	void print()
	{
		cout << "BM's health: " << health << endl;
		cout << "BM's damage: " << damage << endl;
	}
	void level_up()
	{
		cout << "Battle Mage Level up!" << endl;
		level++;
		experience += 100;
		damage += 10;
	}
};

int main(int argc, char const *argv[])
{
	cout << "What class do you want to be?" << endl;
	cout << "1. Dark elf" << endl;
	cout << "2. Dwarf" << endl;
	cout << "3. Battle mage" << endl;
	int option;
	while(true) // I'd normally do some better input validation but I won't just for simplicity's sake
	{
		cin >> option;
		if(option >= 1 && option <= 3)
			break;
		cout << "Something went wrong, please try again." << endl;
	}
	Player *player;
	switch(option)
	{
		case 1: 
			player = new Dark_elf;
			break;
		case 2: 
			player = new Dwarf;
			break;
		case 3: 
			player = new Battle_mage;
			break;
	}
	player->print();
	player->level_up();
	player->print();

	delete player;
	return 0;
}