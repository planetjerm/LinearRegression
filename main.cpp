#include <GL/glut.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <vector>
#include <cstdlib>
#include <Windows.h>
#include "LinearRegression.h"
#include <algorithm>
using std::max_element;
using std::sort;

void display()
{
	std::vector <std::pair<double, double>> data; //creates inital vector pair
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); //creates color
	glClear(GL_COLOR_BUFFER_BIT); //clears and buffers the color
	glPointSize(4.0); //point size
	// Initalize a test vector;
	for (double i = 0; i < 100; i++)
	{
		data.push_back(std::make_pair(i, i + 1));
	}

	
	
	//Creates each point
	glBegin(GL_POINTS);
	for (int i = 0; i <= data.size()-1; i++)
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(.01*data[i].first, .01*data[i].second);
	}
	glEnd();

	glFlush();
}
	
	

int main(int argc, char** argv)
{
	

	
	glutInit(&argc, argv);
	glutCreateWindow("Practice Test");
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 50);
	glutDisplayFunc(display);
	glutMainLoop();
}

	




		
	
	


