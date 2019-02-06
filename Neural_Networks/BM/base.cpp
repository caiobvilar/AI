#include "base.hpp"

double DRand(double min,double max)
{
	double ret = (double)rand()/RAND_MAX;
	return min+(ret*(max-min));
}

void initialization(std::vector<Unit> u,double *W,double *L, double J*)
{
	srand(NULL);
	for(static int i=0;i<UNIT_COUNT;i++)
	{
		u.at(i).state = rand() %2;
	}
}

void Clamped_phase(std::vector<Unit> u,std::vector<Training_Pattern> p,double *W,double *L, double J*)
{

}
void Freerunning_phase(std::vector<Unit> u,double *W,double *L, double J*);
{

}
