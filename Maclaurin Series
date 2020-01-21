/********************************************************************
Filename:ass1.c
Version : 1.1
Author : Dongxu Jiang
Student No : 040 920 915
Course Name / Number : CST8233 Numerical computing
Lab Sect : 311
Assignment # : 1
Assignment name : Building Motion Simulation
Due Date : September 27 2019
Submission Date : September 24 2019
Professor : Mohamed Abouseif
Purpose : a simple C language console application that calculate Tylor series,
truncation error and exact error based on user input(terms for series and range to increase).
*********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
/******************************************************************
Function name : Main
Purpose:funtion to run program, take user input, do calculations and print results out
In parameters : None
Out parameters : none
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
int main() {
	char opt = '1';																				//option to continue(1) program or quite(0),initialize to 1
	int terms = -1;																				//terms(1-5),initialize to -1;
	double incre=-1.0;																			//increment factor(0-2.0),initialize to -1;
	while (opt=='1') {
		printf("Evaluate the Maclaurin Series approximation to exp(-t)*cos(t)\n\n1: Evaluate the series\n2: quite\n");
		scanf("%c", &opt);																		// take option
		while (getchar() != '\n');
		while (opt != '1' && opt != '2') {														//loop until get a valid option
			printf("Please enter a valid option:\n");
			scanf("%c",&opt);
			while (getchar() != '\n');
		}
		if (opt == '1') {																		//get input for terms,loop until get valid number for terms
			printf("Evaluating the series\n");
			while (terms <= 0 || terms >5) {
				printf("Please enter the number of terms in the series (max 5 terms) :");
				scanf("%d", &terms);
				while (getchar() != '\n');
			}
			while (incre <= 0 || incre >2) {													//get input for increment factors, loop until get valid number in range
				printf("Please enter the range of t to evaluate in 10 increments (0.0 < t < +2.0):");
				scanf("%lf", &incre);
				while (getchar() != '\n');
			}
			double t;
			double series,trunc, exact, ext_err,tru_err;
			double default_val = 1.0;
			printf("\nMACLAURIN SERIRS\n");
			printf("t\t\tSeries\t\tExact\t\tExact %% Error\tTrunc. %% Error\n");
			for (int j = 0; j < 11; j++) {														//loop for 11 times to print 11 lines, increase from 0		
					t = j*incre/10;																//divide increment factor by 10 and increase through multiply by the loop control variable,start from 0

					switch (terms)																//calculate serise and first truncation based on the terms
					{
					case 1:
						series = 1.0; 
						trunc = -1*t; 
						break;
					case 2:
						series = 1.0 - t;
						trunc = t * t * t / 3;
						break;
					case 3:
						series = 1.0 - t + t * t * t / 3.0;
						trunc = -1*t * t * t * t / 6;
						break;
					case 4:
						series = 1.0 - t + t * t * t / 3.0 - t * t * t * t / 6.0;
						trunc = t * t * t * t * t / 30;
						break;
					case 5:
						series = 1.0 - t + t * t * t / 3.0 - t * t * t * t / 6.0 + t * t * t * t * t / 30.0;
						trunc = -1*t * t * t * t * t * t * t / 630;
						break;
					}
					exact = exp(-t) * cos(t);																							//calculate exact value by using functions in math library
					ext_err = 100 * (exact - series) / exact;																			//calculate exact error
					tru_err = 100 * trunc / series;																						//calculate relative error
					printf("%-15.3e %-15.5e %-15.5e	%-15.5e	%-30.5e\n", t,series,exact,ext_err,tru_err);								//print out results in fixed format(scientific notation)
			  }			
			}
		terms = -1;
		incre = -1.0;																													//reset terms and increment factor in order to start another computing
		}
	return 0;
	}

