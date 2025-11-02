/**
 * File: KineticEnergy.cpp
 * Date: January 29, 2025
 * Description: Calculate kinetic energy using mass and velocity.
 *
 * This program demonstrates function usage, input validation, and
 * formatted output using iomanip for calculating kinetic energy.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Calculate kinetic energy.
 *
 * Computes kinetic energy using the formula: KE = 0.5 * mass * velocity^2
 *
 * @param mass Mass in kilograms
 * @param vel Velocity in meters per second
 * @return Kinetic energy in joules
 */
double getKineticEnergy(double mass, double vel) {
    return 0.5 * mass * vel * vel;  // KE = 1/2 * m * v^2
}

/**
 * Main function to get user input and calculate kinetic energy.
 *
 * Prompts user for mass and velocity, then calculates and displays
 * the kinetic energy with one decimal place precision.
 */
int main() {
    double mass, velocity;

    // Get mass from user
    cout << "Enter Mass in KG: ";
    cin >> mass;

    // Get velocity from user
    cout << "Enter Velocity in Meter per Second: ";
    cin >> velocity;

    // Calculate and display energy with formatting
    cout << fixed << showpoint << setprecision(1)
         << "Energy is: " << getKineticEnergy(mass, velocity) << endl;

    return 0;
}
