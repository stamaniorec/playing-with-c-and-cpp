#include <iostream>
#include <cstdlib>

int f(int faces_weight[], int i, int suits_weight[], int j, int in, int sum, int target)
{
	// For the k-th member of the hand, sum equals the hand weight of the k-1-th members of the hand. 
	if(in >= 6)
		return sum == target;

	int res = 0;
	res += f(faces_weight, i+1, suits_weight, 0, in+1, sum+in*10*faces_weight[i]+suits_weight[j], target);
	// If this hand is a match, when in is 5, it will overcount because the function will return 1 four times with in=6.
	if(in < 5) 
	{
		res += f(faces_weight, i+1, suits_weight, 1, in+1, sum+in*10*faces_weight[i]+suits_weight[j], target);
		res += f(faces_weight, i+1, suits_weight, 2, in+1, sum+in*10*faces_weight[i]+suits_weight[j], target);
		res += f(faces_weight, i+1, suits_weight, 3, in+1, sum+in*10*faces_weight[i]+suits_weight[j], target);
	}
	
	return res;
}

int main(int argc, char const *argv[])
{
	int faces_weight[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	int suits_weight[] = {1, 2, 3, 4};

	int target;
	std::cin >> target;
	
	int res = 0;
	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			res += f(faces_weight, i, suits_weight, j, 1, 0, target);
		}
	}

	std::cout << res << std::endl;

	return 0;
}


