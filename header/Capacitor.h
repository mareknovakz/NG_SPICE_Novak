#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "CircuitElement.h"
#include "spdlog/spdlog.h"

// Capacitor class
class Capacitor : public CircuitElement {
    double C;   // Capacitance value
    int index;  // Index in the matrix
public:
    Capacitor(double capacitance, int idx);
    void computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) override;
};

#endif // CAPACITOR_H
