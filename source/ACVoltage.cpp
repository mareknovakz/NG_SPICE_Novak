#include "ac_voltage.h"
#include <cmath>    // For sin function
#include <stdexcept>

// Implementace metod třídy ACVoltage

ACVoltage::ACVoltage(double voltage, double frequency, int idx) : V(voltage), freq(frequency), index(idx) {
    // Logování při vytvoření instance ACVoltage
    spdlog::info("ACVoltage created with V: {}, freq: {}, index: {}", V, freq, index);
}

void ACVoltage::computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) {
    try {
        if (index < 0 || index >= b.size()) {
            throw std::out_of_range("Index out of range in computeMatrices");
        }

        double angularFreq = 2.0 * M_PI * freq;
        b[index] += V * sin(angularFreq * t);

        // Logování úspěšného výpočtu
        spdlog::info("Computed matrices for ACVoltage at time: {}, dt: {}, V*sin(ωt): {}", t, dt, V * sin(angularFreq * t));
    } catch (const std::exception& e) {
        spdlog::error("Error in computeMatrices: {}", e.what());
    }
}
