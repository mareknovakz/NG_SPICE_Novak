#ifndef RESISTOR_H
#define RESISTOR_H

#include "CircuitElement.h"
#include "spdlog/spdlog.h"

// Resistor class
class Resistor : public CircuitElement {
    double R;   // Resistance value
    int index;  // Index in the matrix
public:
    Resistor(double resistance, int idx);
    void computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) override;
};

#endif // RESISTOR_H
