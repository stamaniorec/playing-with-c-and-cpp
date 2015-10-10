#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector; //myVector(5) 5 -> creates 5 elements that are 0
	// myVector(5,100); -> creates 5 elements with an initial value of 100  

	cout << "Enter the numbers you want to sum, please. Enter 0 to exit." << endl;

	int i = 0, sum = 0, holder = 0;

	myVector.reserve(10);
	// like an initial length
	// basically we just don't wanna reallocate memory over and over

	while(1)
	{
		cin >> holder; // we can't do cin >> myVector[i]
		if ( holder == 0 )
		{
			break;
		}
		myVector.push_back(holder);
		sum += myVector[i];
		i++;
	}

	cout << "The sum is: " << sum << endl;

	// j needs to be unsigned; gives error otherwise
	// capacity() is basically what we have from reserve()
	// myVector.size();
	for ( unsigned int j = 0; j < myVector.size(); j++ )
	{
		cout << myVector[j] << " ";
	}

	return 0;
}
