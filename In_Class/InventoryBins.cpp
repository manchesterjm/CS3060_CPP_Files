// Preprocessor directives: These lines include libraries that provide additional functions.
// <iostream> provides input/output stream functionality, like cout and cin.
// <cstdlib> includes general purpose functions, such as conversions from strings to numbers.
// <iomanip> is used for manipulating output formatting (e.g., setw for setting width).
// <string> allows us to use the string data type.
#include <iostream>
#include <cstdlib> // Contains functions for converting strings to numbers.
#include <iomanip>
#include <string>

// Using the standard namespace so that we do not have to prefix std:: before every standard function (like cout, cin, etc.)
using namespace std;

// Constant definition: NUM_BINS is the number of bins in our inventory.
// Using a constant allows for easier changes and better readability.
const int NUM_BINS = 10;

// Struct definition: A struct is a user-defined data type that groups related variables together.
// The InventoryBin struct holds two pieces of data:
// - description: a string describing the part stored in the bin.
// - num: an integer representing the quantity of that part in the bin.
struct InventoryBin
{
    string description;
    int num;
};

// Function prototypes: Declarations for functions that are defined later in the code.
// This tells the compiler about the functions before they are used in main().

// selectBin: Function that takes an array of InventoryBin objects and an integer representing the selected bin index.
// It allows the user to choose an action (add or remove parts) for the chosen bin.
void selectBin(InventoryBin [], int);

// addParts: Function that takes a reference to an InventoryBin and an integer quantity to add.
// It increases the quantity of parts in that bin.
void addParts(InventoryBin&, int);

// removeParts: Function that takes a reference to an InventoryBin and an integer quantity to remove.
// It decreases the quantity of parts in that bin if enough parts exist.
void removeParts(InventoryBin&, int);

// Main function: The entry point of the program.
int main()
{
    int choice;  // Variable to store the user's choice for bin selection.

    // Create an array of InventoryBin objects with NUM_BINS elements.
    // Each element in the array represents one inventory bin with a description and a starting quantity.
    InventoryBin bins[NUM_BINS] = {
        {"valve", 10},
        {"Bearing", 5},
        {"bushing", 15},
        {"coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12}
    };

    // The main loop of the program.
    // The loop will continue until the user enters 0 to exit.
    do
    {
        // Display the current inventory.
        // Loop through each bin (from index 0 to NUM_BINS-1) and display its number, part description, and quantity.
        cout << "\nCurrent Inventory:\n";
        for (int count = 0; count < NUM_BINS; count++)
        {
            // setw(3) sets the width of the output field to 3 characters for better formatting.
            cout << "Bin #" << setw(3) << (count+1);
            cout << ", Part: " << bins[count].description;
            cout << ", Quantity: " << bins[count].num << endl;
        }
        
        // Prompt the user to enter a bin number to update.
        // The user can enter a number from 1 to NUM_BINS, or 0 to exit the program.
        cout << "\nEnter bin number to update (1-" << NUM_BINS << ") or 0 to exit: ";
        cin >> choice;

        // Check for invalid bin number (if the choice is less than 0 or greater than NUM_BINS).
        if (choice < 0 || choice > NUM_BINS)
        {
            cout << "Invalid bin number. Please try again." << endl;
            continue; // Restart the loop if an invalid bin number is entered.
        }

        // If the user enters 0, exit the loop and end the program.
        if (choice == 0)
        {
            cout << "Exiting program." << endl;
            break;
        }

        // Adjust the bin number entered by the user to a 0-based index.
        // (Because array indexing starts at 0, but the user sees bins numbered 1-10.)
        int binIndex = choice - 1;
        
        // Call selectBin to process the selected bin.
        // This function will let the user choose to add or remove parts from the chosen bin.
        selectBin(bins, binIndex);

    } while (choice != 0);
    
    return 0; // End the program successfully.
}

// selectBin function: Allows user to choose an action for the selected bin.
void selectBin(InventoryBin b[], int index)
{
    int action;   // Variable to store the user's action choice (add or remove).
    int quantity; // Variable to store the number of parts to add or remove.

    // Inform the user which bin was selected, showing both the bin number and the part description.
    cout << "\nYou selected Bin #" << (index + 1) << " (" << b[index].description << ")\n";
    
    // Ask the user if they want to add parts (1) or remove parts (2).
    cout << "Enter 1 to add parts, 2 to remove parts: ";
    cin >> action;
    
    // If the user selects 1, prompt them to enter the quantity to add.
    if (action == 1)
    {
        cout << "Enter the number of parts to add: ";
        cin >> quantity;
        // Call addParts function with the selected bin and the specified quantity.
        addParts(b[index], quantity);
    }
    // If the user selects 2, prompt them to enter the quantity to remove.
    else if (action == 2)
    {
        cout << "Enter the number of parts to remove: ";
        cin >> quantity;
        // Call removeParts function with the selected bin and the specified quantity.
        removeParts(b[index], quantity);
    }
    // If the user enters an invalid action, notify them and return to the main menu.
    else
    {
        cout << "Invalid action selected. Returning to main menu.\n";
    }
}

// addParts function: Adds the specified quantity of parts to the bin.
// Uses a reference for the bin parameter so that changes affect the original bin in the array.
void addParts(InventoryBin &bin, int quantity)
{
    // If a negative quantity is provided, do not modify the bin.
    if (quantity < 0)
    {
        cout << "Cannot add a negative quantity. No changes made.\n";
        return;
    }
    // Increase the bin's quantity by the specified number.
    bin.num += quantity;
    // Display the new quantity after addition.
    cout << quantity << " parts added. New quantity: " << bin.num << endl;
}

// removeParts function: Removes the specified quantity of parts from the bin.
// Checks if there are enough parts before removing them.
void removeParts(InventoryBin &bin, int quantity)
{
    // If a negative quantity is provided, do not modify the bin.
    if (quantity < 0)
    {
        cout << "Cannot remove a negative quantity. No changes made.\n";
        return;
    }
    // Check if the quantity to remove is more than what is available.
    if (quantity > bin.num)
    {
        cout << "Cannot remove more parts than available. No changes made.\n";
    }
    else
    {
        // Reduce the bin's quantity by the specified number.
        bin.num -= quantity;
        // Display the new quantity after removal.
        cout << quantity << " parts removed. New quantity: " << bin.num << endl;
    }
}
