// Filename:        regression.hpp
// Boilerplate incoming


// Of course we include these to make sure we don't run through this header
// twice.
#ifndef FILE_REGRESSION_H_INCLUDED
#define FILE_REGRESSION_H_INCLUDED

// These are the libraries required for this class
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <cmath>
	
class Regression
{
// these are the functions which can be called from OUTSIDE the particular
// instance of the class
public:
    // This is the constructor
    Regression(const std::vector<std::pair<double, double>> & data);
    
    // This function will return the slope
    double getSlope();

    // This function will return the uncertainty of the slope
    double getSlopeUncertainty();

    // This function will return the number of data points stored
    int getSize();

    // This function will return the y intercept, or the b in y=mx+b
    double getIntercept();

    // This function will return the uncertainty in the intercept
    double getInterceptUncertainty();

    // This function returns the standard deviation
    double getStdDev();


// These functions and variables are only visible INSIDE the particular instance
// of the class
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
    
    // This function calculates all of the sums we need for our other
    // functions.
    void sumsCalculator();

    // This function calculates averages, which are needed for certain sums
    void averagesCalculator();

    // This function calculates the slope, or m in y=mx+b
    void slopeCalculator();

    // Thus function calculates the standard deviation
    void stdDevCalculator();

    // Thus function calculates the intercept, or b in y=mx+b
    void interceptCalculator();

    // Thus function calculates uncertanty in the slope and the intercept
    void uncertaintiesCalculator();

};

#endif //#ifndef FILE_REGRESSION_H_INCLUDED