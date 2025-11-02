/**
 * File: AnimalPolymorphism.cpp
 * Date: April 21, 2025
 * Description: Polymorphism with virtual functions.
 *
 * Demonstrates runtime polymorphism using virtual functions.
 * Shows how derived classes can override base class virtual functions
 * and how polymorphic behavior works with pointers.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Animal base class.
 *
 * Base class for animal hierarchy demonstrating virtual functions
 * and polymorphic behavior.
 */
class Animal {
private:
    string type_;  // Type of animal

public:
    /**
     * Constructor: Create an animal with specified type.
     *
     * @param t Type of animal (default: "Animal")
     */
    Animal(string t = "Animal") : type_(t) { }

    /**
     * Virtual destructor.
     *
     * Required for proper cleanup in polymorphic hierarchies.
     */
    virtual ~Animal() { }

    /**
     * Virtual speak function.
     *
     * Provides default implementation that can be overridden
     * by derived classes for polymorphic behavior.
     */
    virtual void speak() const {
        cout << "Animal Sound" << endl;
    }

    /**
     * Get the animal type.
     *
     * @return Type of the animal
     */
    string getType() const {
        return type_;
    }
};

/**
 * Dog derived class.
 *
 * Represents a dog that overrides the speak() function
 * to provide dog-specific behavior.
 */
class Dog : public Animal {
public:
    /**
     * Constructor: Create a Dog object.
     */
    Dog() : Animal("Dog") { }

    /**
     * Override speak function for dog-specific sound.
     *
     * The override keyword explicitly marks this as an override,
     * helping catch errors at compile time.
     */
    void speak() const override {
        cout << "Woof woof, I'm a dog" << endl;
    }
};

/**
 * Play animal sound polymorphically.
 *
 * Accepts pointer to Animal (base class) but calls the appropriate
 * speak() function based on the actual object type (polymorphism).
 *
 * @param a Pointer to Animal object
 */
void playSound(const Animal* a) {
    a->speak();  // Polymorphic call - actual version depends on object type
}

/**
 * Main function demonstrating polymorphism.
 *
 * Creates Animal and Dog objects, then calls speak() through both
 * direct calls and polymorphic function calls.
 */
int main() {
    Animal a;
    Dog d;
    Animal* ptr = &d;  // Base class pointer to derived class object

    playSound(&a);     // Calls Animal version: "Animal Sound"
    playSound(ptr);    // Calls Dog version: "Woof woof, I'm a dog"

    return 0;
}
