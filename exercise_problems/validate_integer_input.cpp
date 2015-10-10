#include <iostream>
#include <string>

using namespace std;

bool validate_input(string string)
{
	bool flag = true;
	
	for ( unsigned int i = 0; i < string.size(); i++ )
	{
		if (string[i] < '0' || string[i] > '9')
		{
			flag = false;
			break;
		}
	}

	return flag;

}

int main()
{
	string string;
	
	cout << "Please enter a number: ";
	cin >> string;

	while (!validate_input(string))
	{
		cout << "Error, please try again." << endl;
		cin >> string;
	}

	cout << "Everything went ok." << endl;

	return 0;
}
