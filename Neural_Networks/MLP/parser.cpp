#include "parser.hpp"

std::vector<dataset> parseinputs(const char *inputs_filename, const char *desired_filename)
	//std::vector<dataset> parseinputs(const char *inputs_filename)
{
	std::vector<std::string> inputs_file_data; 		//vector to temporarily store each line of the inputs_file
	std::vector<std::string> desired_file_data;  	//vector to temporarily store each line of the desired_file
	std::ifstream inputs_file(inputs_filename);
	std::ifstream desired_file(desired_filename);
	std::string input_string;
	std::string desired_string;
	std::size_t start=0,end=0;
	while(inputs_file.good() && desired_file.good())
	{
		getline(inputs_file, input_string,'\n');
		getline(desired_file, desired_string,'\n');
		inputs_file_data.push_back(input_string);
		desired_file_data.push_back(desired_string);
	}
	/*
		 while(inputs_file.good())
		 {
		 getline(inputs_file, input_string,'\n');
		 inputs_file_data.push_back(input_string);
		 }
	*/
	std::vector<dataset> data_samples;
	dataset aux_dataset;
	//parse data to feed input matrices [samples and desired outputs]
	std::vector<std::string>AccelX; //Column corresponding to acceleration in the X axis
	std::vector<std::string>AccelY; //Column corresponding to acceleration in the Y axis
	std::vector<std::string>AccelZ; //Column corresponding to acceleration in the Z axis
	std::vector<std::string>VelX;
	std::vector<std::string>VelY;
	std::vector<std::string>VelZ;
	std::vector<std::string>D0; 		
	std::vector<std::string>D1; 		
	std::vector<std::string>D2; 		

	std::vector<std::string>::iterator itr_input_vector;
	std::vector<std::string>::iterator itr_desired_vector;
	std::vector<std::string>::iterator itr_AccelX;
	std::vector<std::string>::iterator itr_AccelY;
	std::vector<std::string>::iterator itr_AccelZ;
	std::vector<std::string>::iterator itr_VelX;
	std::vector<std::string>::iterator itr_VelY;
	std::vector<std::string>::iterator itr_VelZ;
	std::vector<std::string>::iterator itr_D0;
	std::vector<std::string>::iterator itr_D1;
	std::vector<std::string>::iterator itr_D2;

	 for(itr_input_vector = inputs_file_data.begin(),	itr_desired_vector = desired_file_data.begin();
	 itr_input_vector != inputs_file_data.end(),itr_desired_vector != desired_file_data.end();
	 itr_input_vector++,	itr_desired_vector++)
	{
		//INPUTS FILE PROCESSING
		end = (*itr_input_vector).find(SEPARATOR,start);
		AccelX.push_back((*itr_input_vector).substr(start,end));
		(*itr_input_vector).erase(start,end+1);

		end = (*itr_input_vector).find(SEPARATOR,start);
		AccelY.push_back((*itr_input_vector).substr(start,end));
		(*itr_input_vector).erase(start,end+1);

		end = (*itr_input_vector).find(SEPARATOR,start);
		AccelZ.push_back((*itr_input_vector).substr(start,end));
		(*itr_input_vector).erase(start,end+1);

		end = (*itr_input_vector).find(SEPARATOR,start);
		VelX.push_back((*itr_input_vector).substr(start,end));
		(*itr_input_vector).erase(start,end+1);

		end = (*itr_input_vector).find(SEPARATOR,start);
		VelY.push_back((*itr_input_vector).substr(start,end));
		(*itr_input_vector).erase(start,end+1);

		end = (*itr_input_vector).find(SEPARATOR,start);
		VelZ.push_back((*itr_input_vector).substr(start,end));
		(*itr_input_vector).erase(start,end+1);

		//DESIRED OUTPUTS FILE PROCESSING

		end = (*itr_desired_vector).find(SEPARATOR,start);
		D0.push_back((*itr_desired_vector).substr(start,end));
		(*itr_desired_vector).erase(start,end+1);
		end = (*itr_desired_vector).find(SEPARATOR,start);

		D1.push_back((*itr_desired_vector).substr(start,end));
		(*itr_desired_vector).erase(start,end+1);
		end = (*itr_desired_vector).find(SEPARATOR,start);

		D2.push_back((*itr_desired_vector).substr(start,end));
		(*itr_desired_vector).erase(start,end+1);
		end = (*itr_desired_vector).find(SEPARATOR,start);
	}
	for(itr_AccelX = AccelX.begin(),
			itr_AccelY = AccelY.begin(),
			itr_AccelZ = AccelZ.begin(),
			itr_VelX = VelX.begin(),
			itr_VelY = VelY.begin(),
			itr_VelZ = VelZ.begin(),
			itr_D0 = D0.begin(),
			itr_D1 = D1.begin(),
			itr_D2 = D2.begin();
			itr_AccelX != AccelX.end(),
			itr_AccelY != AccelY.end(),
			itr_AccelZ != AccelZ.end(),
			itr_VelX != VelX.end(),
			itr_VelY != VelY.end(),
			itr_VelZ != VelZ.end(),
			itr_D0 != D0.end(),
			itr_D1 != D1.end(),
			itr_D2 != D2.end();
			itr_AccelX++,
			itr_AccelY++,
			itr_AccelZ++,
			itr_VelX++,
			itr_VelY++,
			itr_VelZ++,
			itr_D0++,
			itr_D1++,
			itr_D2++)
	{
		aux_dataset.X0 = std::stof((*itr_AccelX));
		aux_dataset.X1 = std::stof((*itr_AccelY));
		aux_dataset.X2 = std::stof((*itr_AccelZ));
		aux_dataset.X3 = std::stof((*itr_VelX));
		aux_dataset.X4 = std::stof((*itr_VelY));
		aux_dataset.X5 = std::stof((*itr_VelZ));
		aux_dataset.D0 = std::stof((*itr_D0));
		aux_dataset.D1 = std::stof((*itr_D1));
		aux_dataset.D2 = std::stof((*itr_D2));
		data_samples.push_back(aux_dataset);
	}
	return data_samples;
}
