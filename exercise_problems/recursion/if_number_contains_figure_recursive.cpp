#include <iostream>

using namespace std;

bool is_contained(int n, int k)
{
	
	if ( n == 0 )
	{
		return false;
	}
	
	int figure = n % 10;
	
	if ( figure == k )
	{
		return true;
	}
	
	return is_contained(n/10, k);
}

int main()
{
	int n, k;
	
	cout << "Enter n: ";
	cin >> n;

	cout << "Enter k: ";
	cin >> k;

	cout << is_contained(n, k) << endl;
	
	return 0;
}
