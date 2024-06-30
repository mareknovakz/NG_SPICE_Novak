#include "dc_voltage.h"

// Implementace metod třídy DCVoltage

DCVoltage::DCVoltage(double voltage, int idx) : V(voltage), index(idx) {}

void DCVoltage::computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) {
    b[index] += V;
}
