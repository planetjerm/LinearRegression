/*******************************************************************************
* Class:            CS 201                                                     *
* Group Project:    Statistical Analysis                                       *
* Team Members:     Kelly Offield - kcoffield@alaska.edu                       *
*                   Jeremy Thomas - jdthomas7@alaska.edu                       *
*                   Samuel Grenon - sgrenon@alaska.edu                         *
*                                                                              *
* File Purpose:     Documentation for CS 201 Statistical Analysis              *
* Filename:         readme.txt                                                 *
*******************************************************************************/

	CS 201 Statistical Analysis is a command line tool that utilizes both 
standard libraries and GLUT. This tool will read in a CSV file, perform 
statistical analysis, and create a useful visual graph.

	Statistical analysis in this context refers to performing a linear 
regression: finding the slope, intercept, and associated uncertanties.

	The program uses the GLUT library to graph the data points read in from the
CSV file. Data points are graphed individually and the linear fit is graphed
over them.

	The CSV file the user intends to perform statistical analysis on must follow
certain conventions. It must be comma seperated by column, and newline seperated
by row. The first two entries in the file (the first line) must be the column
headers. There must only be two columns in the CSV.

Example data set:
********************************************************************************
X axis header, Y axis header
12.34, 12.34
23.45, 23.45
34.56, 34.56
45.67, 45.67
56.78, 56.78
78.90, 78.90
********************************************************************************

	When executing the program, please ensure the CSV file you intend to analyse
is in the same folder as 'StatisticalAnalysis.exe'. The program will ask for a
filename; please input the name of the file to be analysed. The program will
then analyse the data and print statistical information to the terminal. A 
window will then be opened by the program where it will create a graph that
represents the data that was imported. If the user clicks on the graph, the
program will print the coordinates of the locatation that was clicked relative
to the graph.

	This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License as published by the Free 
Software Foundation, either version 3 of the License, or (at your option) any
later version.

	This program is distributed in the hope that it will be useful, but WITHOUT 
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>

********************************************************************************
GLUT citation:
	Copyright (c) Mark J. Kilgard, 1994, 1995, 1996, 1998, 2000, 2006, 2010.

	This program is freely distributable without licensing fees and is provided 
without guarentee or warrantee expressed or implied. This program is -not- in 
the public domain.