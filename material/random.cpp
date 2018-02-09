#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Initialize Random generator base on machine time
void InitializeRandomGenerator ()
{
	time_t t;
	srand((unsigned) time(&t));	
}

// Uniform random number betwee Zero to One
double RealRandomZeroToOne ()
{
	return (double) rand() / ((double) RAND_MAX + 1.);
}

// Uniform random number between xmin to xmax
void UniformRandomHistogram (double xmin=0.0, double xmax=1.0, int nx=100, int nRan=1000000)
{
	InitializeRandomGenerator ();

	int seed[nx];
	for(int ix=0; ix<nx; ix++)
		seed[ix] = 0;

	double dx = (xmax - xmin) /((double) nx);
	
	for(int iRan=0; iRan<nRan; iRan++)
	{
		double x = xmin + (xmax - xmin)*RealRandomZeroToOne ();
		for(int ix=0; ix<nx; ix++)
		{
			if(x>=(xmin + ix*dx) && x<(xmin + (ix+1)*dx))
			{
				seed[ix] = seed[ix] + 1;
				break;
			}
		}
	}

	FILE * OutFile;
	OutFile = fopen ("Output.txt", "w");
	for(int ix=0; ix<nx; ix++)
	{
		fprintf (OutFile, "%.8f %d\n", xmin + ix*dx, 0);
		fprintf (OutFile, "%.8f %d\n", xmin + ix*dx, seed[ix]);
		fprintf (OutFile, "\n");
	}
	fclose (OutFile);	
}

int main()
{
	UniformRandomHistogram (0.0, 2.0);
	return 0;
}
