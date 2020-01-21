

/********************************************************************

Filename:ass3.cpp

Version : 1.1

Author : Dongxu Jiang

Student No : 040 920 915

Course Name / Number : CST8233 Numerical Computing

Lab Sect : 311

Assignment # : 2

Assignment name : Transient-Response Analysis of 1st Order Systems

Due Date : Dec 6 2019

Submission Date : Dec 01 2019

Professor : Hala Own

Purpose : Find the solution of 1st order Ordinary Differential Equations (ODE) using well known

methods; namely, Euler’s and Runge-Kutta 2nd Order Methods.

*********************************************************************/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	double h,m;/*set h(increasing value) value and m for Euler method*/
	double exact;/*for calculating exact value*/
	double step[] = { 0.8,0.2,0.05 };/*list all possible h values*/
	double t = 0,y=3;/*initially set (x0,y0) value which was respented by t and y*/
	int opt = 0;/*user options*/
	double k1, k2, k3, k4;/*k1, k2, k3, k4*/
	while (1) {/*loop to take user options*/
		cout << ">>Choose the method for solving the ODE:\n1.Euler’s Method\n2.unge-Kutta 4th Order Method\n>>";
		cin >> opt;
		if (opt == 3)/*in case to quit programm*/
			break;
		while (1) {/*loop if user input a value not in the list*/
			cout << "Choose step size “h” (0.8, 0.2, 0.05)\n>> ";
			cin >> h;
			if (h != step[0] && h != step[1] && h != step[2]) {
				cout << "Invalid step size..." << endl;
			}
			else break;/*break if inputs is valid*/
		}
		cout << "Time(second)\tExact Temp(C)\tEstimated Temp(C)\tPercentage Error(%) " << endl;/*value titles*/
		for (int i = 1; i <= 10; i++) {/*loop 10 times to display 10 different situations*/
			if (opt == 1) {/*Euler’s Method*/
				m = cos(4 * t) - 2*y;
				y = y + h * m;
				t = t + h;/*increase t for next calculation*/
				exact = 0.1 * cos(4 * t) + 0.2 * sin(4 * t)+ 2.9 * exp(-2 * t);/*calculate exact value*/
				cout << left << setw(16) << t << fixed << setprecision(3) << setw(16) << exact << setw(24) << y << fixed << setprecision(2) << setw(61) << abs((y-exact) / exact * 100) << endl;/*display*/
			}
			else if (opt == 2) {/*unge-Kutta 4th Order Method*/
				k1 = cos(4 * t) - y* 2;

				k2 = cos(4 * (t + h / 2)) - 2*(y + h / 2 * k1);

				k3 = cos(4 * (t + h / 2)) - 2*(y + h / 2 * k2);

				k4 = cos(4 * (t + h)) - 2*(y + h * k3);
				y = y + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);

				t = t + h;/*increase t for next calculation*/
				exact = 0.1 * cos(4 * t) + 0.2 * sin(4 *t) + 2.9 * exp(-2 * t);/*calculate exact value*/
				cout << fixed;
				cout << setprecision(1);				/*set precision*/
				cout <<left << setw(16) <<t  << fixed<< setprecision(3) << setw(16) << exact << setw(24) << y  << fixed << setprecision(2) << setw(61) << abs((y-exact) / exact*100) << endl;/*display*/
			}
		}
		t = 0;/*reset t and y*/
		y = 3;
	}
	return 0;
}
