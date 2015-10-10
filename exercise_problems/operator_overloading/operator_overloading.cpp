#include <iostream>

using namespace std;

class Crap
{
private: 
	int value;
	int array[10];
public:
	Crap(int data=0) : value(data)
	{
		for(int i = 0; i < 10; i++)
		{
			array[i] = i;
		}
	};
	int get_value() { return value; }
	friend ostream& operator<<(ostream &out, Crap &crap);
	friend Crap operator+(const Crap &obj1, const Crap &obj2);
	friend Crap operator+(const Crap &crap, int data);
	friend Crap operator+(int data, const Crap &crap);
	friend istream& operator>>(istream &in, Crap &crap);
	friend bool operator!(Crap &crap);
	Crap operator++()
	{
		return ++value;
	}
	Crap operator++(int)
	{
		return value++;
	}
	int& operator[](int index)
	{
		return array[index];
	}
};

ostream& operator<<(ostream &out, Crap &crap)
{
	out << "Value: " << crap.value << endl;
	return out;
}

Crap operator+(const Crap &obj1, const Crap &obj2)
{
	return Crap(obj1.value + obj2.value);
}

Crap operator+(const Crap &crap, int data)
{
	return Crap(crap.value + data);
}

Crap operator+(int data, const Crap &crap)
{
	return Crap(data + crap.value);
}

istream& operator>>(istream &in, Crap &crap)
{
	in >> crap.value;
	return in;
}

bool operator!(Crap &crap)
{
	return crap.value == 0;
}

int main(int argc, char const *argv[])
{
	Crap crap;
	if(!crap)
		cout << "Value is 0." << endl;
	cin >> crap;
	cout << crap;
	crap = crap + Crap(100);
	cout << crap;
	crap = crap + 15000;
	crap = 5000 + crap;
	cout << crap;
	if(!crap)
		cout << "Wut?" << endl;
	++crap;
	cout << crap;
	crap++;
	cout << crap;

	cout << " --- --- --- " << endl;

	cout << crap[5] << endl;
	crap[5] = 500;
	cout << crap[5] << endl;
	
	return 0;
}