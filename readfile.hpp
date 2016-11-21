// Filename:        readfile.hpp
// Owner:           Jeremy Thomas
// Purpose:         Class declarations for the ReadFile class

#include <string>
#include <fstream>
#include <vector>
#include <iostream>


#ifndef FILE_READFILE_H_INCLUDED
#define FILE_READFILE_H_INCLUDED

class ReadFile
{
public:
	ReadFile(const std::string & filename);
	
	std::vector <std::pair <double, double>> getData();

	std::pair <std::string, std::string> getHeaders();

private:
	
	void openFile(const std::string & filename);
	
	void parseFile();

	//std::ifstream _dataStream;
	std::pair <std::string, std::string> _headers {"",""};
	std::vector <std::pair<double, double>> _data;
	std::ifstream _dataStream;
};


#endif //#ifndef FILE_READFILE_H_INCLUDED