#include <iostream>
#include <math.h>

using namespace std;

/*Да се разработи програма, която изисква от потребителя да въведе число x, където x e интервала (0;1). 
Да се намери сумата от сбора на реципрочните стойности за всеки две twin primes. 
Развитието да продължи докато отношението не стане по-малко то x.*/

// кое отношение?!!?!?!?!?!??!?!

bool is_prime(int n)
{
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	float x;
	cout << "Enter x: ";
	while(1)
	{
		cin >> x;
		if(x > 0.00 && x < 1.00)
			break;
		cout << "Error, please try again." << endl;
	}
	int number = 2;
	int prev_prime = 2;
	int i = 0;
	float result = 0.00;
	while(1)
	{
		if(is_prime(number))
		{
			if(number == (prev_prime + 2))
			{
				result += (((float)1/number) + ((float)1/prev_prime));
			}
			else
			{
				prev_prime = number;
			}
		}
		number++;
		if(i == 10)
			break;
	}
	return 0;
}