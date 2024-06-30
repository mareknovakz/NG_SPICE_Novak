#ifndef CONJUGATE_GRADIENT_SOLVER_H
#define CONJUGATE_GRADIENT_SOLVER_H

#include <vector>

class ConjugateGradientSolver {
public:
    std::vector<double> solve(const std::vector<std::vector<double>>& A, const std::vector<double>& b, int maxIterations = 1000, double tolerance = 1e-10);
};

#endif // CONJUGATE_GRADIENT_SOLVER_H
