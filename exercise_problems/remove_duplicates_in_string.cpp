#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string my_string = "111123345555555";
	int i = 0; 
	int temp = 0;
	while(my_string[i] != '\0')
	{
		while(my_string[i] == my_string[i+1])
		{
			i++;
		}
		my_string[temp] = my_string[i];
		temp++;
		i++;
	}
	my_string[temp] = '\0';
	cout << my_string << endl;
	return 0;
}