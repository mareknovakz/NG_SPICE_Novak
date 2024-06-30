#include "inductor.h"
#include <stdexcept>

// Implementace metod třídy Inductor

Inductor::Inductor(double inductance, int idx) : L(inductance), index(idx) {
    // Logování při vytvoření instance Inductor
    spdlog::info("Inductor created with L: {}, index: {}", L, index);
}

void Inductor::computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) {
    try {
        if (index < 0 || index >= A.size()) {
            throw std::out_of_range("Index out of range in computeMatrices");
        }

        A[index][index] += L / (dt * dt);

        // Logování úspěšného výpočtu
        spdlog::info("Computed matrices for Inductor at time: {}, dt: {}, L/(dt*dt): {}", t, dt, L / (dt * dt));
    } catch (const std::exception& e) {
        spdlog::error("Error in computeMatrices: {}", e.what());
    }
}
