#include "ConjugateGradientSolver.h"
#include "spdlog/spdlog.h"
#include <numeric>
#include <cmath>
#include <stdexcept>

std::vector<double> ConjugateGradientSolver::solve(const std::vector<std::vector<double>>& A, const std::vector<double>& b, int maxIterations, double tolerance) {
    int n = b.size();
    std::vector<double> x(n, 0.0);  // Initial guess for the solution
    std::vector<double> r = b;      // Initial residual r = b - A*x, where x is initially zero
    std::vector<double> p = r;      // Initial search direction
    double rsold = std::inner_product(r.begin(), r.end(), r.begin(), 0.0);  // Initial residual norm

    spdlog::info("Starting Conjugate Gradient solver with maxIterations: {}, tolerance: {}", maxIterations, tolerance);

    for (int i = 0; i < maxIterations; ++i) {
        std::vector<double> Ap(n, 0.0);

        // Compute A*p
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                Ap[j] += A[j][k] * p[k];
            }
        }

        // Compute alpha
        double alpha = rsold / std::inner_product(p.begin(), p.end(), Ap.begin(), 0.0);

        // Update solution x and residual r
        for (int j = 0; j < n; ++j) {
            x[j] += alpha * p[j];
            r[j] -= alpha * Ap[j];
        }

        double rsnew = std::inner_product(r.begin(), r.end(), r.begin(), 0.0);  // New residual norm

        // Check for convergence
        if (std::sqrt(rsnew) < tolerance) {
            spdlog::info("Convergence reached after {} iterations with residual: {}", i + 1, std::sqrt(rsnew));
            break;
        }

        // Update search direction
        for (int j = 0; j < n; ++j) {
            p[j] = r[j] + (rsnew / rsold) * p[j];
        }
        rsold = rsnew;
    }

    if (std::sqrt(rsold) >= tolerance) {
        spdlog::warn("Conjugate Gradient solver did not converge after {} iterations. Final residual: {}", maxIterations, std::sqrt(rsold));
    }

    spdlog::info("Conjugate Gradient solver completed with final residual: {}", std::sqrt(rsold));
    return x;
}
