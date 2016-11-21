// Filename:        regression.cpp
// boilerplate incoming

#include "regression.hpp"

Regression::Regression(const std::vector<std::pair<double, double>> & data)
{
    _data=data;
    sumsCalculator();
    slopeCalculator();
    interceptCalculator();
    stdDevCalculator();
    uncertaintiesCalculator();
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
        // The sum of all (y_i - yAve)^2
        _SSyy+= std::pow(_data[i].second-_yAve, 2);
        // The sum of all (y_i - yAve)*(x_i - xAve)
        _SSxy+= (_data[i].second-_yAve)*(_data[i].first-_xAve);
        // The sum of all (x_i - xAve)^2
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
    _uncertaintySlope = _stdDev/(std::pow(_SSxx, 0.5));

    // The uncertainty in the intercept
    _uncertaintyIntercept = _stdDev*(1/_data.size()+std::pow(_xAve, 2)/_SSxx);
}