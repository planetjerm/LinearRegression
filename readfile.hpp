// Filename:        readfile.hpp
// boilerplate incoming


// Of course we include these to make sure we don't run through this header
// twice.
#ifndef FILE_READFILE_H_INCLUDED
#define FILE_READFILE_H_INCLUDED

// These are the libraries needed for the class ReadFile
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>

class ReadFile
{
// these are the functions which can be called from OUTSIDE the particular
// instance of the class
public:
	// This is the constructor
	ReadFile(const std::string & filename);
	
	// This function returns the data vector obtained from the file
	std::vector <std::pair <double, double>> getData();

	// This function returns the headers for the x and y axis
	std::pair <std::string, std::string> getHeaders();

// These functions and variables are only visible INSIDE the particular instance
// of the class
private:
	
	// This function opens the file
	void openFile(const std::string & filename);
	
	// This function reads the data from the file to the data vector and
	// the headers, then closes the filestream
	void parseFile();

	std::pair <std::string, std::string> _headers {"",""};
	std::vector <std::pair<double, double>> _data;
	std::ifstream _dataStream;
};


#endif //#ifndef FILE_READFILE_H_INCLUDED