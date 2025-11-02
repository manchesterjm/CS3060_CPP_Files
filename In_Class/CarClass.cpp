/**
 * File: CarClass.cpp
 * Description: Car class implementation demonstrating OOP principles.
 *
 * This program implements a Car class with attributes for year model, make,
 * and speed. Demonstrates constructors, getters/setters, and member functions
 * for accelerating and braking.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Car class represents a vehicle with basic attributes and operations.
 *
 * Provides functionality to track and modify car's year model, make,
 * and current speed. Supports acceleration and braking operations.
 */
class Car {
private:
    int yearModel_;  // Car's year model
    string make_;    // Car's make (manufacturer)
    int speed_;      // Current speed in mph

public:
    /**
     * Constructor: Initialize car with year model and make.
     *
     * @param yrModel Year model of the car
     * @param mk Make/manufacturer of the car
     */
    Car(int yrModel, string mk) : yearModel_(yrModel), make_(mk), speed_(0) { }

    // Setters

    /**
     * Set the car's year model.
     *
     * @param yrModel New year model
     */
    void setModel(int yrModel) {
        yearModel_ = yrModel;
    }

    /**
     * Set the car's make.
     *
     * @param mk New make/manufacturer
     */
    void setMake(string mk) {
        make_ = mk;
    }

    /**
     * Set the car's current speed.
     *
     * @param spd New speed value
     */
    void setSpeed(int spd) {
        speed_ = spd;
    }

    // Getters

    /**
     * Get the car's year model.
     *
     * @return Year model of the car
     */
    int getYearModel() const {
        return yearModel_;
    }

    /**
     * Get the car's make.
     *
     * @return Make/manufacturer of the car
     */
    string getMake() const {
        return make_;
    }

    /**
     * Get the car's current speed.
     *
     * @return Current speed in mph
     */
    int getSpeed() const {
        return speed_;
    }

    // Member functions

    /**
     * Accelerate the car by 5 mph.
     */
    void accelerate() {
        speed_ += 5;
    }

    /**
     * Brake the car by 5 mph.
     */
    void brake() {
        speed_ -= 5;
    }
};

/**
 * Main function demonstrating Car class usage.
 *
 * Creates a Car object and demonstrates acceleration and braking
 * by displaying speed changes.
 */
int main() {
    Car car(2013, "Honda");  // Create a 2013 Honda

    // Accelerate 5 times and display speed after each
    for (int i = 0; i < 5; i++) {
        car.accelerate();
        cout << "Current speed: " << car.getSpeed() << endl;
    }

    // Brake 5 times and display speed after each
    for (int i = 0; i < 5; i++) {
        car.brake();
        cout << "Current speed: " << car.getSpeed() << endl;
    }

    return 0;
}
