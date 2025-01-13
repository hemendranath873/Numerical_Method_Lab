#include <iostream>
using namespace std;

// Function to calculate the Lagrange Interpolation
double lagrangeInterpolation(double x[], double y[], int n, double xp) {
    double result = 0; // Initialize result

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[n], y[n];
    cout << "Enter the data points (x and y):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double xp;
    cout << "Enter the value of x for which y is required: ";
    cin >> xp;

    double yp = lagrangeInterpolation(x, y, n, xp);
    cout << "The interpolated value at x = " << xp << " is " << yp << endl;

    return 0;
}

