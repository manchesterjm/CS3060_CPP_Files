#include <iostream>      // Enables console input/output (std::cout, std::endl)
using namespace std;     // Brings standard library names into global namespace

// --- Non-Virtual Base Class ---
// This class does NOT use virtual functions.
// Derived overrides will NOT be called when using base-class variables or slices.
class Shape_NonVirtual {
private:
    string shapeType;     // Example member data (unused here, but increases object size)
public:
    // Regular (non-virtual) print method.
    // Calls to this are bound at compile time based on the static type.
    void print() {
        cout << "I am a shape_nonvirtual, not sure of what type" << endl;
    }
};

// Derived class from Shape_NonVirtual.
// Defines its own print(), but it will only be used when the static type is Circle_NonVirtual.
class Circle_NonVirtual : public Shape_NonVirtual {
public:
    // This hides Shape_NonVirtual::print, but does not override it polymorphically.
    void print() {
        cout << "I am a circle_nonvirtual" << endl;
    }
};

// --- Virtual Base Class ---
// This class uses a virtual function for print, enabling runtime polymorphism.
class Shape_Virtual {
private:
    string shapeType;     // Member data to illustrate extra space for the vptr + data
public:
    // Virtual print method: sets up a vtable entry for dynamic dispatch.
    virtual void print() {
        cout << "I am a shape_virtual, not sure of what type" << endl;
    }
};

// Derived from Shape_Virtual. Overrides the virtual print() method.
class Circle_Virtual : public Shape_Virtual {
public:
    // 'override' keyword (optional) clarifies intent and lets compiler check correctness.
    void print() override {
        cout << "I am a circle_virtual" << endl;
    }
};

int main()
{
    // Uncommenting these would allow us to measure object sizes:
    // Shape_Virtual s1;
    // Shape_NonVirtual s2;

    /* cout << "Size of object with vPtr is: " << sizeof(s1) << endl;
       cout << "Size of object without vPtr is: " << sizeof(s2) << endl; */

    // Instantiate one object of each derived type
    Circle_Virtual    c1;
    Circle_NonVirtual c2;

    /* Note: The compiler generates a hidden pointer (vptr) inside c1 to
       the virtual table for Shape_Virtual, but you won't see it in code. */

    /* Demo of direct calls on derived objects:
    cout << "Will the circles know their types?" << endl;
    cout << "Circle with the virtual function says:" << endl;
    c1.print();
    cout << "Circle without the virtual function says:" << endl;
    c2.print();
    */

    // --- Object Slicing Example ---
    // Assigning a derived object to a base-class variable slices off the derived part.
    Shape_Virtual    s1 = c1;   // c1 is sliced into plain Shape_Virtual
    Shape_NonVirtual s2 = c2;   // c2 is sliced into plain Shape_NonVirtual

    s1.print();  // Calls Shape_Virtual::print (not Circle_Virtual), due to slicing
    s2.print();  // Calls Shape_NonVirtual::print (Circle_NonVirtual version is ignored)

    // --- Pointer-Based Dispatch (commented out) ---
    // Shape_Virtual *sPtr1 = new Circle_Virtual();
    // Shape_NonVirtual *sPtr2 = new Circle_NonVirtual();
    //
    // sPtr1->print();  // Would call Circle_Virtual::print (dynamic dispatch)
    // sPtr2->print();  // Calls Shape_NonVirtual::print (no dynamic dispatch)

    // --- Reference-Based Dispatch ---
    // References preserve the actual object type.
    Shape_Virtual&     sRef1 = c1;  // Reference to a Circle_Virtual
    Shape_NonVirtual&  sRef2 = c2;  // Reference to a Circle_NonVirtual

    sRef1.print();  // Virtual dispatch: calls Circle_Virtual::print
    sRef2.print();  // No virtual dispatch: calls Shape_NonVirtual::print

    return 0;
}
