#include <iostream>

class structure
{
	private:
		int info1;
		int info2;
	public:
		int get_info1()
		{
			return info1;
		}

		int get_info2()
		{
			return info2;
		}
			
		void set_info1(int n)
		{
			info1 = n;
		}

		void set_info2(int n)
		{
			info2 = n;
		}
		
		structure(int a, int b)
		{
			set_info1(a);
			set_info2(b);
		}
};

void print_class(structure object)
{
	std::cout << object.get_info1() << std::endl;
	std::cout << object.get_info2() << std::endl;
}

int main (int argc, char const *argv[])
{
	structure my_object(10, 20);
	print_class(my_object);
	structure second_object(30,40);
	print_class(second_object);
	return 0;
}
