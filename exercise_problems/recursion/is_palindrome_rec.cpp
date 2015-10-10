#include <iostream>

bool is_palindrome_rec(std::string string, int cur_index)
{
	if(cur_index >= string.length() / 2)
		return true;
	return (string[cur_index] == string[string.length()-cur_index-1]) && is_palindrome_rec(string, cur_index+1);
}

int main(int argc, char const *argv[])
{
	std::string a = "aabb";
	std::string b = "abba";
	std::string c = "aba";
	std::string d = "kiril e lirik";
	std::string e = "not a palindrome";

	std::cout << "palindrome? " << a << " -> " << is_palindrome_rec(a, 0) << std::endl;
	std::cout << "palindrome? " << b << " -> " << is_palindrome_rec(b, 0) << std::endl;
	std::cout << "palindrome? " << c << " -> " << is_palindrome_rec(c, 0) << std::endl;
	std::cout << "palindrome? " << d << " -> " << is_palindrome_rec(d, 0) << std::endl;
	std::cout << "palindrome? " << e << " -> " << is_palindrome_rec(e, 0) << std::endl;
	
	return 0;
}