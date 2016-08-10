#include "featureExtraction.h"
#include "datamanip.h"
using namespace std;

//Constructor
featureExtraction::featureExtraction()
	:entropy(10,0), IG(10,0)
{
	//No default constructors for functions
}

//Function definition of setEntropy
void featureExtraction::setEntropy(vector<double> epy)
{
	entropy = epy;
}

//Function definition of getEntropy
vector<double> featureExtraction::getEntropy()
{
	return entropy;
}

//Function definition of setIG
void featureExtraction::setIG(vector<double> infGain)
{
	IG = infGain;
}

//Function definition of getIG
vector<double> featureExtraction::getIG()
{
	return IG;
}

//Function prototype of setNumFeatures
void featureExtraction::setNumFeatures(int numFeat)
{
	numFeatures = numFeat;
}

//Function prototype of setMaxAttrib
void featureExtraction::setMaxAttrib(double maxAtt)
{
	maxAttrib = maxAtt;
}

//Function prototype of getNumFeatures
int featureExtraction::getNumFeatures()
{
	return(numFeatures);
}

//Function prototype of getMaxAttrib
double featureExtraction::getMaxAttrib()
{
	return maxAttrib;
}

//Function definition of findProbVecofVec
vector<vector<double> > featureExtraction::findProbVecofVec(vector<vector<double> > probAttrib, vector<vector<int> > attributeVec, double numEntries)
{
	for (int i = 0; i < attributeVec.size(); i++) {
		for (int j = 0; j < attributeVec[i].size(); j++)
		{
			probAttrib[i][j] = attributeVec[i][j] / numEntries;
		}
	}
	//printVecofVec(probAttrib);
	return(probAttrib);
}

