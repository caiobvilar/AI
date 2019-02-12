#ifndef _BASE2_HPP_
#define _BASE2_HPP_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

class Unit
{
	private:

		int id;
		int state;
		bool visible;
		std::vector<std::map<int,double>> neighbours;

	public:

		void setId(int ids);
		int getId();
		int getState();
		void setState(int s);
		double energyGap();
		void setNeighbour(int n_id,double weight);
		void setVisibility(bool v);
		void showNeighbours();
		Unit(int state,int id);
		~Unit();
};

class Network
{
	private:
		std::vector<Unit> units;
	public:
		Network();
		~Network();
		void ClampedPhase(std::vector<int> visible);
		void setNeighbours();
		void FreeRunningPhase();
		void InsertUnit(int state,int id);
		void RandomInit(int unit_count);
		void ShowUnits();
		double DRand(double min, double max);
};




#endif //_BASE2_HPP_

//TODO:
// + Random initialziation of weights and states
// + Direct definition of weghts or states
// + Global Energy calculation
// + Energy gap calculation of each unit
// + Clamped Phase training
// + Free-Running Phase training
