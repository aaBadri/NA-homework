#include<iostream>
#include<cmath>

using namespace std;

double myFunction(double x) {
    return (25 * pow(x, 3)) - (6 * pow(x, 2)) + (7 * x - 88);
}

double integration_simpson(int n, double a, double b) {
    double step, sum = 0, integral, x[n + 1], y[n + 1];
    step = (b - a) / n;
    for (int i = 0; i < n + 1; i++) {
        x[i] = a + i * step;
        y[i] = myFunction(x[i]);
    }
    for (int i = 1; i < n; i += 2)
        sum = sum + 4.0 * y[i];
    for (int i = 2; i < n - 1; i += 2)
        sum = sum + 2.0 * y[i];
    integral = step / 3.0 * (y[0] + y[n] + sum);
    return integral;
}

int main() {
    double a = 3, b = 9;
    int n = 30;
    cout << "Enter Initial limit,a (like 3) \n";
    cin >> a;
    cout << "Final limit, b (like 9) \n";
    cin >> b;
    cout << "Enter the number of pieces, n (like 30) \n";
    cin >> n;
    cout << "Integral of this function is = " << integration_simpson(n, a, b);
}