#include <iostream>
#include "city.hpp"

std::ostream& operator<<(std::ostream& out, const City &c)
{
	out << c.get_name() << " -> " << c.get_population();
	return out;
}

std::ostream& operator<<(std::ostream& out, const City *c)
{
	out << c->get_name() << " -> " << c->get_population();
	return out;
}