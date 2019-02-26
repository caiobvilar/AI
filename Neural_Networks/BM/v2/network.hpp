#ifndef _NETWORK_HPP_
#define _NETWORK_HPP_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include "unit.hpp"

class Network
{
	private:
		std::vector<Unit> units;
	public:
		double DRand(double min, double max);
		int BRand();
		Learn_pattern();
		Anneal();
		Recall_pattern();
		Adjust_weights();
		Sweep_probe(); //also called propagate.
};




#endif //_NETWORK_HPP_

//TODO:
