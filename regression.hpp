// regression.hpp

#ifndef FILE_REGRESSION_H_INCLUDED
#define FILE_REGRESSION_H_INCLUDED

#include <vector>
#include <string>
#include <utility>
	
class Regression
{
public:
    Regression(const std::vector<std::pair<double, double>> & data);
    double getSlope();

    int getSize();

    double getIntercept();


private:

    std::vector<std::pair<double, double>> _data;
    double _slope = 0.0;
    double _intercept = 0.0;
    double _stdDev = 0.0;
    double _residual = 0.0;
    double _sumXY = 0.0;          // The sum of (x_i * y_i)
    double _sumX = 0.0;           // The sum of (x_i)
    double _sumY = 0.0;           // The sum of (y_i)
    double _sumXsquared = 0.0;    // The sum of (x_i)^2
    double _squaredSumX = 0.0;    // The square of the sum of (x_i)
    
    void sumsCalculator();

    void slopeCalculator();

    void stdDevCalculator();

    void interceptCalculator();

};

// struct graphMetaData
// {
//     std::string x;
//     std::string y;
//     std::string title;
// };


#endif //#ifndef FILE_BUBBLE_SORT_H_INCLUDED