#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct Hidden			//Hidden units
{
	std::vector<double> hh_weights; //hidden-hidden interaction weights
	std::vector<double> hv_weights; //hidden-visible interaction weights
	uint8_t state;									//Hidden units state
};

struct Visible		//Visible units
{
	std::vector<double> vv_weights; //visible-visible interaction weights
	std::vector<double> vh_weights; //visible-hidden interaction weights
	uint8_t state;									//visible unit states
};

double DRand(double min,double max)
{
	double ret = (double)rand()/RAND_MAX;
	return min+(ret*(max-min));
}

void start_weights(std::vector<Hidden> h, std::vector<Visible> v);

const int node_count = 3;

const AND_States[4][4];

int main(int argc, char *argv[])
{
	std::vector<Hidden> hidden_units;
	std::vector<Visible> visible_units;
	
	std::vector<Hidden>::iterator hidden_units_itr;
	std::vector<Visible>::iterator visible_units_itr;

	
	return 0;
}


void start_weights(std::vector<Hidden> h, std::vector<Visible> v)
{
	std::vector<double>::iterator weight_itr;
	for(hidden_units_itr = h.begin();hidden_units_itr != h.end();hidden_units_itr++)
	{
		for(weight_itr = (*hidden_units_itr).begin();
				weight_itr != (*hidden_units_itr).end();
				weight_itr++)
		{

		}
	}
}
