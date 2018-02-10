#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include<iomanip>

using namespace std;

double linear_fit(double x[], double y[], int number) {
    double x_sum = 0, x2_sum = 0, y_sum = 0, xy_sum = 0, m = 0, b = 0;
    for (int i = 0; i < number; i++) {
        x_sum = x_sum + x[i];
        y_sum = y_sum + y[i];
        x2_sum = x2_sum + pow(x[i], 2);
        xy_sum = xy_sum + x[i] * y[i];
    }
    m = (number * xy_sum - x_sum * y_sum) / (number * x2_sum - x_sum * x_sum);
    b = (x2_sum * y_sum - x_sum * xy_sum) / (x2_sum * number - x_sum * x_sum);
    cout << "\nThe best fit line is : " << m << "x + " << b << endl;
}

int main() {
    int arr_size = 51;
    ifstream fin("D2.txt");

    cout << "Please enter number of points [if you just enter , default is = 51]: \n";
    string input;
    getline(cin, input);
    if (!input.empty())
        stringstream(input) >> arr_size;
    double x_arr[arr_size], y_arr[arr_size];

    for (int i = 0; i < arr_size; ++i)
        fin >> x_arr[i] >> y_arr[i];

    linear_fit(x_arr, y_arr, arr_size);
    return 0;
}

