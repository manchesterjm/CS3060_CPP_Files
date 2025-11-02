/**
 * File: InheritanceBigThree.cpp
 * Date: April 21, 2025
 * Description: Inheritance with Big Three (copy constructor, copy assignment, destructor).
 *
 * Demonstrates proper implementation of the Big Three in both base and derived
 * classes. Shows how derived classes must call base class constructors and
 * assignment operators.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Instrument base class.
 *
 * Represents a musical instrument with type attribute.
 * Demonstrates Big Three implementation for base class.
 */
class Instrument {
private:
    string type_;  // Type of instrument

public:
    /**
     * Constructor: Create an instrument with specified type.
     *
     * @param t Type of the instrument
     */
    Instrument(string t) : type_(t) {
        cout << "Instrument constructor called\n";
    }

    /**
     * Copy constructor: Create instrument from another.
     *
     * @param rhs Source Instrument to copy from
     */
    Instrument(const Instrument& rhs) : type_(rhs.type_) {
        cout << "Instrument copy constructor called\n";
    }

    /**
     * Copy assignment operator.
     *
     * @param rhs Source Instrument to assign from
     * @return Reference to this object
     */
    Instrument& operator=(const Instrument& rhs) {
        cout << "Instrument assignment operator called\n";
        if (this != &rhs) {  // Check for self-assignment
            type_ = rhs.type_;
        }
        return *this;
    }

    /**
     * Get the instrument type.
     *
     * @return Type of the instrument
     */
    string getType() const {
        return type_;
    }
};

/**
 * Guitar derived class.
 *
 * Represents a guitar instrument with number of strings.
 * Demonstrates Big Three implementation in derived class.
 */
class Guitar : public Instrument {
private:
    int strings_;  // Number of strings on the guitar

public:
    /**
     * Constructor: Create a guitar with type and string count.
     *
     * @param t Type of guitar (e.g., "Electric", "Acoustic")
     * @param s Number of strings
     */
    Guitar(string t, int s) : Instrument(t), strings_(s) {
        cout << "Guitar constructor called\n";
    }

    /**
     * Copy constructor: Create guitar from another.
     *
     * Must call base class copy constructor explicitly.
     *
     * @param rhs Source Guitar to copy from
     */
    Guitar(const Guitar& rhs) : Instrument(rhs), strings_(rhs.strings_) {
        cout << "Guitar copy constructor called\n";
    }

    /**
     * Copy assignment operator.
     *
     * Must call base class assignment operator explicitly.
     *
     * @param rhs Source Guitar to assign from
     * @return Reference to this object
     */
    Guitar& operator=(const Guitar& rhs) {
        cout << "Guitar assignment operator called\n";
        if (this != &rhs) {  // Check for self-assignment
            Instrument::operator=(rhs);  // Call base class assignment
            strings_ = rhs.strings_;
        }
        return *this;
    }

    /**
     * Get the number of strings.
     *
     * @return Number of strings on the guitar
     */
    int getStrings() const {
        return strings_;
    }
};

/**
 * Main function demonstrating Big Three with inheritance.
 *
 * Creates Guitar objects and demonstrates copy construction and
 * assignment operations, showing the order of constructor/operator calls.
 */
int main() {
    Guitar g1("Electric", 6);  // Regular constructor
    Guitar g2 = g1;            // Copy constructor
    Guitar g3("Acoustic", 12); // Regular constructor
    g3 = g1;                   // Assignment operator

    return 0;
}
