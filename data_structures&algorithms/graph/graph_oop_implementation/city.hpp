#ifndef __CITY__
#define __CITY__

#include "base_vertex.hpp"

class City : public BaseVertex
{
	std::string name_;
	long population_;
public:
	City(std::string name, long population) : name_(name), population_(population) {};
	
	std::string get_name() const { return name_; }
	long get_population() const { return population_; }

	friend std::ostream& operator<<(std::ostream& out, const City &c);
	friend std::ostream& operator<<(std::ostream& out, const City *c);
};

#endif