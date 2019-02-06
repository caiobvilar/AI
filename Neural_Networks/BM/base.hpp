#ifndef _BASE_HPP_
#define _BASE_HPP_
///////////////////////INCLUDES///////////////

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#define UNIT_COUNT	3	

///////////////////////BASE DEFINITIONS///////

static double W[UNIT_COUNT][UNIT_COUNT];
static double J[UNIT_COUNT][UNIT_COUNT];
static double L[UNIT_COUNT][UNIT_COUNT];

struct Unit			// Units definition structure
{
	bool visible;   // Defines if they're visible units or not.
	uint8_t state;	// Units state
};


double DRand(double min,double max)
{
	double ret = (double)rand()/RAND_MAX;
	return min+(ret*(max-min));
}


#endif //_BASE_HPP_
