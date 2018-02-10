#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <cstdio>

using namespace std;

// Initialize Random generator base on machine time
void InitializeRandomGenerator() {
    time_t t;
    srand((unsigned) time(&t));
}

// Exponential distribution random number
double expRandom() {
    double u;
    u = (double) rand() / ((double) RAND_MAX + 1.);
    return -log(1 - u);

}

// Uniform random number between xmin to xmax
void expRandomHistogram(double xmin = 0.0, double xmax = 1.0, int nx = 100, int nRan = 1000000) {
    InitializeRandomGenerator();

    int seed[nx];
    for (int ix = 0; ix < nx; ix++)
        seed[ix] = 0;

    double dx = (xmax - xmin) / ((double) nx);

    for (int iRan = 0; iRan < nRan; iRan++) {
        double x = xmin + (xmax - xmin) * expRandom();
        for (int ix = 0; ix < nx; ix++) {
            if (x >= (xmin + ix * dx) && x < (xmin + (ix + 1) * dx)) {
                seed[ix] = seed[ix] + 1;
                break;
            }
        }
    }

    FILE *OutFile;
    OutFile = fopen("q3_Output.txt", "w");
    for (int ix = 0; ix < nx; ix++) {
		fprintf (OutFile, "%.8f %d : ", xmin + ix*dx, seed[ix]);
        for (int j = 0; j < seed[ix]; j++) {
        	fprintf(OutFile, "*");
    	}	
        fprintf(OutFile, "\n");
    }
    fclose(OutFile);
}


int main() {
    expRandomHistogram(0.0, 100.0);
    return 0;
}
