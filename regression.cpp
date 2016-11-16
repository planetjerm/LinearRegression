//  main.cpp



#include <iostream>
    using std::cout; using std::cin; using std::endl;
#include <fstream>
#include <string>
    using std::string; using std::getline;
#include <vector>
    using std::vector;
#include <cmath>
    using std::pow;


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

double slope(const vector <dataPoint> & data)
{
    int n = data.size();
    
    // Sum of all (x_i times y_i)
    double s1= 0.0;
    for (int i=0; i<n; i++)
    {
        s1 = s1 + (data[i].x)*(data[i].y);
    }

    // sum of all x_i
    double s2 = 0.0;
    for (int i=0; i<n; i++)
    {
        s2 = s2 + (data[i].x);
    }

    // sum of all y_i
    double s3 = 0.0;
    for (int i=0; i<n; i++)
    {
        s3 = s3 + (data[i].y);
    }

    // sum of all (x_i)^2
    double s4 = 0.0;
    for (int i=0; i<n; i++)
    {
        s4 = s4 + pow(data[i].x, 2);
    }

    // (sum of all x_i)^2
    double s5 = pow(s2, 2);

    return ((n*s1-s2*s3)/(n*s4-s5));
}


// int main()
// {
//     vector <dataPoint> data;
    
//     // Initalize a test vector;
//     for (double i=0; i<100; i++)
//     {
//         data.push_back(*new dataPoint {i,i});
//     }
    
//     for(int i=0; i<data.size(); i++)
//     {
//         cout << data[i].y << " and " << data[i].x << endl;
//     }
    
//     cout << slope(data) << endl;
    
// }