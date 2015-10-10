#include <iostream>
#include "vector.h"

void Vector::expand_vector()
{
	//std::cout << "Expanding." << std::endl;
	int *new_array = new int[size*2];
	for(int i = 0; i < size; i++)
	{
		new_array[i] = array[i];
	}
	size *= 2;
	delete[] array;
	array = new_array;
}

Vector::Vector()
{
	size = 2;
	array = new int[size];
	v_top = 0;		
}

Vector::Vector(int size1, int initial_value)
{
	size = size1;
	array = new int[size];
	v_top = size;
	for(int i = 0; i < size; ++i)
	{
		array[i] = initial_value;
	}
}

Vector::Vector(const Vector &source)
{
	size = source.size;
	array = new int[size];	
	v_top = source.v_top;
	std::cout << v_top << std::endl;		
	for(int i = 0; i < v_top; i++)
	{
		array[i] = source.array[i];
	}
}

void Vector::push_back(int value)
{
	if(v_top >= size - 1)
	{
		expand_vector();
	}			
	array[v_top++] = value;
}

void Vector::pop_back()
{
	array[--v_top] = 0;
}

int Vector::top()
{
	return array[v_top-1];
}

bool Vector::is_empty()
{
	return v_top == 0;
}

void Vector::operator<<(int val)
{
	push_back(val);
	std::cout << "v_top = " << v_top << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Vector &v)
{
	for(int i = 0; i < v.v_top; ++i)
	{
		out << v.array[i] << " ";
	}
	return out;
}

bool Vector::operator!()
{
	return is_empty();	
}

bool Vector::operator==(const Vector &v2)
{
	if(v_top == v2.v_top)
	{
		for(int i = 0; i < v_top; ++i)
		{
			if(array[i] != v2.array[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}	

bool Vector::operator!=(const Vector &v2)
{
	return !(*this == v2);
}	

Vector& Vector::operator=(const Vector &source)
{
	if(this != &source)
	{
		delete[] array;
		array = new int[source.size];
		size = source.size;
		v_top = source.v_top;
		for(int i = 0; i < v_top; ++i)
		{
			array[i] = source.array[i];
		}
	}
	return *this;
}
