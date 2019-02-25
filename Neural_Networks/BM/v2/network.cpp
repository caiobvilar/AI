#include "base2.hpp"
//TODO: implement Network::setNeighbours()

int Unit::getId()
{
	return this->id;
}

void Unit::setId(int ids)
{
	this->id = ids;
}

int Unit::getState()
{
	return this->state;
}

void Unit::setState(int s)
{
	this->state = s;
}

double Unit::energyGap()
{
	double ret = 0.0;
	return ret;
}

void Unit::setNeighbour(int n_id,double weight)
{
	std::map<int, double> aux_map;
	aux_map.insert(std::pair<int,double>(n_id,weight));
	this->neighbours.push_back(aux_map);
}

void Unit::setVisibility(bool v)
{
	this->visible = v;
}

void Unit::showNeighbours()
{
		std::cout << "Neighbour Count: " << this->neighbours.size() << std::endl;
}


Unit::Unit(int state,int id)
{
	this->setState(state);
	this->setId(id);
}
Unit::~Unit()
{
	this->neighbours.clear();
}
/////////////////////////////////////////////////////////////////////////
//Network Constructor
//Arguments:
//@
//Return:
/////////////////////////////////////////////////////////////////////////
Network::Network()
{
}

/////////////////////////////////////////////////////////////////////////
//Network Destructor
//Arguments:
//@
//Return:
/////////////////////////////////////////////////////////////////////////
Network::~Network()
{
}

/////////////////////////////////////////////////////////////////////////
//Network ClampedPhase()
//Arguments:
//@std::vector<int> visible
//Return:
//@void
/////////////////////////////////////////////////////////////////////////
void Network::ClampedPhase(std::vector<int> visible)
{
}
/////////////////////////////////////////////////////////////////////////
//Network ClampedPhase()
//Arguments:
//@std::vector<int> visible
//Return:
//@void
/////////////////////////////////////////////////////////////////////////
void Network::FreeRunningPhase()
{
}
/////////////////////////////////////////////////////////////////////////
//Network InsertUnit()
//Arguments:
//@state
//@id
//Return:
//@void
/////////////////////////////////////////////////////////////////////////
void Network::InsertUnit(int state,int id)
{
	Unit u_aux(state,id);
	this->units.push_back(u_aux);
}
/////////////////////////////////////////////////////////////////////////
//Network ClampedPhase()
//Arguments:
//@std::vector<int> visible
//Return:
//@void
/////////////////////////////////////////////////////////////////////////
void Network::RandomInit(int unit_count)
{
	for(int i=0;i < unit_count;i++)
	{
		this->InsertUnit(rand()%2,i);
	}
}

void Network::ShowUnits()
{
	
	std::vector<Unit>::iterator itr_units;
	for(itr_units = this->units.begin();itr_units != this->units.end();itr_units++)
	{
		std::cout << "Unit ID: " <<(*itr_units).getId() << " | Unit State: " << (*itr_units).getState() << std::endl;
		(*itr_units).showNeighbours();
	}
}
double Network::DRand(double min, double max)
{
	double ret = (double)rand()/RAND_MAX;
	return (min+(ret*(max-min)));
}
void Network::setNeighbours()
{
	//
	
}

