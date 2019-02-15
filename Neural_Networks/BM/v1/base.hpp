#ifndef _BASE_HPP_
#define _BASE_HPP_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define rows1 1
#define rows2 3
#define cols1 3
#define cols2 3

//TODO: implement clamped training phase.
void assign_random(double *m, int rowsm, int colsm,bool binary);
void show_values(double *m,int rowsm,int colsm);
void sum_matrices(double *m1,double *m2, int rowsm12,int colsm12);
void multiply_matrices(double *m1, double *m2, double *mout, int rowsm1, int colsm1, int rowsm2);
double DRand(double min, double max);
double global_energy(double *s, double *b,int *v,int rowss,int colss);
void clamped_phase(double *s,double *t,int rowss,int colss, int *v);
void transpose(double *mat_in,double *mat_out,int rows,int cols);
void add_bias(double *b, double *t, int rowsbt, int colsbt);
void array_copy(double *a,double *b, int rowsab, int colsab);
///////PAPER AND GATE/////////////////////


#endif //_BASE_HPP_
