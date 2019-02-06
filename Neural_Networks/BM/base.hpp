#ifndef _BASE_HPP_
#define _BASE_HPP_
///////////////////////INCLUDES///////////////

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>


///////////////////////BASE DEFINITIONS///////

#define UNIT_COUNT	3	
#define VISIBLE_COUNT 1
#define HIDDEN_COUNT 2

static double W[VISIBLE_COUNT][HIDDEN_COUNT];
static double L[HIDDEN_COUNT][HIDDEN_COUNT];
static double J[VISIBLE_COUNT][VISIBLE_COUNT];


struct Unit			// Units definition structure
{
	bool visible;   // Defines if they're visible units or not.
	uint8_t state;	// Units state
};


void set_visible(std::vector<Unit> u);
void initialization(std::vector<Unit> u,double *W,double *L,double *J);
void Clamped_phase(std::vector<Unit> u,std::vector<uint8_t> Training_Pattern,double *W,double *L, double *J);
void Freerunning_phase(std::vector<Unit> u,double *W,double *L, double *J);
double DRand(double min,double max);
void show_states(std::vector<Unit> u);
void show_weights(double *W, double *L, double *J);

#endif //_BASE_HPP_
