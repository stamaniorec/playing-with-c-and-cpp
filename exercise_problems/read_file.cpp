#include <iostream>
#include <fstream> 
#include <string>

int main()
{
	std::ifstream file("info.txt");

	std::string name;
	int age;
	float random;
	
	while(file >> name >> age >> random)
	{
		std::cout << "Record: " << name << "; " << 
			age << "; " << random << std::endl;
	}

	return 0;
}
