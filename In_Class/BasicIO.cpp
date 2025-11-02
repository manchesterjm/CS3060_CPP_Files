/**
 * File: BasicIO.cpp
 * Description: Basic C++ program demonstrating input/output and constants.
 *
 * This program demonstrates fundamental C++ concepts including console I/O,
 * constants, and basic arithmetic operations.
 */

#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14159;  // Mathematical constant for pi

/**
 * Main function demonstrating basic I/O and calculations.
 *
 * Prompts user for input, performs calculation with PI constant,
 * and displays the result.
 */
int main() {
    cout << "hello\n";

    double s;
    cin >> s;

    cout << "You entered: " << s << endl;
    cout << PI * s << endl;

    return 0;
}
