#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file("user_input.txt", ios::out | ios::in);

    string name, email;

    if(!file.is_open())
    {
        return -1;
    }

    while(cin >> name >> email)
    {
        file << name << "," << email << endl;
    }

    file.seekg(0);

    string temp = "";
    string text = "";

    while(!file.eof())
    {
        getline(file, temp);
        text += temp;
    }

    cout << text;

    return 0;
}
