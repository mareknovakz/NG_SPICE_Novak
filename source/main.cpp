#include "MatrixGenerator.h"
#include "ConjugateGradientSolver.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "DCVoltage.h"
#include "ACVoltage.h"
#include <iostream>
#include <vector>
#include <fstream>

// Function to write solution vector to a file
void writeSolutionToFile(const std::vector<double>& x, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (size_t i = 0; i < x.size(); ++i) {
        outFile << i << "\t" << x[i] << std::endl;
    }

    outFile.close();
}

int main() {
    // Define circuit elements
    std::vector<CircuitElement*> elements;

    // 1. Smyčka: U_0(240V, 50Hz, sin), R1, R2, R3, C1
    double U0_voltage = 240.0;  // Peak voltage
    double frequency = 50.0;    // Frequency in Hz
    double R1_value = 1000.0;   // 1 kOhm resistor
    double R2_value = 2200.0;   // 2.2 kOhm resistor
    double R3_value = 4700.0;   // 4.7 kOhm resistor
    double C1_value = 1e-6;     // 1 µF capacitor

    elements.push_back(new ACVoltage(U0_voltage, frequency, 0)); // AC voltage source at index 0
    elements.push_back(new Resistor(R1_value, 1));               // Resistor R1 at index 1
    elements.push_back(new Resistor(R2_value, 2));               // Resistor R2 at index 2
    elements.push_back(new Resistor(R3_value, 3));               // Resistor R3 at index 3
    elements.push_back(new Capacitor(C1_value, 4));              // Capacitor C1 at index 4

    // 2. Smyčka: L1
    double L1_value = 0.001;  // 1 mH inductor
    elements.push_back(new Inductor(L1_value, 5));  // Inductor L1 at index 5

    // 3. Smyčka: R4, C1, C2
    double R4_value = 3300.0;   // 3.3 kOhm resistor
    double C2_value = 2e-6;     // 2 µF capacitor
    elements.push_back(new Resistor(R4_value, 6));   // Resistor R4 at index 6
    elements.push_back(new Capacitor(C1_value, 7));  // Capacitor C1 (reused) at index 7
    elements.push_back(new Capacitor(C2_value, 8));  // Capacitor C2 at index 8

    double t_start = 0.0;  // Start time
    double t_end = 0.1;    // End time
    double dt = 0.001;     // Time step

    // Create matrices A and vector b
    int numElements = elements.size();
    std::vector<std::vector<double>> A(numElements, std::vector<double>(numElements, 0.0));  // System matrix
    std::vector<double> b(numElements, 0.0);  // Right-hand side vector

    // Generate matrices A and vector b using MatrixGenerator
    MatrixGenerator matrixGenerator;
    matrixGenerator.generateMatrices(elements, t_start, dt, A, b);

    // Solve the system A * x = b using Conjugate Gradient method
    ConjugateGradientSolver solver;
    std::vector<double> x = solver.solve(A, b);

    // Write solution vector x to a file
    writeSolutionToFile(x, "solution.txt");

    // Clean up dynamically allocated memory
    for (auto& element : elements) {
        delete element;
    }

    // Call Python script to plot the results using matplotlib
    system("python3 plot_results.py");

    return 0;
}
