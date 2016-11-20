#include <GL/glut.h>
#include "Display.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "LinearRegression.h"
#include <algorithm>

Display::Display(const std::vector<std::pair<double, double>> & data)
{
	_data = data;
	largestxvalue();
	largestyvalue();
	smallestxvalue();
	smallestyvalue();
}

std::pair<double, double> Display::getlargexvalue()
{
	return largexvalue;
}

std::pair<double, double> Display::getlargeyvalue()
{
	return largeyvalue;
}

std::pair<double, double> Display::getsmallxvalue()
{
	return smallxvalue;
}

std::pair<double, double> Display::getsmallyvalue()
{
	return smallyvalue;
}



void Display::largestxvalue()
{
	largexvalue =
		*(std::max_element(_data.begin(), _data.end(), [](const std::pair<double, double > & right, const std::pair<double, double> & left) {
		return right.first < left.first; }));
}



void Display::largestyvalue()
{
	largeyvalue =
		*(std::max_element(_data.begin(), _data.end(), [](const std::pair<double, double > & right, const std::pair<double, double> & left) {
		return right.second < left.second; }));
}

void Display::smallestxvalue()
{
	smallxvalue =
		*(std::min_element(_data.begin(), _data.end(), [](const std::pair<double, double > & right, const std::pair<double, double> & left) {
		return right.first > left.first; }));
}



void Display::smallestyvalue()
{
	smallyvalue =
		*(std::min_element(_data.begin(), _data.end(), [](const std::pair<double, double > & right, const std::pair<double, double> & left) {
		return right.second > left.second; }));
}
