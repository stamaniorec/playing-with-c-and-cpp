#include <iostream>
#include <math.h>

using namespace std;

/*Да се разработи програма, която изисква от потребителя да въведе целочислено число x, 
където x e интервала [0; +∞). 
Да се намерят първите 10 нечетни числа делители на x и да се запишат в масив. 
Масивът да се изведе на екрана и да се намерят простите числа в този масив.*/

bool is_prime(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int x;
	cout << "Enter x: ";
	while(1)
	{
		cin >> x;
		if(x >= 0)
			break;
		cout << "Error, please try again." << endl;
	}
	int array[10];
	int counter = 0;
	int number = 1;
		for (int i = 0; i < 10; ++i)
	{
		array[i] = 0;
	}
	while(number <= x)
	{
		if(number % 2 != 0)
		{
			if(x % number == 0)
			{
				array[counter] = number;
				counter++;
			}
		}
		number++;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl << "The prime numbers are: " << endl;
	for (int i = 0; i < 10; ++i)
	{
		if(is_prime(array[i]) && array[i] != 0)
		{
			cout << array[i] << " ";
		}
	}
	cout << endl;
	return 0;
}