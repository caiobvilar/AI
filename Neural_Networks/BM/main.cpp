////////////////////////////////////////////////////////////////////////////
//
//Author: Caio J. B. V. Guimaraes
//E-mail: caio.b.vilar@gmail.com
//License: GLPv3.0
//
//
////////////////////////////////////////////////////////////////////////////


//#include "base.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	/*
	std::vector<Unit> Units;
	std::vector<Unit>::iterator ITR_Units;
	*/
	int a[100];
	for(int i=0;i<100;i++)
	{
		a[i] = rand() %2;
	}
	
	for(int i=0;i<100;i++)
	{
		std::cout << "A[" << i << "]: " << a[i] << std::endl;
	}
	return 0;
}


