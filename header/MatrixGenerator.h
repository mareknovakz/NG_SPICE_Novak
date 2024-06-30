#ifndef MATRIX_GENERATOR_H
#define MATRIX_GENERATOR_H

#include <vector>
#include "CircuitElement.h"

class MatrixGenerator {
public:
    void generateMatrices(std::vector<CircuitElement*>& elements, double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b);
};

#endif // MATRIX_GENERATOR_H