//Function definition of findEntropy_dataset
void featureExtraction::findEntropy_dataset(vector<vector<string> > data)										//Think about some inheritance / Polymorphism for this one !
{
	//Output to screen
	cout << "Finding entropy of the different features in the dataset." << endl;
	
	//DECLARE VARIABLES
	int numFeatures = 0;			//Total number of Features
	double numEntries = 0;			//Total number of entries
	vector <double> col;			//The particular column under test
	numFeatures = data[0].size();	//Update the number of features
	setNumFeatures(numFeatures);	//Set the number of features
	//Uncomment to test whether numFeatures is correct.
	//cout << "numFeatures = " << data[0].size() << endl;

	//Flags to make note of the attributes								//bool flag0[numFeatures] = 0, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;	
	bool* flag0 = new bool[numFeatures]();     // Zero-initialized
	bool* flag1 = new bool[numFeatures]();     // Zero-initialized
	bool* flag2 = new bool[numFeatures]();     // Zero-initialized
	bool* flag3 = new bool[numFeatures]();     // Zero-initialized
	bool* flag4 = new bool[numFeatures]();     // Zero-initialized
	bool* flag5 = new bool[numFeatures]();     // Zero-initialized

	vector <int> numAttrib(numFeatures, 0);			//Number of attributes in the columns

	for (int i = 0; i < data.size(); i++)
	{
		numEntries = data.size();		//Update the number of entries
		for (int j = 0; j < data[i].size(); j++)
		{
			//Iterate through each column and convert string to float.
			if (stof(data[i][numFeatures - j - 1]) == 0 && flag0[numFeatures - j - 1] == 0)
			{
				flag0[numFeatures - j - 1] = 1;
				numAttrib[numFeatures - j - 1] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 1 && flag1[numFeatures - j - 1] == 0)
			{
				flag1[numFeatures - j - 1] = 1;
				numAttrib[numFeatures - j - 1] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 2 && flag2[numFeatures - j - 1] == 0)
			{
				flag2[numFeatures - j - 1] = 1;
				numAttrib[numFeatures - j - 1] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 3 && flag3[numFeatures - j - 1] == 0)
			{
				flag3[numFeatures - j - 1] = 1;
				numAttrib[numFeatures - j - 1] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 4 && flag4[numFeatures - j - 1] == 0)
			{
				flag4[numFeatures - j - 1] = 1;
				numAttrib[numFeatures - j - 1] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 5 && flag5[numFeatures - j - 1] == 0)
			{
				flag5[numFeatures - j - 1] = 1;
				numAttrib[numFeatures - j - 1] += 1;
			}
		}
	}

	//Free up the space allocated for the flag's
	delete[] flag0;
	delete[] flag1;
	delete[] flag2;
	delete[] flag3;
	delete[] flag4;
	delete[] flag5;

	//std::reverse(myvector.begin(),myvector.end()); 
	reverse(numAttrib.begin(), numAttrib.end());

	//Total number of attributes will be numAttrib.size()
	//Uncomment to output the number of attributes in each feature
	/*cout << "Number of Attributes in each feature of the dataset is as follows: " << endl;
	for (int i = 0; i < numFeatures; i++)
	cout << numAttrib[numFeatures - i - 1] << '\t';
	cout << endl;*/

	//Maximum number of attributes in any feature
	double maxAttrib = *max_element(numAttrib.begin(), numAttrib.end());

	//Set the maximum number of attributes
	setMaxAttrib(maxAttrib);

	//Uncomment to output the maximum number of attributes in any feature
	//cout << "The maximum number of attributes in any feature is " << maxAttrib << endl;

	//Limit maximum number of attributes per feature to 5
	if (maxAttrib > 5)
	{
		// Give and error message
		cerr << "Please choose a dataset with less than 5 different attributes in any feature." << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	// Now we'll try to create a 3 by 5 "matrix".
	// First, create a vector with 5 elements
	vector<int> v2(5, 99);

	// Now create a vector of 3 elements. 
	// Each element is a copy of v2
	vector<vector<int> > v2d2(3, v2);


	//Create a vector of vectors to store the number of each attributes in each feature of the dataset
	vector <int> eachAttrib(maxAttrib + 1, 0);
	vector<vector<int> > countAttrib(numFeatures, eachAttrib);		//Number of each attribute in the columns
	//vector<vector<double> > countAttrib(numFeatures, vector<double> (maxAttrib+1));			//Number of each attribute in the columns

	//Create a vector to store entropy and probability
	vector <double> entropy(numFeatures, 0);		//Entropy of the different features
	vector <double> eachAttrib_d(maxAttrib + 1, 0);
	vector<vector<double> > probAttrib(numFeatures, eachAttrib_d);			//Probability of each attributes of each feature

	//Update the number of each attributes in each feature
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++)
		{
			if (stof(data[i][numFeatures - j - 1]) == 0)
			{
				countAttrib[numFeatures - j - 1][0] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 1)
			{
				countAttrib[numFeatures - j - 1][1] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 2)
			{
				countAttrib[numFeatures - j - 1][2] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 3)
			{
				countAttrib[numFeatures - j - 1][3] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 4)
			{
				countAttrib[numFeatures - j - 1][4] += 1;
			}
			else if (stof(data[i][numFeatures - j - 1]) == 5)
			{
				countAttrib[numFeatures - j - 1][5] += 1;
			}
		}//inner for loop ends here
	}//outer for loop ends here

	//Uncomment to print out and test countAttrib vector
	//printVecofVec(countAttrib);			//Overloading the function printVecofVec

	//Erase all the zero fields in countAttrib vector to prepare it for probability calculation
	//countAttrib = preprocessRemZero(countAttrib);

	//Uncomment to print out and test countAttrib vector
	//cout << "countAttrib vector has: ";
	//printVecofVec(countAttrib);			//Overloading the function printVecofVec

	//Find the probability of the attributes
	probAttrib = findProbVecofVec(probAttrib, countAttrib, numEntries);

	//Uncomment to print out and test probAttrib vector
	//printVecofVec(probAttrib);			//Overloading the function printVecofVec

	//Erase all the zero fields in probAttrib vector
	probAttrib = preprocessRemZero(probAttrib);

	//Uncomment to print out and test probAttrib vector
	//printVecofVec(probAttrib);			//Overloading the function printVecofVec

	//Find entropy of the column
	for (int i = 0; i < probAttrib.size(); i++){
		for (int j = 0; j < probAttrib[i].size(); j++)
		{
			entropy[i] = entropy[i] + (probAttrib[i][j] * log2(probAttrib[i][j]));
		}
		entropy[i] *= -1;	//account for the - sign in equation.
	}

	//Uncomment to output Entropy
	//cout << "Entropy values are: ";
	//printVec(entropy);		//Overloading the function printVec

	//Set the value of entropy
	setEntropy(entropy);	
}

