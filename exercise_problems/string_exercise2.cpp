#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/*
Alex Allain, webmaster@cprogramming.com
John Smith, john@nowhere.com
*/

int main()
{
    cout << "Start entering CSV data please. " << endl;
    cout << "Press enter to exit." << endl;

    vector<string> file;
    map<char, int> characters;
    string input_line;
    int number_of_lines = 0;

    while(true)
    {
        getline(cin, input_line);
        if(input_line.empty())
        {
            cout << "Done!" << endl;
            break;
        }
        file.push_back(input_line);
        number_of_lines++;
    }

    for(int i = 0; i < file.size(); i++)
    {
        for(int j = 0; j < file[i].length(); j++)
        {
            if((file[i].at(j) < 'a' || file[i].at(j) > 'z') &&
               (file[i].at(j) < 'A' || file[i].at(j) > 'Z') &&
               (file[i].at(j) < '0' || file[i].at(j) > '9'))
            {
                characters[file[i].at(j)]++;
            }
        }
    }

    cout << "Please choose a separator character between: ";
    map<char, int>::iterator itr = characters.begin();
    while(itr != characters.end())
    {
        if(itr->second == number_of_lines)
            cout << itr->first << " ";
        itr++;
    }

    return 0;
}
