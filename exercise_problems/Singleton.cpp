#include <iostream>

class Singleton
{
private: 
	int data;

	Singleton()
	{
		data = 5;
	}
	void operator=(const Singleton &s){}
	Singleton(const Singleton &s){}
public: 
	static Singleton& get_instance()
	{
		static Singleton instance;
		return instance;
	}

	void set_data(int value)
	{
		this->data = value;
	}

	void print_data()
	{
		std::cout << data << std::endl;
	}
};	

int main()
{
	Singleton::get_instance().print_data();
	Singleton::get_instance().set_data(500);
	Singleton::get_instance().print_data();
	return 0;
}
