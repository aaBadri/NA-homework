#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

double interpolate(double x[], double y[], double point, int number) {
    double result = 0;
    for (int i = 0; i < number; i++) {
        double y_temp = y[i];
        for (int j = 0; j < number; j++){
		
            if (j != i)
                y_temp = y_temp * (point - x[j]) / double(x[i] - x[j]);
		}
        result += y_temp;
    }
    return result;
}

int main() {
    int arr_size = 26;
    ifstream fin("D1.txt");
    if (!fin.is_open()) {
        cerr << "Unable to open file D1.txt";
        exit(1);
    }
    cout << "Please enter number of points [if you just enter , default is 26]: \n";
    string input;
    getline(cin, input);
    if (!input.empty())
        stringstream(input) >> arr_size;
    double x_arr[arr_size],y_arr[arr_size];
    
    for (int i = 0; i < arr_size; ++i) 
    	fin >> x_arr[i] >> y_arr[i];
    for (int i = 0; i < arr_size; ++i)
        cout << x_arr[i] << y_arr[i];
    cout << "f(3.1) = " << interpolate(x_arr, y_arr, 3.1, arr_size);
    return 0;
}
