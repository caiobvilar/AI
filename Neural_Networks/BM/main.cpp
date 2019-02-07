////////////////////////////////////////////////////////////////////////////
//
//Author: Caio J. B. V. Guimaraes
//E-mail: caio.b.vilar@gmail.com
//License: GLPv3.0
//
//
////////////////////////////////////////////////////////////////////////////


#include "base.hpp"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		std::cout << "USAGE: ./main VISIBLE_COUNT HIDDEN_COUNT" << std::endl;
		return 0;
	}
	int visible_count= atoi(argv[1]),hidden_count = atoi(argv[2]);
	double W[visible_count][hidden_count]; 		//
	double L[visible_count][visible_count]; 	// Diagonal weights set to zero
	double J[hidden_count][hidden_count];			// Diagonal weights set to zero

	std::vector<Unit> units;

	units = set_visible_hidden(units,visible_count,hidden_count);
	units = initialization(units,W[0],L[0],J[0],visible_count,hidden_count);

	std::cout << "There are: " << units.size() << " units." << std::endl; 

	show_states(units);
	show_weights(W[0],L[0],J[0],visible_count,hidden_count);

	return 0;
}


