#include <iostream>
#include <string>

using namespace std;

int main ()
{
	while ( true )
	{
		string first_name;
		getline( cin, first_name, ',' );

		if ( first_name.size() == 0 )
		{
			break;
		}

		string last_name;
		getline( cin, last_name, ',' );
		
		string player_class;
		getline( cin, player_class, '\n' );
		
		cout << first_name << " " << last_name << " is a " <<
			player_class << endl;
	}

	return 0;
}
