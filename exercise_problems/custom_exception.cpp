#include <iostream>

class Exception
{
protected:
	std::string error_message;
public:
	Exception(std::string message) : error_message(message) {};
	std::string get_message()
	{
		return error_message;
	}
};

class XLessThanTenException : public Exception
{
public:
	XLessThanTenException() : Exception("x is less than 10, oh no!"){};
};

int main()
{
	int x = 5;

	try
	{
		if(x < 10)
		{
			// throw(Exception("x is less than 10!!!"));
			throw(XLessThanTenException());
		}
		std::cout << "Everything went fine." << std::endl;
	}
	catch(XLessThanTenException e)
	{
		std::cerr << e.get_message() << std::endl;
	}
	catch(Exception e)
	{
		std::cerr << "Undefined exception!" << std::endl;
	}

	return 0;
}
