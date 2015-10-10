#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;
int main()
{   
    string str1;
    string str2;
    int T;
    cin >> T;
    int flag;
    bool visited[100] = {false};
    for(int i = 0; i < T; i++)
    {
        cin >> str1 >> str2;
        for(int z = 0; z < 100; z++)
        {
        	visited[z] = false;
        }
        if(str1.length() == str2.length())
        {
            for(int j = 0; j < str1.length(); j++)
            {
                flag = 0;
                for(int k = 0; k < str2.length(); k++)
                {
                    if((str1[j] == str2[k]) && !visited[k])
                    {
                        flag = 1;
                        visited[k] = true;
                        break;
                    }
                }
            }
            if(!flag)
			{
			    cout << "NO" << endl;
			}
			else
			{
			    cout << "YES" << endl;
			}
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
