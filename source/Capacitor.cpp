#include "capacitor.h"
#include <stdexcept>

// Implementace metod třídy Capacitor

Capacitor::Capacitor(double capacitance, int idx) : C(capacitance), index(idx) {
    // Logování při vytvoření instance Capacitor
    spdlog::info("Capacitor created with C: {}, index: {}", C, index);
}

void Capacitor::computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) {
    try {
        if (index < 0 || index >= A.size()) {
            throw std::out_of_range("Index out of range in computeMatrices");
        }

        A[index][index] += C / dt;

        // Logování úspěšného výpočtu
        spdlog::info("Computed matrices for Capacitor at time: {}, dt: {}, C/dt: {}", t, dt, C / dt);
    } catch (const std::exception& e) {
        spdlog::error("Error in computeMatrices: {}", e.what());
    }
}
