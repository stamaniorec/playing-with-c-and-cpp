#include <iostream>

using namespace std;

/*
Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10. 
Да се инициализира масив от 10 елемента. 
Да се намери първото число N в интервала [0; +∞) делящо се на х. 
Да се намери сумата на всички числа в интервала [0; N] и да се запише като първи елемент в масива.
 Да се намери второто число N' в интервала [0; +∞) делящо се на x. 
 Да се намери сумата на всички числа в интервала [0, N'] и да се запише като втори елемент в масива. 
 Аналогично да се запълнят и останалите елементи на масива. Масивът да се изведе на стандартния изход.
*/

int main(int argc, char const *argv[])
{
	int x;
	cout << "Enter x: ";
	while(1)
	{
		cin >> x;
		if(x > 0 && x <10)
			break;
		cout << "Error, please try again." << endl;
	}
	int array[10];
	int k = 1;
	int a = 0;
	int sum_of_natural_numbers;
	while(1)
	{
		sum_of_natural_numbers = 0;
		if(k % x == 0)
		{
			for(int i = 1; i <= k; i++)
			{
				sum_of_natural_numbers += i;
			}
			array[a] = sum_of_natural_numbers;
			a++;
			if(a == 10)
				break;
		}
		k++;
	}
	for(int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}