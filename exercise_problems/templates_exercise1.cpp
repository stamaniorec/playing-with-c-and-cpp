#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
T sum(vector<T> v)
{
    T sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}
template <>
string sum(vector<string> v)
{
    string sum = "";
    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    vector<float> v2;
    v2.push_back(1.55);
    v2.push_back(2.84);
    v2.push_back(3.25);
    v2.push_back(1023.4912);
    vector<string> v3;
    v3.push_back("Hello ");
    v3.push_back("World");
    v3.push_back("!");
    cout << sum(v3) << endl;
    return 0;
}
