// Filename:        regression.cpp
// Owner:           Jeremy Thomas
// Purpose:         Class definitions for the Regression class

#include "regression.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <utility>

Regression::Regression(const std::vector<std::pair<double, double>> & data)
{
    _data=data;
    sumsCalculator();
    slopeCalculator();
    interceptCalculator();
    uncertaintiesCalculator();
    stdDevCalculator();
}
    
double Regression::getSlope()
{
    return _slope;
}

double Regression::getSlopeUncertainty()
{
    return _uncertaintySlope;
}

double Regression::getInterceptUncertainty()
{
    return _uncertaintyIntercept;
}

int Regression::getSize()
{
    return _data.size();
}

double Regression::getIntercept()
{
    return _intercept;
}

double Regression::getStdDev()
{
    return _stdDev;
}

void Regression::sumsCalculator()
{

    for (int i=0; i<_data.size(); i++)
    {
        // Sum of all (x_i times y_i)
        _sumXY = _sumXY + (_data[i].first)*(_data[i].second);
        // sum of all x_i
        _sumX = _sumX + (_data[i].first);
        // sum of all y_i
        _sumY = _sumY + (_data[i].second);
        // sum of all (x_i)^2
        _sumXsquared = _sumXsquared + std::pow(_data[i].first, 2);
    }

        // This function is called because the rest of the sums are dependent on it.
        averagesCalculator();

    for (int i=0; i<_data.size(); i++)
    {
        // SSyy
        _SSyy+= std::pow(_data[i].second-_yAve, 2);
        // SSxy
        _SSxy+= (_data[i].second-_yAve)*(_data[i].first-_xAve);
        // SSxx
        _SSxx+= std::pow(_data[i].first-_xAve, 2);
    }
    // End of sumsCalculator
}

void Regression::averagesCalculator()
{
    _yAve= (_sumY/_data.size());
    _xAve= (_sumX/_data.size());
}

void Regression::slopeCalculator()
{
    _slope= (_data.size()*_sumXY-_sumX*_sumY)/(_data.size()*_sumXsquared-_sumX*_sumX);
}

void Regression::stdDevCalculator()
{
    _stdDev= std::pow((_SSyy-_slope*_SSxy)/(_data.size()-2) , 0.5);
}

void Regression::interceptCalculator()
{
    _intercept= (_sumXsquared*_sumY-_sumXY*_sumX)/(_data.size()*_sumXsquared-_sumX*_sumX);
}

void Regression::uncertaintiesCalculator()
{
    // The uncertainty in the slope
    _uncertaintySlope = _stdDev/std::pow(_SSxx, 0.5);

    // The uncertainty in the intercept
    _uncertaintyIntercept = _stdDev*(1/_data.size()+std::pow(_xAve, 2)/_SSxx);
}

// detla s is y
// w is x

int main()
{
    std::vector <std::pair<double, double>> data;
    
    // Initalize a test vector;
    for (double i=0; i<10; i++)
    {
        data.push_back(std::make_pair(i, i));
        // std::cout << data[i].first << " " << data[i].second << std::endl;
    }
    
    Regression swag(data);
    
    std::cout << "Slope: " << swag.getSlope() << std::endl;
    std::cout << "intercept: " << swag.getIntercept() << std::endl;
    std::cout << "stdDev: " << swag.getStdDev() << std::endl;
    std::cout << "Slope uncertainty: " << swag.getSlopeUncertainty() << std::endl;
    std::cout << "Intercept uncertainty: " << swag.getInterceptUncertainty() << std::endl;
    
}