#include <iostream>

class my_class
{
	private:
		int a;
		int b;
	public:
		my_class(int parameter1, int parameter2);
		void get_a()
		{
			std::cout << a << std::endl;
		}
		void get_b()
		{
			std::cout << b << std::endl;
		}
};

my_class::my_class(int parameter1, int parameter2)
{
	my_class::a = parameter1;
	my_class::b = parameter2;
}

int main()
{
	my_class variable(10, 20);
	variable.get_a();
	variable.get_b();
	return 0;
}
