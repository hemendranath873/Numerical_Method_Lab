#include <iostream>
#include <cmath>
using namespace std;

// Define the function for which we need to find the root
double func(double x) {
    // Example: f(x) = x^3 - x - 2
    return x * x * x - x - 2;
}

// Function to find the root using Bisection Method
void bisection(double a, double b, double tolerance) {
    if (func(a) * func(b) >= 0) {
        cout << "You have not assumed the right a and b." << endl;
        return;
    }

    double c = a; // Initialize c

    while ((b - a) >= tolerance) {
        // Find the middle point
        c = (a + b) / 2;

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
    double a = 1, b = 2;
    double tolerance = 0.0001;

    bisection(a, b, tolerance);
    return 0;
}

