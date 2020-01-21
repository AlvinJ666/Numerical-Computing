

/********************************************************************

Filename:ass2.cpp

Version : 1.1

Author : Dongxu Jiang

Student No : 040 920 915

Course Name / Number : CST8233 Numerical Computing

Lab Sect : 311

Assignment # : 2

Assignment name : Moore’s Law

Due Date : Nov 12 2019

Submission Date : Nov 08 2019

Professor : Hala Own

Purpose : Fit data using linear regression least-squares method for an exponential function.

*********************************************************************/
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
vector <double> value;//use a vector to store data
int n;//to calculate the number of data pairs
double x;//x value
double y;//y value
double deltaY;//delta y, the numerator to calculate a0
double sum_xy;//the sum of xy products
double sum_x;//the sum of x values
double sum_sqrx;//the sum of square x values
double sum_y;//the sum of y values
double sum_sqry;//the sum of square y values
double m,a;//the m value and a value in this assignment
double c,b;//the c value and b value in this assignment
/******************************************************************

Function name : calculate()

Purpose:to calculate m,c,a,b, values

In parameters : none

Out parameters : 0

for successful executionVersion : 1.1

Author : Dongxu Jiang

**********************************************************************/
void calculate() {
	n =  value.size();
	for (int i = 0; i < n;i+=2) {//loop through to calculate all necessary values
		x = value[i]-1970;//x value
		y = log(value[i + 1]);//y value
		sum_x += x;//sum of x value
		sum_y += y;//sum of y value
		sum_sqrx+= (x* x);//sum of square x value
		sum_sqry += (y * y);//sum of square y value
		sum_xy += (x*y);//sum of xy value
	}
	n /= 2;//devide by 2 to get number of data pairs
	deltaY = n * sum_sqrx - sum_x * sum_x;//calculate deltaY
	m =(n * sum_xy - sum_x * sum_y) / deltaY;// apply formula to get m(a0)
	c = (sum_y - m*sum_x) / n;// apply formula to get m(a1)
	b = m;// b equal to m
	a= exp(c);// a equal to e^c
}
/******************************************************************

Function name : main()

Purpose:to generate a menu and submenu for user to evaluate the equation 

In parameters : none

Out parameters : 0

for successful executionVersion : 1.1

Author : Dongxu Jiang

**********************************************************************/
int main() {
	int opt = 0;
	int subopt=0;
	int year;
	double transistor;
	double pre_transistor;
	double rate;
	string filename="";//initialize the file name;
	while(opt!=2){
		cout << "LEAST_SQUARES LINEAR REGRESSION\n\n"<<"MENU\n 1.Exponential Fit\n 2.Quit" << endl;
		cin >> opt;
		if (opt == 1) {
			cout << "Please enter the name of the file to open: " << endl;//read file name and open file
			cin >> filename;
			ifstream infile(filename, ios::in);
			if (!infile) {//if fail to open a file
				cout << "File can't be opened." << endl;
				return -1;
			}
			string Year, TranCount, Name;//initialize 3 strings to take the value of year,transcount and name
			int linecount = 0;//count lines from 0
			while (infile >> Year >> TranCount >> Name) {//read values of each line to 3 strings
				cout << Year << '\t' << TranCount << '\t' << Name << endl;//print out values read from the file
				if (linecount >= 1) {//when line count is larger or eqaul to 1, star to store data into the vector
					value.push_back(stod(Year));//add value of year to vector
					value.push_back(stod(TranCount));//add value of TranCount year to vector
				}
				linecount++;//increase line count
			}
			infile.close();//close file stream
			cout << '\n' << "There are " << (linecount - 1) << " records." << '\n' << endl;//report records read from file
			calculate();//do the calculations
			cout << scientific << setprecision(3);//print out data in sentific value format
			cout << "Linear Regression Fit:  transistor count = "<<a<<"*exp("<<m<<"*(year-1970)"<<endl;//print out equaltion			
			while (1) {
				cout << "MENU\n 1. Extrapolation\n 2. Main Menu" << endl;
				cin >> subopt;
				if (subopt == 2)
					break;
				if (subopt == 1) {
					cout << "Please enter the year to extrapolate to: " << endl;
					cout << "Year = ";
					cin >> year;
					transistor = a * exp(b * (year - (double)1970));//calcualte transistors by applying the equaltion
					cout << "transistor count = " << transistor << endl;
					cout << "rate of count increase = " << (transistor*b) <<"transistors/year"<< endl;//calculate increase rate and print it out
				}
				else {
					cout << "Invalid option." << endl;//if input is not a valid option
				}
			}
		}
	}
	return 0;
}
