#include <iostream>

int num_digits_rec(int num)
{
	if(num == 0)
		return 0;
	return 1 + num_digits_rec(num/10);
}

int main(int argc, char const *argv[])
{
	std::cout << "num digits of 5 -> " << num_digits_rec(5) << std::endl;
	std::cout << "num digits of 10 -> " << num_digits_rec(10) << std::endl;
	std::cout << "num digits of 15 -> " << num_digits_rec(15) << std::endl;
	std::cout << "num digits of 150 -> " << num_digits_rec(150) << std::endl;
	std::cout << "num digits of 105 -> " << num_digits_rec(105) << std::endl;

	return 0;
}