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


const int node_count = 3;

const AND_States[4][4];

int main(int argc, char *argv[])
{
	

	
	return 0;
}
