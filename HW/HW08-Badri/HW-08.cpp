#include<bits/stdc++.h>
#include <cmath>

#define ESP 0.001
#define func(x) ((1/x)*exp(-x/100) - 1);
#define derivFunc(x) ((-101) / (100 * x)) * exp((-x) / 100);

using namespace std;
int iteration = 1;

void newtonRaphson(double x) {
    double f, df, h;
    f = func(x);
    df = derivFunc(x);
    h = f / df;
    cout << "\n____________________________________________________________________________________________________";
    cout << "\niteration\tx\t\tf\tf'\n";
    cout << "____________________________________________________________________________________________________";
    cout << "\n   " << iteration << "\t\t" << x << "         " << f << "       " << df;
    while (fabs(h) >= ESP) {
        iteration++;
        f = func(x);
        df = derivFunc(x);
        h = f / df;
        x = x - h;
        cout << "\n   " << iteration << "\t\t" << x << "        " << f << "     " << df;
    }
    cout << "\n\nRoot = " << x;
}

int main() {
    int start;
    cout << "\nEnter the values of startLimit (like 20)\n";
    cin >> start;
    newtonRaphson(start);
    return 0;
}
