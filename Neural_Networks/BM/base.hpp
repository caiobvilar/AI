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

void initialization(std::vector<Unit> u,double *W,double *L, double J*);
void Clamped_phase(std::vector<Unit> u,std::vector<Training_Pattern> p,double *W,double *L, double J*);
void Freerunning_phase(std::vector<Unit> u,double *W,double *L, double J*);


double DRand(double min,double max)
{
	double ret = (double)rand()/RAND_MAX;
	return min+(ret*(max-min));
}

void initialization(std::vector<Unit> u,double *W,double *L, double J*)
{

}

void Clamped_phase(std::vector<Unit> u,std::vector<Training_Pattern> p,double *W,double *L, double J*)
{

}
void Freerunning_phase(std::vector<Unit> u,double *W,double *L, double J*);
{

}
#endif //_BASE_HPP_
