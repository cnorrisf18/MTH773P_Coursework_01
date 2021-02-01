#include "stats.h"
#include <iostream>
#include <random>
using namespace std;

int main()
{
	
	Stats1 OurStats;
	srand(time(NULL));
	//default_random_engine generator;
	//uniform_real_distribution<double> distribution(0.0, 1.0);
	for (int i = 0; i < 10000; ++i)
	{
		double randomnumber = rand() / double(RAND_MAX);
		OurStats.add(randomnumber);
		//cout << randomnumber;
		//double number = distribution(generator);
		//OurStats.add(number);
	}
	cout << "The mean is " << OurStats.mean() << endl;
	cout << "The expected mean according to uniform distribution is .5" << endl;
	cout << "The standard deviation is " << OurStats.stDev() << endl;
	cout << "The expected standard deviation according to uniform distribution is " << sqrt(1.0 / 12.0) << endl;
	// the values returned are within a few decimal points of the expected values, which we can 
	// attribute to the random aspect of it. So the class looks like it works
	

	Stats2 FitALine;
	FitALine.add(1, 16);
	FitALine.add(2, 11);
	FitALine.add(3, 9);
	FitALine.add(4, 3);
	FitALine.add(5, 2);
	cout << "Calculated fit of the data is y = " << FitALine.m << "x + " << FitALine.c << endl;
	cout << "R squared is " << FitALine.rsquared << endl;

	NormalRandomGenerator Rgen;
	Stats1 BoxStats;
	for (int i = 0; i < 100000; ++i)
	{
		double inumber = Rgen.generate();
		BoxStats.add(inumber);
		//cout << BoxStats.sumofnumbers << endl;
	}
	//cout << "Length is " << BoxStats.length << endl;
	//cout << "Sum is " << BoxStats.sumofnumbers << endl;
	cout << "The mean of Box-Muller is " << BoxStats.mean() << endl;
	cout << "The standard deviation of Box-Muller is " << BoxStats.stDev() << endl;
	//The expected mean of standard normal distribution is 0, and the expected standard deviation is 1. 
	//This code regularly comes with values within a few decimal points of the expected values,
	//so it seems to work
}