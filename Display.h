#ifndef FILE_DISPLAY_H_INCLUDED
#define FILE_DISPLAY_H_INCLUDED

#include <vector>
#include <string>
#include <utility>

class Display
{
public:
	Display(const std::vector<std::pair<double, double>> & data);

	std::pair<double, double> getlargexvalue();

	std::pair<double, double> getlargeyvalue();

	std::pair<double, double> getsmallyvalue();

	std::pair<double, double> getsmallxvalue();

private:
	std::vector<std::pair<double, double>> _data;
	std::pair<double, double>largexvalue;
	std::pair<double, double>largeyvalue;
	std::pair<double, double>smallyvalue;
	std::pair<double, double>smallxvalue;

	void smallestyvalue();
	void smallestxvalue();
	void largestxvalue();
	void largestyvalue();
};

#endif



