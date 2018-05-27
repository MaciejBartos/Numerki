
#include <vector>

std::vector<double> systemOfEquations(double **matrix, double *x, int n) {
    std::vector<double> solution;
    double variable;
    int numberOfVariables;
    for (int row = n - 1; row >= 0; --row) {
        variable = x[row];
        numberOfVariables = 0;
        while (numberOfVariables < solution.size()) {
            variable -= matrix[row][n - 1 - numberOfVariables] * solution[numberOfVariables];
            numberOfVariables++;
        }
        variable /= matrix[row][row];
        solution.push_back(variable);
    }
    return solution;
}