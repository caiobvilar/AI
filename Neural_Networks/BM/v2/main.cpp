#include "base2.hpp"



#define UNIT_COUNT 3



int main(int argc, char *argv[])
{
	Network *net = new Network();
	std::cout << "Random Initialization:" << std::endl;
	net->RandomInit(UNIT_COUNT);
	net->ShowUnits();
	std::cout << "Setting Neighbours:" << std::endl;
	net->setNeighbours();
	return 0;
}