//Function definition of findInformationGain
void featureExtraction::findInformationGain()
{
	//Get entropy value
	entropy = getEntropy();
	//Get maximum number of attributes
	maxAttrib = getMaxAttrib();

	cout << "Finding the information gain of different features in the dataset." << endl;
	cout << endl;
	//Initialize the parent entropy to a variable
	double entropy_parent = entropy[entropy.size() - 1];

	//For multi attribute problems, classifying based on Information Gain alone is not proper.
	//The information gain ratio needs to be calculated to carry out feature selection.

	vector<double> informationGain(entropy.size(), 0);
	vector<double> IG(entropy.size(), 0);

	if (maxAttrib == 2)
	{
		//Find the information gain
		for (int i = 0; i < entropy.size(); i++)
		{
			informationGain[i] = entropy_parent - entropy[i];
			IG[i] = informationGain[i];
		}
		//Uncomment to output the Information Gain Ratio of each feature
		for (int i = 0; i < entropy.size() - 1; i++)
		{
			cout << "Feature " << i + 1 << '\t' << "Information Gain: " << informationGain[i] << endl;
			if (i == entropy.size() - 2)
				cout << "Feature " << entropy.size() << " is the binary output of the decision tree" << endl;
		}
	}
	else
	{
		//Find the information gain ratio
		for (int i = 0; i < entropy.size(); i++)
		{
			informationGain[i] = entropy_parent - entropy[i];
			IG[i] = abs(informationGain[i]) / entropy[i];
		}
		//Uncomment to output the Information Gain Ratio of each feature
		for (int i = 0; i < entropy.size() - 1; i++)
		{
			cout << "Feature " << i + 1 << '\t' << "Information Gain Ratio: " << IG[i] << endl;
			if (i == entropy.size() - 2)
				cout << "Feature " << entropy.size() << " is the binary output of the decision tree" << endl;
		}
	}
	cout << endl;
	setIG(IG);
}

//Function definition of extractFeatures
void featureExtraction::extractFeatures(vector<vector<string> > data)
{
	//Get Information Gain IG
	vector<double> IG = getIG();
	vector < vector<string> >extractedDataset;
	double sum = 0.0;
	double avg = 0.0;
	//Find the sum of elements
	for (double n : IG)
		sum += n;

	//Find the average
	avg = sum / IG.size();

	//Uncomment to print IG vector
	//printVec(IG);					//Overloading the function printVec

	//Extract the dataset
	for (int i = 0; i < IG.size(); i++)
	{
		if (IG[i] > avg)
		{
			cout << "Feature " << i + 1 << " with Information Gain " << IG[i] << " is a good feature to implement the decision tree" << endl;
		}
		else
			data = deleteColumn(data, i);
	}
	cout << endl << "Writing the extracted features into a 'extractedDataset.dat'" << endl;
	cout << endl;

	//Write the extracted dataset into a text file
	ofstream writeFile;
	writeFile.open("extractedDataset.dat", ios::out);
	for (int i = 0; i < data.size(); i++){
		for (int j = 0; j < data[i].size(); j++){
			if (!data[i].empty())
				writeFile << data[i][j] << ' ';
		}
		writeFile << '\n';
	}
}
