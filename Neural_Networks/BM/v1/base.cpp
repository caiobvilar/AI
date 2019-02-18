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

void negativate(double *m,int rowsm,int colsm)
{
	for(int i=0;i < rowsm;i++)
	{
		for(int j=0;j<colsm;j++)
		{
			*(m + (i*colsm+j)) = (-1)* *(m + (i*colsm+j));
		}
	}

}
void show_values(double *m,int rowsm,int colsm)
{
	std::cout << "##################" << std::endl;
	for(int i=0;i < rowsm;i++)
	{
		for(int j=0;j<colsm;j++)
		{
			std::cout << std::setprecision(5) << std::fixed << *(m + (i*colsm+j)) << "\t";
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

void subtract_matrices(double *m1, double *m2,double *mout, int rowsbt, int colsbt)
{
	for(int i=0;i < rowsbt;i++)
	{
		for(int j=0;j<colsbt;j++)
		{
			*(mout + (i*colsbt+j)) =  *(m1 + (i*colsbt+j)) - *(m2 + (i*colsbt+j));
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

///////////////////////////BOLTZMANN LEARNING/////////////////////////////////////////////////////
// The BM Learning algorithm is an unsupervised learning algorithm
// The algorithm is trying to build a model of the set of input vectors.
//	-	We want to maximize the productof the probabilities that the BM
//		assigns to the binary vectors in the training set.
//	-	It is also equivalent to maximizing the probability
//		that we would obtain exactly the N training cases
//		if we did the following:
//		-	Let the network settle to its stationary
//			distribution N different times with no external
//			input.
//		-	Sample the visible vector once each time.
//	 @PARAMS:
//	 s: unit states vector
//	 t: local field matrix = s x w + b
//   v: visible unit definition vector
//   @RETURN:
//    There is no return statement. All results and operations are made
//    with pointer to parameters, so they are changed globally
//////////////////////////////////////////////////////////////////////////////////////////////////
void clamped_phase(double *s,double *t,int rowss,int colss, int *v)
{
	//Add a check if any states in the V vector is changed, if the amount
	//of changes is zero, the network reached thermal equilibrium.
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
void transpose(double *mat_in,double *mat_out,int rows,int cols)
{
	for(int i=0;i < rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			*(mat_out + (j*rows+i)) = *(mat_in + (i*cols+j));
		}
	}
}
void global_energy(double *s,double *st,double *bt,int *v,int rowss,int colss,double *w,double *e)
{
	/*
		 double C[rowss][rowss];
		 double D[rowss][rowss];
		 double F[rowss][rowss];
		 double E_aux[rowss][rowss];
	//E_theta(x) = -Bt * X - Xt * W * X
	//multiply Bt by X and store it in C
	//multiply Xt by X store in a rowss x rowss matrix D
	//multiply D by W and store it in F
	//subtract C from F and store it in E.
	//Copy contents from
	multiply_matrices(bt,s,C[0],rowss,1,colss);
	multiply_matrices(s,st,D[0],rowss,colss,colss);
	multiply_matrices(D[0],w,F[0],rowss,colss,colss);
	subtract_matrices();
	array_copy_diag(E_aux[0],e,rowss,rowss);
	*/
}
////////////////////////////////////////////////////////////////////////////////
void array_copy(double *a,double *b, int rowsab, int colsab)
{
	for(int i=0;i < rowsab;i++)
	{
		for(int j=0;j<colsab;j++)
		{
			*(b + (i*colsab+j)) =  *(a + (i*colsab+j));
		}
	}
}
void array_copy_diag(double *a,double *b, int rowsab, int colsab)
{
	for(int i=0;i < rowsab;i++)
	{
		for(int j=0;j<colsab;j++)
		{
			if(i == j)
			{
				*(b + (i*colsab+j)) =  *(a + (i*colsab+j));
			}
		}
	}
}

void calc_prob(double *e,double *ps,int rowse,int colse)
{
	double energy = 0.0;
	for(int i=0;i < rowse;i++)
	{
		for(int j=0;j<colse;j++)
		{
			energy +=  *(e + (i*colse+j));
		}
	}
	energy = exp(energy);
	for(int i=0;i < rowse;i++)
	{
		for(int j=0;j<colse;j++)
		{
			*(ps + (i*colse+j)) = (*(e + (i*colse+j))/energy);
		}
	}
}
