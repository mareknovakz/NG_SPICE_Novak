#include "MatrixGenerator.h"

void MatrixGenerator::generateMatrices(std::vector<CircuitElement*>& elements, double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) {
    for (auto& element : elements) {
        element->computeMatrices(t, dt, A, b);
    }
}
