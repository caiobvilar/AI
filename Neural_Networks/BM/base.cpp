#include "base.hpp"

double DRand(double min,double max)
{
	double ret = (double)rand()/RAND_MAX;
	return min+(ret*(max-min));
}

std::vector<Unit> set_visible_hidden(std::vector<Unit> u)
{
	std::cout << "[SYSTEM]: setting [" << VISIBLE_COUNT << "] unit(s) as visible..." << std::endl;
	for(static int i=0;i<VISIBLE_COUNT;i++)
	{
		Unit visible;
		visible.visible = true;
		u.push_back(visible);
	}
	for(static int i=0;i<HIDDEN_COUNT;i++)
	{
		Unit hidden;
		hidden.visible = false;
		u.push_back(hidden);
	}
	return u;
}

std::vector<Unit> initialization(std::vector<Unit> u,double *W,double *L,double *J)
{
	std::cout << "[SYSTEM]: initialization of states and weights." << std::endl;

	srand(time(0));
	std::vector<Unit>::iterator itr_u;
	std::cout << "[SYSTEM]: setting state of [" << u.size() << "] units randomly..." << std::endl;
	for(itr_u = u.begin();itr_u != u.end();itr_u++)
	{
		(*itr_u).state = rand()%2;
	}
	std::cout << "[SYSTEM]: setting [" << VISIBLE_COUNT*VISIBLE_COUNT << "] visible-visible weights randomly..." << std::endl;
	for(static int i = 0;i < VISIBLE_COUNT*VISIBLE_COUNT;i++) //initializing visible-visible interaction weights
	{
		*W++ = DRand(-1,1);
	}
	std::cout << "[SYSTEM]: setting [" << VISIBLE_COUNT*HIDDEN_COUNT << "] visible-hidden weights randomly..." << std::endl;
	for(static int i = 0;i < VISIBLE_COUNT*HIDDEN_COUNT;i++) //initializing visible-hidden interaction weights
	{
		//put condition to set diagonal weights to zero
		*L++ = DRand(-1,1);
	}
	std::cout << "[SYSTEM]: setting [" << HIDDEN_COUNT*HIDDEN_COUNT << "] hidden-hidden weights randomly..." << std::endl;
	for(static int i = 0;i < HIDDEN_COUNT*HIDDEN_COUNT;i++) //initializing hidden-hidden interaction weights
	{
		//put condition to set diagonal weights to zero
		*J++ = DRand(-1,1);
	}
	return u;
}

void Clamped_phase(std::vector<Unit> u,std::vector<uint8_t> Training_Pattern,double *W,double *L, double *J)
{
	std::cout << "[SYSTEM]: starting clamped phase...." << std::endl;

}
void Freerunning_phase(std::vector<Unit> u,double *W,double *L, double *J)
{
	std::cout << "[SYSTEM]: starting Free-Running phase...." << std::endl;

}

void show_states(std::vector<Unit> u)
{
	std::cout << "[SYSTEM]: showing unit states...." << std::endl;
	std::vector<Unit>::iterator itr_u;
	for(itr_u = u.begin();itr_u != u.end();itr_u++)
	{
		if((*itr_u).visible == false)
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
	std::cout << "[SYSTEM]: showing weights...." << std::endl;
	for(static int i=0;i<HIDDEN_COUNT;i++)
	{
		for(static int j=0;j < VISIBLE_COUNT;j++)
		{
			std::cout << 
		}
	}
}



























































