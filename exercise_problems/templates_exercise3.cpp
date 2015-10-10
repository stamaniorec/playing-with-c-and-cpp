#include <iostream>
#include <vector>

using namespace std;

template <class T>
bool vector_search(vector<T> v, T value)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == value)
            return true;
    }
    return false;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(10);
    vector<double> v2;
    v2.push_back(1.50);
    v2.push_back(3.14);
    vector<string> v3;
    v3.push_back("Joe");
    string a = "Joe "; // for some reason calling vector_search(v3, "Joe") gives an error
    cout << vector_search(v, 15) << endl;
    cout << vector_search(v2, 1.51) << endl;
    cout << vector_search(v3, a) << endl;
    return 0;
}
