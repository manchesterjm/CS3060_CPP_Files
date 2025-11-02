/**
 * File: TestScores.cpp
 * Description: Implementation of TestScores class for managing and calculating
 * statistics on student test scores.
 *
 * Provides functionality to store test scores and calculate averages while
 * validating that all scores are non-negative.
 */

#include "TestScores.h"          // Corresponding header first
#include "NegativeScore.h"       // Project headers
#include <iostream>              // Standard library headers

using namespace std;

// Number of scores to work with in main
const int NUM_SCORES = 5;

/**
 * Constructor: Initializes TestScores object with an array of scores.
 *
 * Stores the number of scores, allocates a dynamic array, and checks
 * for negative scores, throwing an exception if any are found.
 *
 * @param scoreArray Array of integer scores to store
 * @param size Number of scores in the array
 * @throws NegativeScore if any score in the array is negative
 */
TestScores::TestScores(int scoreArray[], int size) {
    numScores_ = size;              // Record how many scores we have
    scores_ = new int[size];        // Allocate space for scores

    for (int index = 0; index < size; index++) {
        if (scoreArray[index] < 0) {
            // Negative score detected - throw exception
            throw NegativeScore(scoreArray[index]);
        }
        else {
            // Copy valid score into our array
            scores_[index] = scoreArray[index];
        }
    }
}

/**
 * Calculate the average of all test scores.
 *
 * Computes the sum of all scores and divides by the number of scores
 * to calculate the arithmetic mean.
 *
 * @return The average score as a double
 */
double TestScores::getAverage() const {
    int total = 0;
    for (int index = 0; index < numScores_; index++) {
        total += scores_[index];    // Add up the scores
    }
    // Convert to double and return average
    return static_cast<double>(total) / numScores_;
}

/**
 * Main function demonstrating TestScores usage.
 *
 * Creates TestScores objects with valid and invalid score arrays
 * to demonstrate normal operation and exception handling.
 */
int main() {
    try {
        // First set of scores (all valid)
        int myScores[NUM_SCORES] = {88, 90, 93, 87, 99};
        TestScores myTestScores(myScores, NUM_SCORES);

        // Display the average score
        cout << "The average score is "
             << myTestScores.getAverage() << endl;

        // Second set of scores contains a negative value
        int badScores[NUM_SCORES] = {88, 90, -99, 87, 99};
        // This line will throw NegativeScore during construction
        TestScores badTestScores(badScores, NUM_SCORES);

        // This line won't execute if exception is thrown above
        cout << "The average score is "
             << badTestScores.getAverage() << endl;
    }
    catch (const NegativeScore& e) {
        // Catch the exception and report the invalid score
        cout << "An invalid score was found. The "
             << "invalid score is " << e.getScore()
             << endl;
    }

    return 0;  // Normal program termination
}
