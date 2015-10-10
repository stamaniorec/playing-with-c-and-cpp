#include <iostream>

class Stuff
{
	private:
		int data;
	public: 
		Stuff(int val) : data(val){};
		Stuff operator+(const Stuff &a)
		{
			return Stuff(data + a.data);
		}
		friend std::ostream& operator<<(std::ostream &out, const Stuff &a)
		{
			out << a.data;
			return out;
		}
		// Not needed, I know, I just wanted to practice 
		Stuff& operator=(const Stuff &source)
		{
			if(this != &source)
			{
				data = source.data;				
			}
			return *this;
		}
		Stuff& operator+=(const Stuff &a)
		{
			data += a.data;
			return *this;
		}
		Stuff& operator+=(int a)
		{
			data += a;
			return *this;
		}
};

int main (int argc, char const* argv[])
{
	Stuff s1(5);
	Stuff s2(10);
	Stuff s3 = s1 + s2;
	std::cout << s3 << std::endl;	

	s3 += 500;

	std::cout << s3 << std::endl;

	s3 = s1;
	std::cout << s3 << std::endl;
	return 0;
}
