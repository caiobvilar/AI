#include "base.hpp"

void assign_random(double *m, int rowsm, int colsm,bool binary)
{
	if(binary == false)
	{
		for(int i=0;i < rowsm;i++)
		{
			for(int j=0;j<colsm;j++)
			{
				if(i==j)
				{
					*m++ = 0.0;
				}
				else
				{
					*m++ = DRand(-1,1);
				}
			}
		}
	}
	else
	{
		for(int i=0;i < rowsm;i++)
		{
			for(int j=0;j<colsm;j++)
			{
				*m++ = rand()%2;
			}
		}
	}

}

void show_values(double *m,int rowsm,int colsm)
{
	for(int i=0;i < rowsm;i++)
	{
		for(int j=0;j<colsm;j++)
		{
			std::cout << std::setprecision(3) <<*(m + (i*colsm+j)) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "##################" << std::endl;
}

void add_bias(double *b, double *t, int rowsbt, int colsbt)
{
	for(int i=0;i < rowsbt;i++)
	{
		for(int j=0;j<colsbt;j++)
		{
			*(t + (i*colsbt+j)) =  *(t + (i*colsbt+j)) + *(b + (i*colsbt+j));
		}
	}

}

void multiply_matrices(double *m1, double *m2, double *mout, int rowsm1, int colsm1, int colsm2)
{
	for(int i=0;i<rowsm1;i++)
	{
		for(int j=0;j< colsm1;j++)
		{
			*mout = 0;
			for(int k=0;k < colsm2;k++)
			{
				*mout += (*(m1 + i*colsm2+k))*(*(m2+k*colsm1+j));
			}
			mout++;
		}
	}
}

double DRand(double min, double max)
{
	double ret = (double)rand()/RAND_MAX;
	return (min+(ret*(max-min)));
}



void evaluate_state(double *s,double *t,int rowss,int colss,double *b, int *v)
{
	for(int i=0;i < rowss;i++)
	{
		for(int j=0;j< colss;j++)
		{
			if(*(v + (i*colss+j)) == 0) //checks if unit is visible
			{
				if((tanh(*(t + (i*colss+j)))) > 0)
				{
					*(s + (i*colss+j)) = 1;
				}
				else
				{
					*(s + (i*colss+j)) = 0;
				}
			}
		}
	}
}
