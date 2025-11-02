/*
   Name: Josh Manchester
   Class: CS3060
   Professor: Rory Lewis

   Monkey Business

   A local zoo wants to keep track of how many pounds of food each of its three monkeys 
   eats each day during a typical week. Write a program that stores this information 
   in a two-dimensional 3 × 5 array, where each row represents a different monkey, and 
   each column represents a different day of the week. The program should first have the 
   user input the data for each monkey. Then, it should create a report that includes the 
   following information:

   - Average amount of food eaten per day by the whole family of monkeys.
   - The least amount of food eaten during the week by any one monkey.
   - The greatest amount of food eaten during the week by any one monkey.

   Input Validation: 
   Do not accept negative numbers for pounds of food eaten.
*/

#include <iostream> // allows communications to the console
// #include <string> // allows you to use strings, not needed here
#include <iomanip> // allows use to manipulate our output to look nice
// #include <array> // allows the use of arrays, not needed here
// #include <vector> // dynamic lists, not needed here

using namespace std; // allows us to avoid having to do std::cin and std::cout

// CONSTANTS

const int MONKEY = 3;
const int DAYS = 5;

// FUNCTION PROTOTYPES

void getFoodEaten(double[][DAYS]); // gets food eaten for each monkey/day from the user
void displayAverageDaily(double[][DAYS]); // displays the average food eaten per day by all monkeys
void displayLeastEaten(double[][DAYS]); // finds and displays which monkey/day had the least food eaten
void displayMostEaten(double[][DAYS]); // finds and displays which monkey/day had the most food eaten

// MAIN

int main()
    {
        double food[MONKEY][DAYS] = {{0}}; // declare 3x5 array of double and initialize all elements to 0
        getFoodEaten(food); // when passing an array it is passed as a pointer already, so no need to add *
        cout << "Report on food eaten by monkeys" << endl;
        cout << "-------------------------------\n\n";
        displayAverageDaily(food); // displays the avg daily amount of food that is consumed by all monkeys per day
        displayLeastEaten(food); // displays which monkey/day had the least food
        displayMostEaten(food); // displays which monkey/day had the most food
        return 0;
    }

// FUNCTIONS

void getFoodEaten(double arr[][DAYS])
    {
        // loop through the array by finding a monkey and looping through the days then move to the next monkey
        for (int monkey = 0; monkey < MONKEY; monkey++) // each row is a monkey
            {
                for(int day = 0; day < DAYS; day++) // each col is the food amount in pounds
                    {
                        cout << "Enter the food eaten for Monkey " << monkey+1
                            << " on Day " << day+1 << ": "; // ask question
                        cin >> arr[monkey][day]; // get user input and store in the array
                        while (arr[monkey][day] < 0) // input validation per assignment requirements
                            {
                                cout << "You have entered a negative number, please re-enter: ";
                                cin >> arr[monkey][day];
                            }
                    }
                cout << endl;
            }
    }

void displayAverageDaily(double arr[][DAYS])
    {
        double avg = 0;
        for (int col = 0; col < DAYS; col++) // loop through each day (col)
            {
                for (int row = 0; row < MONKEY; row++) // loop through each monkey (row)
                    {
                        avg += arr[row][col]; // add food amount for current monkey/day
                    }
                    cout << fixed << setprecision(2)
                        << "Avg food eaten on day " << col+1 << ": " << avg/MONKEY << " lbs" << endl; // display average for day
                    avg = 0; // reset avg for next day
            }
        cout << endl;
    }

void displayLeastEaten(double arr[][DAYS])
    {
        double least = arr[0][0]; // initialize least to first element in the 2d array
        int monkey = 0;
        int day = 0;
        for (int row = 0; row < MONKEY; row++) // loop through each monkey
            {
                for (int col = 0; col < DAYS; col++) // loop through each day
                    {
                        if (arr[row][col] < least) // if current food amount is less than least
                            {
                                least = arr[row][col]; // update least food amount
                                monkey = row; // update monkey index
                                day = col; // update day index
                            }
                    }
            }
        cout << fixed << setprecision(2)
            << "Monkey: " << monkey+1
            << " ate the least food: "
            << least << " lbs on day: "
            << day+1 << endl; // display monkey/day with least food eaten
    }

void displayMostEaten(double arr[][DAYS])
    {
        double most = 0;
        int monkey = 0;
        int day = 0;
        for (int row = 0; row < MONKEY; row++) // loop through each monkey
            {
                for (int col = 0; col < DAYS; col++) // loop through each day
                    {
                        if (arr[row][col] > most) // if current food amount is greater than what is currently in most do
                            {
                                most = arr[row][col]; // update most food amount
                                monkey = row; // update monkey index
                                day = col; // update day index
                            }
                    }
            }
        cout << fixed << setprecision(2)
            << "Monkey: " << monkey+1
            << " ate the most food: " << most
            << " lbs on day: " << day+1
            << endl; // display monkey/day with most food eaten
    }
