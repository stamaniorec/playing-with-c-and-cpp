#include <iostream>
#include <string>

using namespace std;

int main()
{
    string haystack, needle;

    cout << "Enter haystack string: ";
    getline(cin, haystack);

    cout << "Enter needle string: ";
    getline(cin, needle);

    int number_of_occurrences = 0;
    needle.append(" "); // lalalala -> 0 ; la la la la -> 4

    for(int i = haystack.find(needle); i != string::npos; i = haystack.find(needle, i))
    {
        number_of_occurrences++;
        i++;
    }

    cout << number_of_occurrences << endl;

    return 0;
}
