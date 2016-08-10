#include <iostream>
#include "dataset.h"
#include "datamanip.h"

using namespace std;

//Define the constructor
Dataset::Dataset(const std::string &filename)
	:filename("test.dat")
{
	//empty body
}	//end Dataset constructor

//Define the setFilename function
void Dataset::setFilename(const std::string &Fname)
{
	filename = Fname;
}
//Define the getFilename function
std::string Dataset::getFilename() const
{
	return filename;
}
//Define the loadDataset function
vector<vector<string> >Dataset::loadDataset()
{
	vector<vector<string> > data;
	vector<string> parent;
	int numFeatures;

	//Read the file using the filename
	string filename;
	filename = Dataset::getFilename();	//Use getFilename function to read filename
	ifstream in(filename);				//Create ifstream object 'in'

	// Only if the file is present, proceed.
	if (in) {
		string line;

		while (getline(in, line)) {

			// Push back the whole line at once
			data.push_back(vector<string>());

			// Break down the row into column values
			stringstream split(line);
			string value;

			// Update the dataset with split values
			while (split >> value)
				data.back().push_back(value);

		} //while ends here
	} //if(in) ends here
	else // If the file is not present or unreadable
	{
		// Give and error message
		cerr << "Dataset file could not be opened." << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	// Update the string parent with the values of the parent node.
	for (int i = 0; i < data.size(); i++) {
		numFeatures = data[i].size();
		for (int j = 0; j < data[i].size(); j++)
		{
			// Extract the last column where the binary output is present.
			parent.push_back(data[i][numFeatures - 1]);
		}
	}

	// Uncomment this to check the parent vector
	/*for (int j = 0; j < parent.size(); j++)
	cout << parent[j] << ' ';*/

	// Uncomment this to print the contents of the dataset
	//printVecofVec(data);

	cout << endl <<  "Loaded dataset '" << filename << "' successfully." << endl;

	// Return the paired dataset and parent vectors.
	return data;
} //function readDataset ends here
