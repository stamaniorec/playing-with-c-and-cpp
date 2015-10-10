#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
void selection_sort(vector<T> &v)
{
    int min_index = 0;
    for(int j = 0; j < v.size(); j++ )
    {
        min_index = j;
        for(int i = j; i < v.size(); i++)
        {
            if(v[min_index] > v[i])
            {
                min_index = i;
            }
        }
        swap(v[j], v[min_index]);
    }
}

template <class T>
void print_vector(vector<T> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(341);
    v.push_back(12);
    selection_sort(v);
    vector<double> v2;
    v2.push_back(12.31);
    v2.push_back(12.30);
    v2.push_back(12.32);
    selection_sort(v2);
    vector<string> v3;
    v3.push_back("Joe");
    v3.push_back("Henry");
    v3.push_back("Sarah");
    v3.push_back("Anna");
    selection_sort(v3);
    print_vector(v);
    print_vector(v2);
    print_vector(v3);
    return 0;
}
