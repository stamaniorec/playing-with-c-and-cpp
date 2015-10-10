#ifndef __EDGE__
#define __EDGE__

#include <iostream>

template<typename T>
class Edge
{
	T* to_;
	long weight_;
public:
	Edge(T* to, long weight) : to_(to), weight_(weight) {};
	T* get_destination() const { return to_; }
	long get_weight() const { return weight_; }

	friend std::ostream& operator<<(std::ostream& out, const Edge& e)
	{
		out << e.get_destination() << " -> " << e.get_weight();
		return out;
	}

	// Needed for std::list remove and find
	bool operator==(const Edge &e)
	{
		return to_ == e.to_ && weight_ == e.weight_;
	}
};

#endif