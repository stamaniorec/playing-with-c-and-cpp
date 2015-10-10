#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string name = "Ivan Ivanov Petrov";
	int num_of_spaces = 0;
	bool flag = false;
	int counter = 0;
	for(int i = 0; i < name.length(); i++)
	{
		if(name[i] == ' ')
			num_of_spaces++;
		if(num_of_spaces == 2 && name[i] != ' ')
			counter++;
	}
	cout << "Length of last name: " << counter << endl;
	return 0;
}