#ifndef CIRCUIT_ELEMENT_H
#define CIRCUIT_ELEMENT_H

#include <vector>

// Base class for circuit elements
class CircuitElement {
public:
    // Virtual method to compute matrices, to be overridden by derived classes
    virtual void computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) = 0;
};

#endif // CIRCUIT_ELEMENT_H
