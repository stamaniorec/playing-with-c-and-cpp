#include <iostream>

class Class
{
	private:
		int var1;
		int var2;
	public:
		void print_var1()
		{
			std::cout << var1 << std::endl;
		}
		void print_var2()
		{
			std::cout << var2 << std::endl;
		}
		Class(int parameter1, int parameter2) :
			var1(parameter1), var2(parameter2) {}
};

int main()
{
	Class my_object(10, 20);
	my_object.print_var1();
	my_object.print_var2();
	return 0;
}
