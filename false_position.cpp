#include <iostream>
#include <cmath>
using namespace std;

// Define the function for which we need to find the root
double func(double x) {
    // Example: f(x) = x^2 - 4
    return x*x - 4;
}

// Function to find the root using False Position Method
void falsePosition(double a, double b, double tolerance) {
    if (func(a) * func(b) >= 0) {
        cout << "You have not assumed the right a and b." << endl;
        return;
    }

    double c = a; // Initialize c

    while ((b - a) >= tolerance) {
        // Find the point that touches the x-axis
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        // Check if c is the root
        if (func(c) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;

        cout << "Current approximation of the root: " << c << endl;
    }

    cout << "The root is: " << c << endl;
}

int main() {
    // Initial values assumed
    double a = 0, b = 3;
    double tolerance = 0.0001;

    falsePosition(a, b, tolerance);
    return 0;
}
