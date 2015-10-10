#include <iostream>

using namespace std;

class Player
{
private: 
	int lives;
	int damage;
	int defense;
public:
	Player() : lives(3), damage(0), defense(0){}
	Player(int damage1, int defense1) : lives(3), damage(damage1), defense(defense1){}
	friend Player operator+(const Player& p1, const Player& p2)
	{
		return Player(p1.damage + p2.damage, p1.defense + p2.defense);
	}
	friend ostream& operator<<(ostream &out, Player &player)
	{
		out << "Number of lives: " << player.lives << endl << 
			"Damage: " << player.damage << endl << 
			"Defense: " << player.defense << endl;
		return out;
	}
	friend istream& operator>>(istream &in, Player &player)
	{
		cout << "Enter damage: ";
		in >> player.damage;
		cout << "Enter defense: ";
		in >> player.defense;
		return in;
	}
};

int main(int argc, char const *argv[])
{
	Player player1;
	cin >> player1;
	cout << player1;

	Player player2;
	cin >> player2;
	cout << player2;

	player1 = player1 + player2;
	cout << player1;
	return 0;
}