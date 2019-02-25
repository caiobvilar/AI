#include "unit.hpp"

int Unit::getID()
{
	return this->id;
}
void Unit::setID(int id_in)
{
	this->id = id_in;
}

int Unit::getState()
{
	return this->state;
}

void Unit::setState(int st)
{
	this->state = st;
}

bool Unit::getVisibility()
{
	return this->visibility;
}
void Unit::setVisibility(bool visible)
{
	this->visibility = visible;
}

void Connection::setConnection(int id1,int id2)
{
	this->unit_1 = id1;
	this->unit_2 = id2;
}

int Connection::getID1()
{
	return this->unit_1;
}

int Connection::getID2()
{
	return this->unit_2;
}

double Connection::getWeight()
{
	return this->weight;
}

void Connection::setWeight(double w)
{
	this->weight = w;
}

