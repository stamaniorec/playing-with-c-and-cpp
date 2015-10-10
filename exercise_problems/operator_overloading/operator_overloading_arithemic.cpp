#include <iostream>

using namespace std;

class Crap
{
private: 
	int value;
public:
	Crap() : value(0){};
	Crap(int value) : value(value){};
	int get_value(){ return value; }
	friend Crap operator+(const Crap& a, const Crap& b);
	friend Crap operator+(const Crap& a, int b);
	friend Crap operator+(int a, const Crap& b);
	friend Crap operator+=(const Crap& a, const Crap& b);
};

Crap operator+(const Crap& a, const Crap& b)
{
	return Crap(a.value + b.value);
}

Crap operator+(const Crap& a, int b)
{
	return Crap(a.value + b);
}

Crap operator+(int a, const Crap& b)
{
	return Crap(a + b.value);
}

int main(int argc, char const *argv[])
{
	Crap crap(5);
	crap = crap + Crap(10);
	crap = crap + 100;
	crap = 1000 + crap;
	crap = crap + 5 + 30 + Crap(1000);
	cout << crap.get_value() << endl;
	return 0;
}