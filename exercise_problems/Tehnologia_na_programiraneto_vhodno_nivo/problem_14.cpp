#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int number)
{
	bool flag = true;
	for(int i = 2; i <= sqrt(number); i++ )
	{
		if(number % i == 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

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
	int array[10];
	int number = 2;
	int a = 0;

	while(a < 10 && is_prime(x) && x != 2 && x != 5)
	{
		if(is_prime(number))
		{
			if(number % 10 == x)
			{
				array[a] = number;
				a++;
			}
		}
		number++;
	}

	if(x == 2 || !is_prime(x) || x == 5)
	{
		cout << "impossibru" << endl;
	}
	else
	{
		for(int i = 0; i < 10; i++)
		{
			cout << array[i] << " ";
		}	
	}

	return 0;
}