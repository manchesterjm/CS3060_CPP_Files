/**
 * File: RationalNumber.cpp
 * Date: April 9, 2025
 * Description: Rational number class with operator overloading.
 *
 * Demonstrates operator overloading using both member functions and
 * friend functions. Shows how to enable operations between Rational
 * objects and between integers and Rational objects.
 */

#include <iostream>

using namespace std;

/**
 * Rational class represents a rational number (fraction).
 *
 * Stores numerator and denominator, provides operator overloading
 * for arithmetic operations, and supports mixed-type operations
 * with integers.
 */
class Rational {
private:
    int numerator_;     // Numerator of the fraction
    int denominator_;   // Denominator of the fraction

public:
    /**
     * Constructor: Create a rational number.
     *
     * @param numerator Numerator value (default: 0)
     * @param denominator Denominator value (default: 1)
     */
    Rational(int numerator = 0, int denominator = 1)
        : numerator_(numerator), denominator_(denominator) { }

    /**
     * Overload + operator for Rational + Rational.
     *
     * Member function allows addition of two Rational objects.
     *
     * @param rhs Right-hand side Rational operand
     * @return New Rational representing the sum
     */
    Rational operator+(const Rational& rhs) const {
        return Rational(
            numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_,
            denominator_ * rhs.denominator_
        );
    }

    /**
     * Friend function for int + Rational operation.
     *
     * Allows integer to be added to Rational (e.g., 2 + Rational(1, 3)).
     */
    friend Rational operator+(int lhs, const Rational& rhs);

    /**
     * Print the rational number.
     *
     * Displays in numerator/denominator format.
     */
    void print() const {
        cout << numerator_ << "/" << denominator_ << endl;
    }
};

/**
 * Friend function: Overload + operator for int + Rational.
 *
 * Enables integer to be on the left side of addition with Rational.
 *
 * @param lhs Left-hand side integer operand
 * @param rhs Right-hand side Rational operand
 * @return New Rational representing the sum
 */
Rational operator+(int lhs, const Rational& rhs) {
    return Rational(
        lhs * rhs.denominator_ + rhs.numerator_,
        rhs.denominator_
    );
}

/**
 * Main function demonstrating operator overloading.
 *
 * Shows usage of both member function operator overload (Rational + Rational)
 * and friend function operator overload (int + Rational).
 */
int main() {
    Rational a(1, 2);  // 1/2
    Rational b(1, 3);  // 1/3

    // Calls member function: Rational + Rational
    Rational c = a + b;
    cout << "a + b = ";
    c.print();  // Output: 5/6

    // Calls friend function: int + Rational
    Rational d = 2 + b;
    cout << "2 + b = ";
    d.print();  // Output: 7/3

    return 0;
}
