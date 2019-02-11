#include "base2.hpp"



#define UNIT_COUNT 15



int main(int argc, char *argv[])
{
	Network *net = new Network();
	net->RandomInit(UNIT_COUNT);
	net->ShowUnits();
	return 0;
}
