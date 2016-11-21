// Filename:        regression.hpp
// Owner:           Jeremy Thomas
// Purpose:         Class declarations for the Regression class

#ifndef FILE_REGRESSION_H_INCLUDED
#define FILE_REGRESSION_H_INCLUDED

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <cmath>
	
class Regression
{
public:
    Regression(const std::vector<std::pair<double, double>> & data);
    
    double getSlope();

    double getSlopeUncertainty();

    int getSize();

    double getIntercept();

    double getInterceptUncertainty();

    double getStdDev();


private:

    std::vector<std::pair<double, double>> _data;
    double _slope = 0.0;
    double _yAve = 0.0;
    double _xAve = 0.0;
    double _intercept = 0.0;
    double _stdDev = 0.0;
    double _SSxy = 0.0;                     // The sum of (x-xAve)*(y-yAve)
    double _SSyy = 0.0;                     // The sum of (y-yAve)^2
    double _SSxx = 0.0;                     // The sum of (x-xAve)^2
    double _sumXY = 0.0;                    // The sum of (x_i * y_i)
    double _sumX = 0.0;                     // The sum of (x_i)
    double _sumY = 0.0;                     // The sum of (y_i)
    double _sumXsquared = 0.0;              // The sum of (x_i)^2
    double _uncertaintySlope = 0.0;
    double _uncertaintyIntercept = 0.0;
    
    void sumsCalculator();

    void averagesCalculator();

    void slopeCalculator();

    void stdDevCalculator();

    void interceptCalculator();

    void uncertaintiesCalculator();

};

// struct graphMetaData
// {
//     std::string x;
//     std::string y;
//     std::string title;
// };


#endif //#ifndef FILE_REGRESSION_H_INCLUDED