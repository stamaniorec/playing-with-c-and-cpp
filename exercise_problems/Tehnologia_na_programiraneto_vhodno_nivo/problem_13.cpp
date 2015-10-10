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
	int array[10];
	int sum = 0;
	for(int i = 0; i < 10; i++ )
	{
		sum = 0;
		for(int j = 1; j < 1000; j++)
		{
			if(j % (x*(i+1)) == 0)
			{
				sum += j;
			}
		}
		array[i] = sum;
	}

	for(int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	
	return 0;
}