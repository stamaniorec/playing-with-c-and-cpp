#include <iostream>
#include <math.h>

using namespace std;

class Sieve
{
private:
	int n;
	bool array1[100];
public:
	Sieve(int a) : n(a){};
	void init_sieve()
	{
		for(int i = 0; i <= n; i++)
		{
			array1[i] = true;
		}
	}
	void run_sieve()
	{
		array1[0] = array1[1] = false;
		for(int i = 2; i <= sqrt(n); i++)
		{
			if(array1[i])
			{
				for(int j = i + i; j <= n; j += i)
				{
					array1[j] = false;
				}
			}
		}
	}
	void print_sieve()
	{
		for(int i = 0; i <= n; i++)
		{
			if(array1[i])
				cout << i << endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	Sieve sieve(100);
	sieve.init_sieve();
	sieve.run_sieve();
	sieve.print_sieve();
	return 0;
}