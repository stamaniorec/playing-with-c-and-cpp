#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

int main()
{
    int number;
    std::cout << "Enter a number, please: ";
    std::cin >> number;

    std::vector<int> factors;
    std::stack<int> factors2;

    for(int i = 1; i <= sqrt(number); ++i)
    {
        if(number % i == 0)
        {
            factors.push_back(i);
            if(i != sqrt(number))
            {
                factors2.push(number / i);
            }
        }
    }

    std::cout << "The factors of " << number <<
        " are: " << std::endl;

    for(int i = 0; i < factors.size(); ++i)
    {
        std::cout << factors[i] << " ";
    }

    while(!factors2.empty())
    {
        std::cout << factors2.top() << " ";
        factors2.pop();
    }

    return 0;
}
