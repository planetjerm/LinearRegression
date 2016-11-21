// Filename:        readfile.cpp
// Owner:           Jeremy Thomas
// Purpose:         Class definitions for the Regression class

#include "readfile.hpp"

ReadFile::ReadFile(const std::string & filename)	// Costructor
{
	openFile(filename);
}

void ReadFile::openFile(const std::string & filename)
{
	_dataStream.open(filename);
	if (!_dataStream)
	{
		std::cout << "Fatal error: file connection failure." << std::endl;
		// Exit the program somehow here
	}
	// std::string stringHolder;
	// while(!_dataStream.eof())
	// {
	// 	getline(_dataStream, stringHolder, '\r');
	// 	std::cout << "While loop stepping" << std::endl;
	// 	std::cout << stringHolder << std::endl;
	// }
	parseFile();
}

void ReadFile::parseFile()
{
	std::string stringHolder;
	while(getline(_dataStream, stringHolder, '\r'))
	{
		for (int i=0; i<stringHolder.size(); i++)
		{
			if(stringHolder[i]==',')
			{
				if (_headers.first=="")
				{
					_headers.first=stringHolder.substr(0,i);
					_headers.second=stringHolder.substr(i+1);
				}
				else 
				{
					_data.push_back(std::make_pair(std::stod(stringHolder.substr(0,i)), std::stod(stringHolder.substr(i+1))));
				}
				break;
			}
		}
	}
	_dataStream.close();
}

std::vector <std::pair <double, double>> ReadFile::getData()
{
	return _data;
}

std::pair <std::string, std::string> ReadFile::getHeaders()
{
	return _headers;
}