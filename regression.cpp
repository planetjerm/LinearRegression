// regression.cpp

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
}
    
double Regression::getSlope()
{
    return _slope;
}

int Regression::getSize()
{
    return _data.size();
}

double Regression::getIntercept()
{
    return _intercept;
}

void Regression::sumsCalculator()
{
// Sum of all (x_i times y_i)
for (int i=0; i<_data.size(); i++)
{
    _sumXY = _sumXY + (_data[i].first)*(_data[i].second);
}

// sum of all x_i
for (int i=0; i<_data.size(); i++)
{
    _sumX = _sumX + (_data[i].first);
}

// sum of all y_i
for (int i=0; i<_data.size(); i++)
{
    _sumY = _sumY + (_data[i].second);
}

// sum of all (x_i)^2
for (int i=0; i<_data.size(); i++)
{
    _sumXsquared = _sumXsquared + std::pow(_data[i].first, 2);
}

// (sum of all x_i)^2
double _squaredSumX = std::pow(_sumX, 2);
}

void Regression::slopeCalculator()
{
    _slope= ((_data.size()*_sumXY-(_sumX*_sumY))/(_data.size()*_sumXsquared- _squaredSumX));
}

void Regression::stdDevCalculator()
{

}

void Regression::interceptCalculator()
{
    _intercept=(((_sumXsquared*_sumY)-(_sumXY*_sumX))/(_data.size()*_sumXsquared-_squaredSumX));
}

// double slope()
// {
//     int n = data.size();
    
//     // Sum of all (x_i times y_i)
//     double s1= 0.0;
//     for (int i=0; i<n; i++)
//     {
//         s1 = s1 + (data[i].first)*(data[i].second);
//     }

//     // sum of all x_i
//     double s2 = 0.0;
//     for (int i=0; i<n; i++)
//     {
//         s2 = s2 + (data[i].x);
//     }

//     // sum of all y_i
//     double s3 = 0.0;
//     for (int i=0; i<n; i++)
//     {
//         s3 = s3 + (data[i].y);
//     }

//     // sum of all (x_i)^2
//     double s4 = 0.0;
//     for (int i=0; i<n; i++)
//     {
//         s4 = s4 + pow(data[i].x, 2);
//     }

//     // (sum of all x_i)^2
//     double s5 = pow(s2, 2);

//     return ((n*s1-s2*s3)/(n*s4-s5));
// }

// double intercept(const vector <dataPoint> & data)
// {
//     int n = data.size();
    
//     // Sum of all (x_i times y_i)
//     double s1= 0.0;
//     for (int i=0; i<n; i++)
//     {
//         s1 = s1 + (data[i].x)*(data[i].y);
//     }

//     // sum of all x_i
//     double s2 = 0.0;
//     for (int i=0; i<n; i++)
//     {
//         s2 = s2 + (data[i].x);
//     }

//     // sum of all y_i
//     double s3 = 0.0;
//     for (int i=0; i<n; i++)
//     {
//         s3 = s3 + (data[i].y);
//     }

//     // sum of all (x_i)^2
//     double s4 = 0.0;
//     for (int i=0; i<n; i++)
//     {
//         s4 = s4 + pow(data[i].x, 2);
//     }

//     // (sum of all x_i)^2
//     double s5 = pow(s2, 2);

//     return (((s4*s3)-(s1*s2))/(n*s4-s5));
// }

int main()
{
    std::vector <std::pair<double, double>> data;
    
    // Initalize a test vector;
    for (double i=0; i<100; i++)
    {
        data.push_back(*(new std::pair<double, double> {i,i+1}));
    }
    
    Regression swag(data);
    
    std::cout << "Slope: " << swag.getSlope() << std::endl;
    std::cout << "intercept: " << swag.getIntercept() << std::endl;
    
}