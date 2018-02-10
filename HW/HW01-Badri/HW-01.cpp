#include <math.h>
#include <iostream>

using namespace std;


double myFunction(double x) {
    return (25 * pow(x, 3)) - (6 * pow(x, 2)) + (7 * x) - 88;
    //return (75 * pow(x, 2)) - (12 * x) + 7; //f'
}

double dfdx_forward(double step, double point) {
    double dfdx_forward = (myFunction(point + step) - myFunction(point)) / step;
    return dfdx_forward;
}

int main() {
    double step = 0.005, point = 3;
    cout << "Enter step (like 0.005): \n";
    cin >> step;
    cout << "Enter x for calculating f'(x) (like 3): \n";
    cin >> point;
    cout << "result = " << dfdx_forward(step, point);
}