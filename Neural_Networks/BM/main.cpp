////////////////////////////////////////////////////////////////////////////
//
//Author: Caio J. B. V. Guimaraes
//E-mail: caio.b.vilar@gmail.com
//License: GLPv3.0
//
//
////////////////////////////////////////////////////////////////////////////


#include "base.hpp"

double W[VISIBLE_COUNT][HIDDEN_COUNT]; //
double L[HIDDEN_COUNT][HIDDEN_COUNT]; 	// Diagonal weights set to zero
double J[VISIBLE_COUNT][VISIBLE_COUNT];// Diagonal weights set to zero
int main(int argc, char *argv[])
{
	std::vector<Unit> units;
	units = set_visible_hidden(units);
  units = initialization(units,W[0],L[0],J[0]);
	std::cout << "There are: " << units.size() << " units." << std::endl; 
	show_states(units);
	show_weights(W[0],L[0],J[0]);
	return 0;
}


