#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
Write a program with two options: register user and log in. Register user allows a new user to
create a login name and password. Log in allows a user to log in and access a second area, with
options for “change password” and “log out”. Change password allows the user to change the
password, and log out will return the user to the original screen.
*/

int read_option()
{
	int user_option;
	while(true)
	{
		cin >> user_option;
		if(user_option >= 1 && user_option <= 3)
			break;
		cout << "Invalid option. Please try again." << endl;
	}
	return user_option;	
}

void print_menu()
{
	cout << "1. Register" << endl;
	cout << "2. Log in" << endl;
	cout << "3. Exit" << endl;
}

void register_user(map<string, string> &database)
{
	string username, password;

	cout << "Enter a username: ";
	cin >> username;

	cout << "Enter password: ";
	cin >> password;

	database[username] = password;	
}

string read_username(map<string, string> &database)
{
	string username;
	map<string, string>::iterator itr;

	while(true)
	{
		cout << "Enter a username: ";
		cin >> username;

		itr = database.find(username);
		if(itr == database.end())
		{
			cout << "Username not found. Please try again." << endl;
		}
		else
		{
			break;
		}	
	}
	return username;
}

string read_password(map<string, string> &database, string username)
{
	string password;
	map<string, string>::iterator itr;

	while(true)
	{
		cout << "Enter a password: ";
		cin >> password;

		itr = database.find(username);
		if(itr->second != password)
		{
			cout << "Wrong password. Please try again." << endl;
		}
		else
		{
			break;
		}	
	}
	return password;
}

void private_field(map<string, string> &database, string username)
{
	map<string, string>::iterator itr = database.find(username);
	int input;
	while(true)
	{
		cout << "1. Change password" << endl;
		cout << "2. Log out" << endl;

		cin >> input;
		if((input == 1) || (input == 2))
		{
			break;
		}
		else
		{
			cout << "Invalid option. Please try again." << endl;
		}
	}
	string new_password;
	switch(input)
	{
		case 1: 
			cout << "Enter new password: ";
			cin >> new_password;
			itr->second = new_password;
			break;
		case 2: 
			break;
	}
	
}

int main(int argc, char const *argv[])
{
	int user_option;
	bool done = false;
	string username, password;
	map<string, string> database;

	while(!done)
	{
		print_menu();
		user_option = read_option();

		switch(user_option)
		{
			case 1:
				register_user(database);
				break;
			case 2: 
				username = read_username(database);
				password = read_password(database, username);
				private_field(database, username);
				break;
			case 3: 
				done = true;
		}
	}

	return 0;
}