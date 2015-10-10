/*
Да се разработи програма, която изисква от потребителя да въведе число x, където 0<x<1. Да се намери числото пи 
чрез следното развитие в ред:
4-4/3+4/5-4/7+4/9-4/11+...4/N. Развитието в ред спира при 4/N<x. Получената стойност за пи да се изведе на екрана.
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	float x;
	cout << "Enter x: ";
	while(1)
	{
		cin >> x;
		if ( x > 0.00 && x < 1.00 )
			break;
		cout << "Error. Please try again." << endl;
	}
	
	bool even = false;
	float result = 0.00;
	int a;
	for(float n = 1; 4/n >=x; n += 2)
	{
		if(!even)
		{
			result += (4/n);
			even = true;
		}
		else
		{
			result -= (4/n);
			even = false;;
		}
		cout << result << endl;
	}

	cout << result << endl;
	
	return 0;
}