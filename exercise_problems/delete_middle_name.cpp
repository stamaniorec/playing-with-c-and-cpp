#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string name = "Ivan Ivanov Petrov";
	int index;
	int num_of_spaces = 0;
	for(int i = 0; i < name.length(); i++)
	{
		if(name[i] == ' ')
		{
			num_of_spaces++;
			if(num_of_spaces == 1)
				index = i;
		}
		if(num_of_spaces == 2)
		{
			name[++index] = name[i+1];	
		}
	}
	for(int j = index; j < name.length(); j++)
	{
		name[j] = '\0';
	}
	cout << name << endl;
	return 0;
}