#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> my_vector;
	int highscore, i;

	while(true)
	{
		cout << "Enter highscore: ";
		cin >> highscore;
		
		// enter 0 to exit
		if(!highscore)
			break;
		
		i = 0;

		if(!my_vector.empty())
		{
			while(my_vector[i] > highscore)
			{
				i++;
			}
		}
		
		my_vector.insert(my_vector.begin() + i, highscore);
	}

	for(unsigned int i = 0; i < my_vector.size(); i++)
	{
		cout << my_vector[i] << " ";
	}

	return 0;
}