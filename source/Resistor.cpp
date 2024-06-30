#include "resistor.h"
#include <stdexcept>

// Implementace metod třídy Resistor

Resistor::Resistor(double resistance, int idx) : R(resistance), index(idx) {
    // Logování při vytvoření instance Resistor
    spdlog::info("Resistor created with R: {}, index: {}", R, index);
}

void Resistor::computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) {
    try {
        if (index < 0 || index >= A.size()) {
            throw std::out_of_range("Index out of range in computeMatrices");
        }

        A[index][index] += 1.0 / R;

        // Logování úspěšného výpočtu
        spdlog::info("Computed matrices for Resistor at time: {}, dt: {}, 1/R: {}", t, dt, 1.0 / R);
    } catch (const std::exception& e) {
        spdlog::error("Error in computeMatrices: {}", e.what());
    }
}
