// regression.hpp

#ifndef FILE_REGRESSION_H_INCLUDED
#define FILE_REGRESSION_H_INCLUDED

#include <vector>
	using std::vector;
#include <string>
	using std::string;
	
struct dataPoint
{
    double x;
    double y;
};

struct graphMetaData
{
    string x;
    string y;
    string title;
};


// These functions should return legitimate values.
double intercept(const vector <dataPoint> & data);
double slope(const vector <dataPoint> & data);

#endif //#ifndef FILE_BUBBLE_SORT_H_INCLUDED