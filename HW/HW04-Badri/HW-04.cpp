#include<iostream>
#include<cmath>

using namespace std;

double myFunction(double x) {
    return (25 * pow(x, 3)) - (6 * pow(x, 2)) + (7 * x - 88);
}

double integration_rectangular(int n, double a, double b) {
    double step = (b - a) / n;
    double area = 0.0;
    for (int i = 0; i < n; i++)
        area += myFunction(a + (i + 0.5) * step) * step;

    return area;
}

int main() {
    double a = 3, b = 9;
    int n = 30;
    cout << "Enter Initial limit,a (like 3)\n";
    cin >> a;
    cout << "Final limit, b (like 9) \n";
    cin >> b;
    cout << "Enter the number of pieces, n (like 30) \n";
    cin >> n;
    cout << "Integral of this function is = " << integration_rectangular(n, a, b);
}