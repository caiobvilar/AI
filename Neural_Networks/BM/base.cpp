#include "base.hpp"

double DRand(double min,double max)
{
	double ret = (double)rand()/RAND_MAX;
	return min+(ret*(max-min));
}

void set_visible(std::vector<Unit> u)
{
	for(static int i=0;i<VISIBLE_COUNT;i++)
	{
		Unit visible;
		visible.visible = true;
		u.push_back(visible);
	}
}

void initialization(std::vector<Unit> u,double *W,double *L,double *J)
{
	srand(time(0));
	for(static int i=0;i<UNIT_COUNT;i++)
	{
		u.at(i).state = rand() %2;
	}
	for(static int i = 0;i < VISIBLE_COUNT*VISIBLE_COUNT;i++) //initializing visible-visible interaction weights
	{
		*W++ = DRand(-1,1);
	}
	for(static int i = 0;i < VISIBLE_COUNT*HIDDEN_COUNT;i++) //initializing visible-hidden interaction weights
	{
		*L++ = DRand(-1,1);
	}
	for(static int i = 0;i < HIDDEN_COUNT*HIDDEN_COUNT;i++) //initializing hidden-hidden interaction weights
	{
		*J++ = DRand(-1,1);
	}
	
}

void Clamped_phase(std::vector<Unit> u,std::vector<uint8_t> Training_Pattern,double *W,double *L, double *J)
{

}
void Freerunning_phase(std::vector<Unit> u,double *W,double *L, double *J)
{

}

void show_states(std::vector<Unit> u)
{
	std::vector<Unit>::iterator itr_u;
	for(itr_u = u.begin();itr_u != u.end();itr_u++)
	{
		if(!(*itr_u).visible)
		{
			std::cout << "Hidden Unit State: " << (*itr_u).state << std::endl;
		}
		else
		{
			std::cout << "Visible Unit State: " << (*itr_u).state << std::endl;
		}
	}
}

void show_weights(double *W, double *L, double *J)
{
}
