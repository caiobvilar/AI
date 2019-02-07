#include "base.hpp"

//////////////////////////////////////FUNCTION DEFINITIONS/////////////////////////////////
double DRand(double min,double max)
{
	double ret = (double)rand()/RAND_MAX;
	return min+(ret*(max-min));
}

std::vector<Unit> set_visible_hidden(std::vector<Unit> u, int visible_count, int hidden_count)
{
	std::cout << "[SYSTEM]: setting [" << visible_count << "] unit(s) as visible..." << std::endl;
	for(int i=0;i<visible_count;i++)
	{
		Unit visible;
		visible.visible = true;
		u.push_back(visible);
	}
	for(int i=0;i<hidden_count;i++)
	{
		Unit hidden;
		hidden.visible = false;
		u.push_back(hidden);
	}
	return u;
}

std::vector<Unit> initialization(std::vector<Unit> u,double *w,double *l,double *j,int visible_count, int hidden_count)
{
	std::cout << "[SYSTEM]: initialization of states and weights." << std::endl;

	std::vector<Unit>::iterator itr_u;
	std::cout << "[SYSTEM]: setting state of [" << u.size() << "] units randomly..." << std::endl;
	for(itr_u = u.begin();itr_u != u.end();itr_u++)
	{
		(*itr_u).state = rand()%2;
	}

	std::cout << "[SYSTEM]: setting [" << visible_count*hidden_count << "] visible-hidden weights randomly..." << std::endl;

	for(int i = 0;i < visible_count;i++) //initializing visible-hidden interaction weights
	{
		for(int k = 0;k < hidden_count;k++)
		{
			*(w+(i*hidden_count+k)) = DRand(-1,1);
		}
	}

	std::cout << "[SYSTEM]: setting [" << visible_count*visible_count << "] visible-visible weights randomly..." << std::endl;

	for(int i = 0;i < visible_count;i++) //initializing visible-visible interaction weights
	{
		for(int k = 0;k < visible_count;k++)
		{
			if(i == k)
			{
				*(l+(i*visible_count+k)) = 0.0;
			}
			else
			{
				*(l+(i*visible_count+k)) = DRand(-1,1);
			}
		}
	}

	std::cout << "[SYSTEM]: setting [" << hidden_count*hidden_count << "] hidden-hidden weights randomly..." << std::endl;

	for(int i = 0;i < hidden_count;i++) //initializing hidden-hidden interaction weights
	{
		for(int k = 0;k < hidden_count;k++)
		{
			if(i == k)
			{
				*(j+(i*hidden_count+k)) = 0.0;
			}
			else
			{
				*(j+(i*hidden_count+k)) = DRand(-1,1);
			}
		}
	}
	return u;
}

void Clamped_phase(std::vector<Unit> u,std::vector<uint8_t> Training_Pattern,double *w,double *l, double *j)
{
	std::cout << "[SYSTEM]: starting clamped phase...." << std::endl;

}
void Freerunning_phase(std::vector<Unit> u,double *w,double *l, double *j)
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

void show_weights(double *w, double *l, double *k,int visible_count,int hidden_count)
{
	std::cout << "Visible-Hidden Weights: " << std::endl;
	for(int i=0;i<visible_count;i++)
	{
		for(int j=0;j<hidden_count;j++)
		{
			std::cout << std::setprecision(3) << *(w + (i*hidden_count+j)) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\nVisible-Visible Weights: " << std::endl;
	for(int i=0;i<visible_count;i++)
	{
		for(int j=0;j<visible_count;j++)
		{
			std::cout << std::setprecision(3) << *(l + (i*visible_count+j)) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\nHidden-Hidden Weights: " << std::endl;
	for(int i=0;i<hidden_count;i++)
	{
		for(int j=0;j<hidden_count;j++)
		{
			std::cout << std::setprecision(3) << *(k + (i*hidden_count+j)) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";
}

