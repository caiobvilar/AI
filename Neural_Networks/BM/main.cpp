#include "base.hpp"

// If I have 2 visible units, say A and B, A(0,0) and B(0,1)
int V[1][3] = {1,1,0}; //which means first two units are visible and the last isnt.

double B[rows1][cols1] = {1,1,-2};
double S[rows1][cols1] = {0,1,0};
double W[rows2][cols2] = {{0,-1,2},{-1,0,2},{2,2,0}};
double T[rows1][cols2] = {0,0,0};

int main(int argc, char *argv[])
{
	std::cout << "[Initial States]" << std::endl;
	show_values(S[0],rows1,cols1);
	std::cout << "[Initial Weights]" << std::endl;
	show_values(W[0],rows2,cols2);
	std::cout << "[Finding local field]" << std::endl;
	multiply_matrices(S[0],W[0],T[0],rows1,cols1,cols2);
	show_values(T[0],rows1,cols2);
	std::cout << "[Adding Bias]" << std::endl;
	add_bias(B[0],T[0],rows1,cols1);
	show_values(S[0],rows1,cols1);
	std::cout << "[Evaluating States]" << std::endl;
	evaluate_state(S[0],T[0],rows1,cols1,B[0],V[0]);
	show_values(S[0],rows1,cols1);
	return 0;
}

