#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string name = "Ivan Ivanov Petrov";
	int num_of_spaces = 0;
	int length_of_middle_name = 0;
	int length_of_last_name = 0;
	for(int i = 0; i < name.length(); i++)
	{
		if(name[i] == ' ')
		{
			num_of_spaces++;
		}
		if(num_of_spaces == 1)
			length_of_middle_name++;
		if(num_of_spaces == 2)
			length_of_last_name++;
	}
	if(length_of_last_name == length_of_middle_name)
		cout << "Yes." << endl;
	else
		cout << "No." << endl;
	return 0;
}