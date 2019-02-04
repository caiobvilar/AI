#ifndef _BASE_HPP_
#define _BASE_HPP_

#include <list>

struct Unit
{
	bool visible;
	double bias;
	double std::list<float> weights;
	bool state;
};

struct Net
{
	std::vector<Unit> visible;
	std::vector<Unit> hidden;
	
};

#endif //_BASE_HPP_
