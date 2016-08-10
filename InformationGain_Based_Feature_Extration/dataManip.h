#ifndef DATAMANIP_H
#define DATAMANIP_H
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

//Funtion Overloading of the function printVecofVec()
//Define function to print a vector of vectors
void printVecofVec(std::vector<std::vector<std::string> >);
void printVecofVec(std::vector<std::vector<double> >);
void printVecofVec(std::vector<std::vector<int> >);

//Funtion Overloading of the function preprocessRemZero()
//Define function to remove the zero's in a vector of vectors
std::vector<std::vector<int> > preprocessRemZero(std::vector<std::vector<int> >);
std::vector<std::vector<double> > preprocessRemZero(std::vector<std::vector<double> >);

//Define function deleteColumn()
std::vector < std::vector<std::string> >deleteColumn(std::vector < std::vector<std::string> >, int);

//Function Overloading of the function printVec
//Define function to print a vector()
void printVec(std::vector<std::string>);
void printVec(std::vector<double>);
void printVec(std::vector<int>);
#endif
