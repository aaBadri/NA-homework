#include <iostream>
#include <cmath>

using namespace std;

#define ESP 0.001
#define F(x) (3*x - exp(-x));

int main() {
    int iteration = 1;
    double f1, f2, f0,startLimit, endLimit, half;;

    cout << "\nEnter the value of startLimit , endLimit(the limits within which the root lies): \nlike : 0.25 , 0.27\n";
    cin >> startLimit >> endLimit;
    cout << "\n____________________________________________________________________________________________________";
    cout << "\niteration\tstart\tend\thalf\t\tf0\t\tf1\t\tf2\n";
    cout << "____________________________________________________________________________________________________";
    do {
        half = (startLimit + endLimit) / 2;
        f0 = F(startLimit);
        f1 = F(endLimit);
        f2 = F(half);
        cout << "\n   " << iteration << "\t\t" << startLimit << "\t" << endLimit << "\t" << half << "\t\t" << f0 << "\t"<< f1 << "\t"<< f2;
        if (f0 * f2 < 0) {
            endLimit = half;
        } else {
            startLimit = half;
        }
        iteration++;
    } while (fabs(f2) > ESP);
    cout << "\n____________________________________________________________________________________________________\n";
    cout << "\n Root = " << half<<"\n\n";
    return 0;
}