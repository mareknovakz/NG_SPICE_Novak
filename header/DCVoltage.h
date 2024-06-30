#ifndef DC_VOLTAGE_H
#define DC_VOLTAGE_H

#include "CircuitElement.h"

// DCVoltage class
class DCVoltage : public CircuitElement {
    double V;   // Voltage value
    int index;  // Index in the matrix
public:
    DCVoltage(double voltage, int idx);
    void computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) override;
};

#endif // DC_VOLTAGE_H
