#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{   
    int T;
    string input;
    stack<char> stacky;
    cin >> T;
    getline(cin, input);
    for(int i = 0; i < T; i++)
    {
        getline(cin, input);
        for(int j = input.length() - 1; j >= 0; j--)
        {
            if(input[j] != ' ')
            {
                stacky.push(input[j]);
            }
            else
            {
                while(!stacky.empty())
                {
                    cout << stacky.top();
                    stacky.pop();
                }
                cout << " ";
            }
        }
        while(!stacky.empty())
        {
            cout << stacky.top();
            stacky.pop();
        }
        cout << endl;
    }
}
