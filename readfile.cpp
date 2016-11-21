// Filename:        readfile.cpp
// boilerplate incoming

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
		std::cout << "Returning to terminal." << std::endl;
		// 0 is the all good exit. I chose to still use this value because we
		// aren't concerned with the specifics of WHY it failed to load the
		// file and don't indent to try to catch this.
		std::exit(0);
	}
	parseFile();
}

void ReadFile::parseFile()
{
	// These variables are created here instead of in the class definitions
	// because they are temporary.
	std::string stringHolder;
	bool headersDefined=false;
	// This '/r' is for >>macOS<<. Other OS will potentially require
	// different newline operators.
	while(getline(_dataStream, stringHolder, '\r'))
	{
		for (int i=0; i<stringHolder.size(); i++)
		{
			if(stringHolder[i]==',')
			{
				if (headersDefined==false)
				{
					_headers.first=stringHolder.substr(0,i);
					_headers.second=stringHolder.substr(i+1);
					headersDefined=true;
				}
				else 
				{
					// We make a few assumptions here. One is that we'll
					// recieve a properly formatted file. If it isn't, we'll
					// have some serious issues on our hands.
					_data.push_back(std::make_pair(std::stod(stringHolder.
						substr(0,i)), std::stod(stringHolder.substr(i+1))));
				}
				break;
			}
		}
	}
	// I close the data stream now that we've read in the data.
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