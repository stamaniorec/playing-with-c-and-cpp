#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string my_string, int index)
{
	static int counter = 0;
	static int midpoint = index / 2;
	
	if ( my_string[index] != my_string[counter] )
		return false;

	if ( counter == midpoint )
		return true;

	counter++;

	return is_palindrome(my_string, index - 1);
}

int main()
{
	string my_string;
	
	cout << "Enter string: ";
	cin >> my_string;
	
	cout << is_palindrome(my_string, my_string.length() - 1);

	return 0;
}
