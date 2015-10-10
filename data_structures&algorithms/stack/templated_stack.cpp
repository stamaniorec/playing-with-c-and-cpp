#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack
{
private:
    vector<T> my_stack;
public:
    void push(T value)
    {
        my_stack.push_back(value);
    }

    void pop()
    {
        my_stack.pop_back();
    }

    void print_contents()
    {
        for(int i = 0; i < my_stack.size(); i++)
        {
            cout << my_stack[i] << endl;
        }
    }

    T peek()
    {
        return my_stack.back();
    }

    T greatest()
    {
        T greatest = my_stack.front();
        for(int i = 1; i < my_stack.size(); i++)
        {
            if(greatest < my_stack[i])
            {
                greatest = my_stack[i];
            }
        }
        return greatest;
    }

    virtual double average()
    {
        double average = 0;
        for(int i = 0; i < my_stack.size(); i++)
        {
            average += my_stack[i];
        }
        return average / my_stack.size();
    }
};

// I was experimenting with some stuff...
class String_Stack : public Stack<string>
{
public:

    double average()
    {
        cout << "Cannot get average of strings." << endl;
        return 0.00;
    }
};

int main()
{
    //Stack<string> s;
    String_Stack s;
    s.push("joe");
    s.push("peter");
    s.push("sarah");
    s.print_contents();
    cout << "--- ---" << endl;
    s.pop();
    s.print_contents();
    cout << "--- ---" << endl;
    cout << s.greatest() << endl;
    /*Stack<int> s;
    s.push(1);
    s.push(3);
    s.push(3);*/
    cout << "--- ---" << endl;
    cout << s.average() << endl;
    return 0;
}



