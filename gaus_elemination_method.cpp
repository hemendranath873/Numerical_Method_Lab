#include <iostream>
#include <vector>
using namespace std;

// Function to perform Gaussian Elimination
void gaussianElimination(vector<vector<double>> &mat, vector<double> &sol, int n) {
    for (int i = 0; i < n; i++) {
        // Partial Pivoting
        for (int k = i + 1; k < n; k++) {
            if (abs(mat[i][i]) < abs(mat[k][i])) {
                for (int j = 0; j <= n; j++) {
                    swap(mat[i][j], mat[k][j]);
                }
            }
        }

        // Forward Elimination
        for (int k = i + 1; k < n; k++) {
            double t = mat[k][i] / mat[i][i];
            for (int j = 0; j <= n; j++) {
                mat[k][j] -= t * mat[i][j];
            }
        }
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; i--) {
        sol[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            sol[i] -= mat[i][j] * sol[j];
        }
        sol[i] /= mat[i][i];
    }
}

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> mat(n, vector<double>(n + 1));
    vector<double> sol(n);

    cout << "Enter the augmented matrix coefficients (including constants):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    gaussianElimination(mat, sol, n);

    cout << "The solutions are: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << sol[i] << endl;
    }

    return 0;
}

