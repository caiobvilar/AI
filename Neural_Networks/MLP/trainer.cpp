//@Authors: Caio Jose Borba Vilar Guimaraes caio.b.vilar@gmail.com
//					Sergio Natan Silva s.natansilva@gmail.com
//@Description: mlp backpropagation trainer
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include "parser.hpp"
#include  <cmath>

#define MIN_ARGS 3
#define HIDDENSIZE 6
#define OUTPUTSIZE 3
struct neuron_in
{
	double W0 = 0.0;
	double W1 = 0.0;
	double W2 = 0.0;
	double W3 = 0.0;
	double W4 = 0.0;
	double W5 = 0.0;
	double lif = 0.0;
	double atf = 0.0;
	double error = 0.0;
	double lgradient = 0.0;
};
struct neuron_out
{
	double W0 = 0.0;
	double W1 = 0.0;
	double W2 = 0.0;
	double lif = 0.0;
	double atf = 0.0;
	double error = 0.0;
	double lgradient = 0.0;
};
double randomize()
{
	return ((double)rand()/(double)RAND_MAX);
}

double activf(double z)
{
	return (1.0/(1.0 + exp(-z)));
}

double sigmadot(double y)
{
	return (activf(y)*(1-activf(y)));
}










int main(int argc, char *argv[])
{
	srand(time(NULL));
	if(argc != MIN_ARGS)
	{
		//std::cout << "Usage: ./trainer input_filename desired_filename hidden_neurons output_neurons eta alpha MSE max_iterations" << std::endl;
		std::cout << "ARGC: " << argc << std::endl;
		return 0;
	}
	double alpha = 0.0001;
	double eta = 0.7;
	double MSE = 0.001;
	double MSEerror = 1.0;
	double max_iterations = 1000;

	std::vector<dataset> data_samples = parseinputs(argv[1],argv[2]);
	std::vector<dataset>::iterator itr_datasamples;
	//generate random weights
	std::vector<neuron_in> neuronshidd;
	std::vector<neuron_in> neuronshidd_old;
	std::vector<neuron_out> neuronsout;
	std::vector<neuron_out> neuronsout_old;
	std::vector<neuron_in>::iterator itr_neuronshidd;
	std::vector<neuron_in>::iterator itr_neuronshidd_old;
	std::vector<neuron_out>::iterator itr_neuronsout;
	std::vector<neuron_out>::iterator itr_neuronsout_old;
	neuron_in aux_neuronhidd;
	neuron_out aux_neuronout;

	for(int i=0; i < HIDDENSIZE;i++)
	{
		aux_neuronhidd.W0 = randomize(); 
		aux_neuronhidd.W1 = randomize(); 
		aux_neuronhidd.W2 = randomize(); 
		aux_neuronhidd.W3 = randomize(); 
		aux_neuronhidd.W4 = randomize(); 
		aux_neuronhidd.W5 = randomize(); 
		neuronshidd.push_back(aux_neuronhidd);
	}

	for(int i=0; i < OUTPUTSIZE;i++)
	{
		aux_neuronout.W0 = randomize(); 
		aux_neuronout.W1 = randomize(); 
		aux_neuronout.W2 = randomize(); 
		neuronsout.push_back(aux_neuronout);
	}

	for(itr_neuronsout = neuronsout.begin();itr_neuronsout != neuronsout.end();itr_neuronsout++)
	{
		neuronsout_old.push_back((*itr_neuronsout));		
	}
	for(itr_neuronshidd = neuronshidd.begin();itr_neuronshidd != neuronshidd.end();itr_neuronshidd++)
	{
		neuronshidd_old.push_back((*itr_neuronshidd));		
	}





	//loop itself
	for(int i = 0;i < max_iterations;i++)
	{
		std::random_shuffle(data_samples.begin(),data_samples.end());

		for(itr_datasamples = data_samples.begin();itr_datasamples != data_samples.end();itr_datasamples++)
		{
			for(itr_neuronshidd = neuronshidd.begin();itr_neuronshidd != neuronshidd.end();itr_neuronshidd++)
			{
				(*itr_neuronshidd).lif +=	(*itr_datasamples).X0 * (*itr_neuronshidd).W0;
				(*itr_neuronshidd).lif +=	(*itr_datasamples).X1 * (*itr_neuronshidd).W1;
				(*itr_neuronshidd).lif +=	(*itr_datasamples).X2 * (*itr_neuronshidd).W2;
				(*itr_neuronshidd).lif +=	(*itr_datasamples).X3 * (*itr_neuronshidd).W3;
				(*itr_neuronshidd).lif +=	(*itr_datasamples).X4 * (*itr_neuronshidd).W4;
				(*itr_neuronshidd).lif +=	(*itr_datasamples).X5 * (*itr_neuronshidd).W5;
				(*itr_neuronshidd).atf = activf((*itr_neuronshidd).lif);
			}
			for(itr_neuronshidd = neuronshidd.begin();itr_neuronshidd != neuronshidd.end();itr_neuronshidd++)
			{
				for(itr_neuronsout = neuronsout.begin();itr_neuronsout != neuronsout.end();itr_neuronsout++)
				{
					(*itr_neuronsout).lif += (*itr_neuronshidd).atf * (*itr_neuronsout).W0;
					(*itr_neuronsout).lif += (*itr_neuronshidd).atf * (*itr_neuronsout).W1;
					(*itr_neuronsout).lif += (*itr_neuronshidd).atf * (*itr_neuronsout).W2;
					(*itr_neuronsout).atf = activf((*itr_neuronsout).lif);
				}
			}
			neuronsout[0].error = pow(((*itr_datasamples).D0 - neuronsout[0].atf),2)/2;	
			neuronsout[1].error = pow(((*itr_datasamples).D1 - neuronsout[1].atf),2)/2;	
			neuronsout[2].error = pow(((*itr_datasamples).D2 - neuronsout[2].atf),2)/2;

			MSEerror = neuronsout[0].error;
			MSEerror += neuronsout[1].error;
			MSEerror += neuronsout[2].error;
			if(MSEerror <= MSE)
			{
				std::cout << "GOT ERROR CAP." << std::endl;
				break;
			}
			//calculate local gradient sigma'(vj(n)) of output neurons
			for(itr_neuronsout = neuronsout.begin();itr_neuronsout != neuronsout.end();itr_neuronsout++)
			{
				(*itr_neuronsout).lgradient = (sigmadot((*itr_neuronsout).lif)*(*itr_neuronsout).error);
			}

			for(itr_neuronsout = neuronsout.begin();itr_neuronsout != neuronsout.end();itr_neuronsout++)
			{
				if(itr_neuronsout == neuronsout.begin())
				{
					(*itr_neuronsout).W0 += (eta*(*itr_neuronsout).lgradient * (*itr_neuronsout).atf);
					(*itr_neuronsout).W1 += (eta*(*itr_neuronsout).lgradient * (*itr_neuronsout).atf);
					(*itr_neuronsout).W2 += (eta*(*itr_neuronsout).lgradient * (*itr_neuronsout).atf);

				}
				else
				{
					(*itr_neuronsout).W0 += (eta*(*itr_neuronsout).lgradient * (*itr_neuronsout).atf) + (alpha * (*std::prev(itr_neuronsout,1)).W0);
					(*itr_neuronsout).W1 += (eta*(*itr_neuronsout).lgradient * (*itr_neuronsout).atf) + (alpha * (*std::prev(itr_neuronsout,1)).W1);
					(*itr_neuronsout).W2 += (eta*(*itr_neuronsout).lgradient * (*itr_neuronsout).atf) + (alpha * (*std::prev(itr_neuronsout,1)).W2);
				}
			}
			for(itr_neuronshidd = neuronshidd.begin();itr_neuronshidd != neuronshidd.end();itr_neuronshidd++)
			{
				(*itr_neuronshidd).lgradient = sigmadot((*itr_neuronshidd).lif) * (neuronsout[0].lgradient * (*itr_neuronshidd).W0);
				(*itr_neuronshidd).lgradient += sigmadot((*itr_neuronshidd).lif) * (neuronsout[1].lgradient * (*itr_neuronshidd).W1);
				(*itr_neuronshidd).lgradient += sigmadot((*itr_neuronshidd).lif) * (neuronsout[2].lgradient * (*itr_neuronshidd).W2);
			}
			for(itr_neuronshidd = neuronshidd.begin();itr_neuronshidd != neuronshidd.end();itr_neuronshidd++)
			{
				if(itr_neuronshidd == neuronshidd.begin())
				{
					(*itr_neuronshidd).W0 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf);
					(*itr_neuronshidd).W1 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf);
					(*itr_neuronshidd).W2 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf);
					(*itr_neuronshidd).W3 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf);
					(*itr_neuronshidd).W4 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf);
					(*itr_neuronshidd).W5 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf);

				}
				else
				{
					(*itr_neuronshidd).W0 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf) + (alpha * (*std::prev(itr_neuronshidd,1)).W0);
					(*itr_neuronshidd).W1 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf) + (alpha * (*std::prev(itr_neuronshidd,1)).W1);
					(*itr_neuronshidd).W2 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf) + (alpha * (*std::prev(itr_neuronshidd,1)).W2);
					(*itr_neuronshidd).W3 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf) + (alpha * (*std::prev(itr_neuronshidd,1)).W3);
					(*itr_neuronshidd).W4 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf) + (alpha * (*std::prev(itr_neuronshidd,1)).W4);
					(*itr_neuronshidd).W5 += (eta*(*itr_neuronshidd).lgradient * (*itr_neuronshidd).atf) + (alpha * (*std::prev(itr_neuronshidd,1)).W5);
				}
			}
		}
	}
	std::cout << "OUTPUT NEURONS " << std::endl;
	for(itr_neuronsout = neuronsout.begin(),
			itr_neuronsout_old = neuronsout_old.begin();
			itr_neuronsout != neuronsout.end(),
			itr_neuronsout_old != neuronsout_old.end();
			itr_neuronsout++,
			itr_neuronsout_old++)
	{
		std::cout << "OLDW0: " << (*itr_neuronsout_old).W0 << " | NEWW0: " << (*itr_neuronsout).W0 << std::endl;
		std::cout << "OLDW1: " << (*itr_neuronsout_old).W1 << " | NEWW1: " << (*itr_neuronsout).W1 << std::endl;
		std::cout << "OLDW2: " << (*itr_neuronsout_old).W2 << " | NEWW2: " << (*itr_neuronsout).W2 << std::endl;
		std::cout << "\n";
	}
	std::cout << "HIDDEN NEURONS " << std::endl;
	for(itr_neuronshidd = neuronshidd.begin(),
			itr_neuronshidd_old = neuronshidd_old.begin();
			itr_neuronshidd != neuronshidd.end(),
			itr_neuronshidd_old != neuronshidd_old.end();
			itr_neuronshidd++,
			itr_neuronshidd_old++)
	{
		std::cout << "OLDW0: " << (*itr_neuronshidd_old).W0 << " | NEWW0: " << (*itr_neuronshidd).W0 << std::endl;
		std::cout << "OLDW1: " << (*itr_neuronshidd_old).W1 << " | NEWW1: " << (*itr_neuronshidd).W1 << std::endl;
		std::cout << "OLDW2: " << (*itr_neuronshidd_old).W2 << " | NEWW2: " << (*itr_neuronshidd).W2 << std::endl;
		std::cout << "OLDW3: " << (*itr_neuronshidd_old).W3 << " | NEWW3: " << (*itr_neuronshidd).W3 << std::endl;
		std::cout << "OLDW4: " << (*itr_neuronshidd_old).W4 << " | NEWW4: " << (*itr_neuronshidd).W4 << std::endl;
		std::cout << "OLDW5: " << (*itr_neuronshidd_old).W5 << " | NEWW5: " << (*itr_neuronshidd).W5 << std::endl;
		std::cout << "\n";
	}
}
