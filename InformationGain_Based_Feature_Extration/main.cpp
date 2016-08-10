#include "dataset.h"
#include "datamanip.h"
#include "featureExtraction.h"

using namespace std;

int main()
{
	//Declare various variables.
	string filename;							//Declare filename as string type.
	vector<double> entropy;						//Declare entropy as a vector of double type.
	vector<double> IG;							//Declare IG as a vector of double type which will store the information gain.
	int maxAttrib;								//Declare the maximum number of attributes in any feature as int type.
	vector<vector<string> > data;				//Declare the dataset as a vector of vectors of string type.
	vector<vector < double > > probAttrib;		//Declare the probability of each attribute as a vector of vectors of double type.
	//Instantiate the classes and make objects.
	Dataset dataset(" ");
	featureExtraction featEx;
	
	//Ask user to enter the filename.
	cout << "Enter the dataset filename: ";
	cin >> filename;
	//filename = "monk-3-tab.txt";			//Uncomment to specify a filename if required.
	//filename = "iris.txt";				//Uncomment to specify a filename if required.
	
	//Load the Dataset
	dataset.setFilename(filename);			//Set the filename.
	data = dataset.loadDataset();			//Load the dataset.
	
	//Start Feature Extraction
	featEx.findEntropy_dataset(data);		//Find the entropy of the features.
	featEx.findInformationGain();			//Find the information gain of the features.
	featEx.extractFeatures(data);			//Do feature extraction and populate result, write dataset to file.
	
	system("pause");						//Pause the output window, wait for a key press and Exit.
	return 0;
}

