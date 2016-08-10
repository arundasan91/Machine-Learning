#ifndef DATASET_H
#define DATASET_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Dataset
{
public:
	Dataset(const std::string &);			//default constructor
	std::vector<std::vector<std::string> >loadDataset();	//loadDataset function prototype
	void setFilename(const std::string &);					//setFilename function prototype
	std::string getFilename() const;						//getFilename function prototype
private:
	std::string filename;					//initialize private member filename
};


#endif
