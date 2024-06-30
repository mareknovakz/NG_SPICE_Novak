#ifndef INDUCTOR_H
#define INDUCTOR_H

#include "CircuitElement.h"
#include "spdlog/spdlog.h"

// Inductor class
class Inductor : public CircuitElement {
    double L;   // Inductance value
    int index;  // Index in the matrix
public:
    Inductor(double inductance, int idx);
    void computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) override;
};

#endif // INDUCTOR_H
