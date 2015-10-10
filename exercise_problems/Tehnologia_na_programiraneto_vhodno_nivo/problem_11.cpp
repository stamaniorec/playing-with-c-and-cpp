#include <iostream>
#include <math.h>

using namespace std;

/* I have no idea whether my program works correctly. :D 
Tho I tested it for the first two or three numbers 
and it appears to be ok. 
*/

int main(int argc, char const *argv[])
{
	int x;
	cout << "Enter x: ";
	while(1)
	{
		cin >> x;
		if(x > 0 && x < 10)
		{
			break;
		}
		cout << "Error, please try again." << endl;
	}	

	float array[10];
	float sum_of_cos_z = 0;

	int n;
	for(n = 0; n < 10; n++)
	{
		sum_of_cos_z = 0;
		for(int j = n*x; j < (n+1)*x; j++)
		{
			sum_of_cos_z += cos(j);
		}
		array[n] = sum_of_cos_z;
	}

	for(int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	
	return 0;
}