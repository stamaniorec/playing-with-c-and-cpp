#include <iostream>
#include <stack>

void push_to_bottom(std::stack<int> &s, int value)
{
	if(s.empty())
	{
		s.push(value);
		return;
	}
	int top = s.top();
	s.pop();
	push_to_bottom(s, value);
	s.push(top);
}

void reverse(std::stack<int> &s)
{
	if(s.empty())
		return;

	int top = s.top();
	s.pop();
	reverse(s);
	push_to_bottom(s, top);	
}

int main(int argc, char const *argv[])
{
	std::stack<int> s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	push_to_bottom(s, 6);
	push_to_bottom(s, 7);

	reverse(s);

	while(!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}

	return 0;
}