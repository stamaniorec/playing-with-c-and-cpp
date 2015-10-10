#include <iostream>
#include <map>
#include <string>

/*Implement a small address book program that allows users to enter names and email addresses,
remove or change entries, and list the entries in their address book. Don’t worry about saving
the address book to disk; it’s ok to lose the data when the program exits.*/

using namespace std;

void print_menu()
{
	cout << "OPTIONS: " << endl;
	cout << "1. New entry." << endl;
	cout << "2. Remove entry" << endl;
	cout << "3. Change entry" << endl;
	cout << "4. List address book" << endl;
	cout << "5. Exit" << endl;
}

int read_option()
{
	int user_option;
	while(true)
	{
		cin >> user_option;
		if(user_option >= 1 && user_option <= 5)
			break;
		cout << "Invalid option. Please try again." << endl;
	}
	return user_option;	
}

int main(int argc, char const *argv[])
{
	map<string, string> address_book;
	map<string, string>::iterator itr;
	bool done = false;
	int user_option;
	string name, email;

	while(!done)
	{
		print_menu();
		user_option = read_option();

		switch(user_option)
		{
			case 1:
				cout << "Enter a name: ";
				cin >> name;

				cout << "Enter an email address: ";
				cin >> email;
				
				address_book[name] = email; 
				break;
			case 2:
				cout << "Enter the name you want to delete: ";
				cin >> name;
				
				address_book.erase(name);
				break;
			case 3: 
				cout << "Enter the name of the person whose email you want to change: ";
				cin >> name;
				
				cout << "Enter the new email: ";
				cin >> email;
				
				itr = address_book.find(name);
				address_book[name] = email;
				break;
			case 4: 
				itr = address_book.begin();
				while(itr != address_book.end())
				{
					cout << itr->first << ": " << itr->second << endl;
					itr++;
				}
				break;
			case 5: 
				done = true;
				break;
		}
	}

	return 0;
}