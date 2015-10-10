#include <iostream>

using namespace std;

int power(int x, int n)
{
	if ( n == 0 )
	{
		return 1;
	}
	return x * power(x, n-1);
}

int main()
{
	int x, n;

	cout << "Enter x: ";
	cin >> x;

	cout << "Enter n: ";
	cin >> n;

	cout << power(x, n) << endl;

	return 0;
}
