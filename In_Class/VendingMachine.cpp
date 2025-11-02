#include <iostream>   // For cin, cout, etc.
#include <cstdlib>    // For functions like atof, atoi, etc. (though not used here)
#include <iomanip>    // For output formatting (fixed, setprecision, etc.)
#include <string>     // For using the C++ string type

using namespace std;

// ----------------------------------------------------
//               CONSTANTS AND STRUCT
// ----------------------------------------------------

// NUM_DRINKS is the total number of different drinks in the machine.
// By using a constant, we can easily change it later without editing code elsewhere.
const int NUM_DRINKS = 5;

// The Drink struct holds data for a single type of drink:
//  - name: The name of the drink
//  - cost: The cost of one drink
//  - num:  How many of that drink are left in the machine
struct Drink
{
    string name;
    double cost;
    int num;
};

// ----------------------------------------------------
//               FUNCTION PROTOTYPES
// ----------------------------------------------------
// 1) getChoice: Displays a menu of drinks, reads the user’s choice, 
//    validates the choice, and returns the chosen index in the array.
//
// 2) transaction: Processes a single transaction based on the user’s choice. 
//    It updates the machine’s stock and the total earnings.
int getChoice(Drink[]);
void transaction(Drink[], int, double&);

// ----------------------------------------------------
//                     MAIN
// ----------------------------------------------------
int main()
{
    // choice will hold the user’s menu choice, represented as an array index (0-based).
    int choice;

    // earnings will track how much money the drink machine has earned overall.
    double earnings = 0;

    // Initialize an array of Drink structures to represent the machine’s inventory.
    // Each array element corresponds to one drink type.
    Drink machine[NUM_DRINKS] = {
        {"Cola      ", 0.75, 20},
        {"Root beer ", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.75, 20},
        {"Cream Soda", 0.75, 20}
    };

    // Format floating-point output to always show two decimals (e.g., 0.75).
    cout << fixed << showpoint << setprecision(2);

    // Display the menu and get the user's first choice.
    choice = getChoice(machine);

    // Loop until the user selects the "Leave the drink machine" option.
    // In getChoice, if the user chooses the last menu item (which is option 6),
    // we return 5, so we keep looping while choice != 5.
    while (choice != 5)
    {
        // Process the transaction for the chosen drink.
        // Note: 'earnings' is passed by reference, so transaction() can update it.
        transaction(machine, choice, earnings);

        // Get the next choice from the user.
        choice = getChoice(machine);
    }

    // When the user chooses to leave (choice == 5), we display total earnings and exit.
    cout << "Total earnings: $" << earnings << endl;

    return 0; // Indicate successful program termination.
}

// ----------------------------------------------------
//                  getChoice FUNCTION
// ----------------------------------------------------
int getChoice(Drink m[])
{
    int choice;  // Will store the user’s 1-based menu selection.

    cout << endl;  // Print a blank line for readability.

    // Display the list of drinks.
    // We use a for loop that runs from 0 to NUM_DRINKS-1.
    // x+1 is printed so the menu is user-friendly (1-based).
    for (int x = 0; x < NUM_DRINKS; x++)
    {
        cout << (x + 1) << ") " << m[x].name << "\t\t"
             << m[x].cost << endl;
    }

    // Display the last menu item, which is the option to leave the machine.
    cout << (NUM_DRINKS + 1) << ") Leave the drink machine\n\n";

    // Prompt the user for their choice.
    cout << "Choose one: ";
    cin >> choice;

    // Validate the choice to ensure it's between 1 and 6 (inclusive).
    // If it's outside that range, we prompt again.
    while (choice < 1 || choice > (NUM_DRINKS + 1))
    {
        cout << "Bad choice, please choose again: ";
        cin >> choice;
    }

    // We return choice - 1 so that:
    //    1 -> 0 (first drink in the array)
    //    2 -> 1 (second drink in the array)
    //    ...
    //    5 -> 4 (fifth drink in the array)
    //    6 -> 5 (this is the 'Leave the machine' option)
    return choice - 1;
}

// ----------------------------------------------------
//               transaction FUNCTION
// ----------------------------------------------------
void transaction(Drink m[], int choice, double &earnings)
{
    // This variable holds the amount of money the user enters.
    double money;

    // If the selected drink is sold out, we display a message and exit the function immediately.
    // 'return;' here means "stop executing transaction() and go back to the caller."
    if (m[choice].num == 0)
    {
        cout << "That drink is sold out. Please choose another.\n\n";
        return;
    }

    // Ask the user for money. We’ll validate that it’s at least the cost of the drink
    // and no more than $1.00 (as per your professor's instructions).
    cout << "Enter an amount of money: ";
    cin >> money;

    // Validate the amount of money. We use a while loop so that if the user’s entry is invalid,
    // we keep asking until they enter something acceptable.
    while (money < m[choice].cost || money > 1.0)
    {
        cout << "Enter at least $" << m[choice].cost
             << " and not more than $1.00.\n";
        cin >> money;
    }

    // At this point, money is guaranteed to be between cost and 1.0.

    // If the user entered enough money (which should be true at this point),
    // we display a "dispensing drink" message.
    // The code "if (money >= m[choice].cost)" is still valid logic 
    // even though we already validated in the while loop.
    if (money >= m[choice].cost)
    {
        cout << "\nThump, thump, thump, splat!\n"
             << "Enjoy your drink!\n\n";
    }

    // Calculate the change due to the customer.
    double change = money - m[choice].cost;

    // Display how much change we calculated.
    cout << "Change calculated: $" << change << endl;

    // If there is change, we give it back (in a real machine, it would dispense coins).
    if (change > 0)
    {
        cout << "Your change, $" << change << ", just dropped into the Change Dispenser.\n";
    }

    // Update our earnings by adding the cost of the drink to the machine's total.
    earnings += m[choice].cost;

    // Decrease the number of drinks left in the machine for the selected type by 1.
    m[choice].num--;

    // Display how many drinks of that type remain.
    cout << "There are now " << m[choice].num << " drink(s) of " 
         << m[choice].name << " left.\n\n";
}
