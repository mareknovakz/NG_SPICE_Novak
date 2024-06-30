#ifndef AC_VOLTAGE_H
#define AC_VOLTAGE_H

#include "CircuitElement.h"
#include "spdlog/spdlog.h"

// ACVoltage class
class ACVoltage : public CircuitElement {
    double V;       // Peak voltage value
    double freq;    // Frequency of the AC voltage
    int index;      // Index in the matrix
public:
    ACVoltage(double voltage, double frequency, int idx);
    void computeMatrices(double t, double dt, std::vector<std::vector<double>>& A, std::vector<double>& b) override;
};

#endif // AC_VOLTAGE_H
