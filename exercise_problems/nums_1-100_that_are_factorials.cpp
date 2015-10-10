#include <iostream>

using namespace std;

int main()
{
	int factorial;
	for ( int i = 1; i < 100; i++ )
	{
		for ( int j = i; j > 1; j-- )
		{
			factorial = 1;
			for ( int k = j; k > 1; k-- )
			{
				factorial *= k;
			}
			if ( factorial == i )
			{	
				cout << i << " ";
			}
		}
		
	}
	return 0;
}
