#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int x; 
	cout << "Enter x: ";
	while(1)
	{
		cin >> x;
		if(x > 0 && x < 10)
			break;
		cout << "Error, please try again." << endl;
	}
	long long array[10];
	long long a = 0;
	long long b = 1;
	int i = 0;
	long long fib;
	for(int i = 0; i < 10; i++)
	{
		array[i] = 0;
	}
	while(1)
	{
		fib = a + b;
		a = b;
		b = fib;
		if(fib % 10 == x)
		{
			array[i] = fib;
			i++;
		}
		if(i == 10)
			break;
	}
	for(int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}