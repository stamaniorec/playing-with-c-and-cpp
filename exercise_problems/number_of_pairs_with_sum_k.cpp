#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int test_cases, num_of_elements, sum;
	cin >> test_cases;
	for(int t = 0; t < test_cases; t++)
	{
		cin >> num_of_elements;
		cin >> sum;
		int *array = new int[num_of_elements];
		for(int temp = 0; temp < num_of_elements; temp++)
		{
			cin >> array[temp];
		}
		int counter = 0;
		for(int i = 0; i < num_of_elements; i++)
		{
			for(int j = i+1; j < num_of_elements; j++)
			{
				if(array[i] + array[j] == sum)
				{
					counter++;
				}
			}
		}
		cout << counter << endl;
		delete[] array;
	}
	return 0;
}