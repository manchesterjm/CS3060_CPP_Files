#include <iostream>   // Includes the input/output stream library for console I/O
using namespace std;  // Brings standard library names (like cout) into the global namespace

// Base class representing a generic shape
class Shape {
public:
    // Virtual method: allows derived classes to override this behavior
    // If a Shape pointer/reference refers to a derived object, the overridden
    // method in the derived class will be called (dynamic dispatch).
    virtual void print() {
        // Default message for generic Shape objects
        cout << "I am a shape, not sure of what type" << endl;
    }
};
    
// Derived class representing a circle, publicly inheriting from Shape
class Circle : public Shape {
public:
    // Override the print() method from Shape to provide Circle-specific output.
    // The virtual keyword is not strictly required here, but it's good practice
    // to repeat it to signal that this method overrides a virtual base method.
    virtual void print() {
        // Message specific to Circle objects
        cout << "I am a circle" << endl;
    }
};
   