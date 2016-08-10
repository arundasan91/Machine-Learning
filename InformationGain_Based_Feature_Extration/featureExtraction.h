#ifndef FEATUREEXTRACTION_H
#define FEATUREEXTRACTION_H
#include "dataset.h"
#include <algorithm>
#include <math.h>

class featureExtraction
{
public:
	//Default constructor
	featureExtraction();

	//First, find the probability of each attributes in each features.
	std::vector<std::vector<double> > findProbVecofVec(std::vector<std::vector<double> >, std::vector<std::vector<int> >, double);
	//Second, find the entropy of each of them.
	void findEntropy_dataset(std::vector<std::vector<std::string> >);
	//Third, find the Information Gain the features can provide.
	void findInformationGain();
	//Fourth, extract the best features and write them in a seperate file.
	void extractFeatures(std::vector<std::vector<std::string> >);
	
	//Function prototype of setEntropy
	void setEntropy(std::vector<double>);
	//Function prototype of getEntropy
	std::vector<double> getEntropy();
	//Function prototype of setIG
	void setIG(std::vector<double>);
	//Function prototype of getIG
	std::vector<double> getIG();
	//Function prototype of setNumFeatures
	void setNumFeatures(int);
	//Function prototype of setMaxAttrib
	void setMaxAttrib(double);
	//Function prototype of getNumFeatures
	int getNumFeatures();
	//Function prototype of getMaxAttrib
	double getMaxAttrib();
private:
	std::vector<double> entropy;
	std::vector<double> IG;
	int numFeatures;
	double maxAttrib;
};
#endif
