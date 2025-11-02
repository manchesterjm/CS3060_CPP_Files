/**
 * File: TestScores.h
 * Description: TestScores class for managing a collection of test scores.
 *
 * This class stores test scores in a dynamically allocated array and provides
 * methods for calculating statistics such as averages. It validates that all
 * scores are non-negative.
 */

#ifndef TEST_SCORES_H
#define TEST_SCORES_H

/**
 * TestScores class manages a collection of test scores.
 *
 * Stores test scores in a dynamically allocated array and validates
 * that all scores are non-negative upon creation.
 */
class TestScores {
private:
    int numScores_;  // Number of scores stored
    int* scores_;    // Pointer to dynamically allocated array of scores

public:
    /**
     * Default constructor.
     * Initializes with zero scores and null pointer.
     */
    TestScores() {
        numScores_ = 0;
        scores_ = nullptr;
    }

    /**
     * Parameterized constructor.
     *
     * @param scoreArray Array of integer scores
     * @param size Number of scores in the array
     * @throws NegativeScore if any score is negative
     */
    TestScores(int scoreArray[], int size);

    /**
     * Compute and return the average of all stored scores.
     *
     * @return The average score as a double
     */
    double getAverage() const;
};

#endif // TEST_SCORES_H
