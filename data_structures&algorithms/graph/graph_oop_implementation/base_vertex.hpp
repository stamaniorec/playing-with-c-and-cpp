#ifndef __BASE_VERTEX__
#define __BASE_VERTEX__

#include <string>

class BaseVertex
{
public:
	virtual ~BaseVertex() {};
	virtual std::string get_name() const = 0;
};

#endif