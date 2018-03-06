#ifndef _PARSER_HPP
#define _PARSER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define SEPARATOR ","

struct dataset
{
	float X0;
	float X1;
	float X2;
	float X3;
	float X4;
	float X5;
	float D0;
	float D1;
	float D2;
};

std::vector<dataset> parseinputs(const char *input_filename, const char *desired_filename);
//std::vector<dataset> parseinputs(const char *inputs_filename);

#endif //_PARSER_HPP
