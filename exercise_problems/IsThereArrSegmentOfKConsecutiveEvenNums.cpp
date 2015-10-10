#include <iostream>

using namespace std;

// Constraints I haven't taken care of but should: 
// 1 <= T <= 10
// 1 <= n <= 50
// 0 <= k <= n
// 1 <= a<sub>i</sub> <= 100
// Time limit 1s
// Source limit 50MB

int main(int argc, char const *argv[])
{
	// Enter number of test cases
	int T;
	cin >> T;

	int n, k;
	int arr[100];
	bool flag;

	// For every test case
	for(int i = 0; i < T; ++i)
	{
		// Read an array length n and a length of consecutive even numbers segment in array we're looking for
		cin >> n >> k;

		// Read the array
		for(int j = 0; j < n; ++j)
		{
			cin >> arr[j];
		}

		for(int p = 0; p <= n - k; ++p)
		{
			flag = true; 
			for(int q = 0; q < k; ++q)
			{
				if(arr[p+q] % 2 != 0)
				{
					flag = false;
					break;
				}
			}

			if(flag)
			{
				cout << "YES" << endl;
				break;
			}
		}

		if(!flag)
			cout << "NO!" << endl;
	}

	return 0;
}