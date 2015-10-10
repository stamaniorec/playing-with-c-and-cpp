#include <iostream>

int knapsack(int *values, int *weights, int n, int capacity_weight, int cur_value)
{
	int best = 0;
	bool anymore_left = false;

	for(int i = 0; i < n; ++i)
	{
		if(weights[i] <= capacity_weight)
		{
			int ret = knapsack(values+i+1, weights+i+1, n-1, capacity_weight-weights[i], cur_value+values[i]);
			if(ret > best) best = ret;
			anymore_left = true;
		}
	}

	if(!anymore_left)
		return cur_value;

	return best;
}

int main(int argc, char const *argv[])
{
	int values[] = {60, 100, 120};
   	int weights[] = {10, 20, 30};
	int capacity_weight = 50;
	int n = sizeof(values)/sizeof(int);

	std::cout << knapsack(values, weights, n, capacity_weight, 0) << std::endl;

	return 0;
}
