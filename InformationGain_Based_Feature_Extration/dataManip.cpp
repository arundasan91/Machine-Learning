#include "datamanip.h"
using namespace std;

//Define function printVecofVec
void printVecofVec(vector<vector<string> > data)
{
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++)
			cout << data[i][j] << '\t';
		cout << '\n';
	} //print loop ends here
}

//Function Overloading on printVecofVec
void printVecofVec(vector<vector<double> > data)
{
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++)
			cout << data[i][j] << '\t';
		cout << '\n';
	} //print loop ends here
}

//Function Overloading on printVecofVec
void printVecofVec(vector<vector<int> > data)
{
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++)
			cout << data[i][j] << '\t';
		cout << '\n';
	} //print loop ends here
}

//Define function preprocessRemZero
vector<vector<int> > preprocessRemZero(vector<vector<int> > attributeVec)
{
	for (int i = 0; i < attributeVec.size(); i++) {
		for (int j = 0; j < attributeVec[i].size(); j++)
		{
			attributeVec[i].erase(remove(attributeVec[i].begin(), attributeVec[i].end(), 0), attributeVec[i].end());
		}
	}
	return(attributeVec);
}

//Function Overloading on preprocessRemZero
vector<vector<double> > preprocessRemZero(vector<vector<double> > attributeVec)
{
	for (int i = 0; i < attributeVec.size(); i++) {
		for (int j = 0; j < attributeVec[i].size(); j++)
		{
			attributeVec[i].erase(remove(attributeVec[i].begin(), attributeVec[i].end(), 0), attributeVec[i].end());
		}
	}
	return(attributeVec);
}

//Define function deleteColumn
vector < vector<string> >deleteColumn(vector < vector<string> >data, int columnToDelete)
{
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i].size() > columnToDelete)
		{
			data[i].erase(data[i].begin() + columnToDelete);
		}
	}
	/*std::for_each(data.begin(), data.end(),
	[&](vector<string>& row) {
	row.erase(next(row.begin(), columnToDelete));
	});*/
	return (data);
}

//Define function to print a vector()
void printVec(vector<string> Vector)
{
	for (int i = 0; i < Vector.size(); i++)
	{
		cout << Vector[i] << '\t';
	}
	cout << endl;
}

//Function Overloading of the function printVec
void printVec(vector<double> Vector)
{
	for (int i = 0; i < Vector.size(); i++)
	{
		cout << Vector[i] << '\t';
	}
	cout << endl;
}

//Function Overloading of the function printVec
void printVec(vector<int> Vector)
{
	for (int i = 0; i < Vector.size(); i++)
	{
		cout << Vector[i] << '\t';
	}
	cout << endl;
}
