#include <iostream>
#include <string>

using namespace std;

void my_remove(string &input, string str)
{
    int index = input.find(str);
    if(index != string::npos)
        input.erase(index, str.length());
}

void remove_head(string &input)
{
    int index = input.find("<head>");
    if(index != string::npos)
    {
        int index2 = input.find("</head>");
        input.erase(index, index2+7);
    }
}

void find_and_replace(string &input, string my_find, string my_replace)
{
    int index;
    for(int i = input.find(my_find); i != string::npos; i = input.find(my_find, i))
    {
        input.replace(i, my_find.length(), my_replace);
        i++;
    }
}

int main()
{
    string input;
    getline(cin, input);
    int index, index2;

    my_remove(input, "<html>");
    my_remove(input, "</html>");
    remove_head(input);
    my_remove(input, "<body>");
    my_remove(input, "</body>");
    find_and_replace(input, "<b>", "*");
    find_and_replace(input, "</b>", "*");
    find_and_replace(input, "<i>", "_");
    find_and_replace(input, "</i>", "_");

    index = input.find("<a href");
    if(index != string::npos)
    {
        index2 = input.find(">", index);
        input.replace(index, index2+1, "(");
    }
    find_and_replace(input, "</a>", ")");

    cout << input << endl;

    return 0;
}
