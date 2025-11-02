#include <iostream>
#include <string>
using namespace std;

class Appliance { // abstract, cannot be instaniated directly
public:
    virtual void use() = 0; // Pure virtual
    virtual ~Appliance() { // virtual destructor
        cout << "Appliance destroyed\n";
    }
};

class Toaster : public Appliance {
private:
    string brand;
public:
    Toaster(string b = "DefaultToaster") : brand(b) {
        cout << "Toaster constructed: " << brand << endl;
    }
    Toaster(const Toaster& rhs) {
        brand = rhs.brand;
        cout << "Toaster copy constructed: " << brand << endl;
    }

    Toaster& operator=(const Toaster& rhs) {
        if (this != &rhs) {
            brand = rhs.brand;
        }
        cout << "Toaster assignment operator: " << brand << endl;
        return *this;
    }

    void use() override {
        cout << "Toasting bread..." << endl;
    }

    ~Toaster() {
        cout << "Toaster destroyed: " << brand << endl;
    }
};

class Blender : public Appliance {
    private:
        int blades;
    public:
        Blender(int b = 4) : blades(b) { // default constructor
            cout << "Blender constructed: " << blades << " blades" << endl;
        }
        Blender(const Blender& rhs) { // copy contructor
            blades = rhs.blades;
            cout << "Blender copy constructed: " << blades << endl;
        }
    
        Blender& operator=(const Blender& rhs) { //  constructor
            if (this != &rhs) {
                blades = rhs.blades;
            }
            cout << "Blender assignment operator: " << blades << endl;
            return *this;
        }
    
        void use() override { // print what I am used for
            cout << "Blending a smoothie..." << endl;
        }
    
        ~Blender() { // destructor
            cout << "Blender destroyed: " << blades << " blades" << endl;
        }
    };

 

int main() {
    const int array_size = 4;
    Appliance* kitchen[array_size]; // what is this doing?  creating appliance pointer of an array of 3 elements
    kitchen[0] = new Toaster("KitchenAid"); // making a new object called toaster of brand Kitchenaid and storing it in the first element of the array
    kitchen[1] = new Blender(5); // creating a new object called blander with 5 blades and storing it in the second element of the array
    kitchen[2] = new Blender; // new object that will use the default constructor
    kitchen[3] = new Toaster("Honda"); // making a new object called toaster of brand Honda and storing it in the first element of the array


    for (int i = 0; i < array_size; ++i) { // looping through the array
        kitchen[i]->use(); // print out what the appliance is used for
    }

    for (int i = 0; i < array_size; ++i) { // looping through the array
        delete kitchen[i];  // Check for proper virtual destructor behavior, destroys the appliances
    }

    return 0;
}