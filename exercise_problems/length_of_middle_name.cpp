#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string name = "Ivan Ivanov Ivanov";
	int flag = 0;
	int counter = 0;
	int num_of_spaces = 0;
	for(int i = 0; i < name.length(); i++)
	{
		if(name[i] == ' ')
		{
			num_of_spaces++;
		}

		if(num_of_spaces == 1 && name[i] != ' ')
			counter++;
	}
	cout << "Length of middle name: " << counter << endl;
	return 0;
}