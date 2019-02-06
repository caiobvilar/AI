#ifndef _BASE_HPP_
#define _BASE_HPP_
///////////////////////INCLUDES///////////////

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>


///////////////////////BASE DEFINITIONS///////

#define UNIT_COUNT	4	
#define VISIBLE_COUNT 2
#define HIDDEN_COUNT 2



struct Unit			// Units definition structure
{
	bool visible;   // Defines if they're visible units or not.
	int state;	// Units state
};


std::vector<Unit> set_visible_hidden(std::vector<Unit> u);
std::vector<Unit> initialization(std::vector<Unit> u,double *w,double *l,double *j);
void Clamped_phase(std::vector<Unit> u,std::vector<uint8_t> Training_Pattern,double *w,double *l, double *j);
void Freerunning_phase(std::vector<Unit> u,double *w,double *l, double *j);
double DRand(double min,double max);
void show_states(std::vector<Unit> u);
void show_weights(double *w, double *l, double *j);

#endif //_BASE_HPP_
