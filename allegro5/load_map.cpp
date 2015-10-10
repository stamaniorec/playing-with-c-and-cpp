#include <iostream>
#include <fstream>
#include <sstream>

// not the best approach
// using a vector of vectors would be better
// but hey, at least I did this myself

int get_dimension_file()
{
	std::ifstream file("map.txt");
	if(!file.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return -1;
	}
	std::string line;
	getline(file, line);
	std::stringstream stream(line);
	int dimension = 0;
	int holder;
	while(stream >> holder)
	{
		++dimension;
	}
	file.close();
	return dimension;
}

int main()
{
	std::ifstream file("map.txt");
	std::string line;
	int dimension = get_dimension_file();
	int map[dimension][dimension];
	int cur_x = 0, cur_y = 0, value;
	while(file >> value)
	{
		map[cur_y][cur_x++] = value;
		if(cur_x >= dimension)
		{
			cur_x = 0;
			++cur_y;
		}
	}
	for(int i = 0; i < dimension; ++i)
	{
		for(int j = 0; j < dimension; ++j)
		{
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
