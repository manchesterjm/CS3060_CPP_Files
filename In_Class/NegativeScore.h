/**
 * File: NegativeScore.h
 * Description: Custom exception class for invalid negative scores.
 *
 * This exception is thrown when a negative score is encountered
 * in the TestScores class or related scoring functionality.
 */

#ifndef NEGATIVE_SCORE_H
#define NEGATIVE_SCORE_H

/**
 * NegativeScore exception class.
 *
 * Exception thrown when a negative score value is encountered.
 * Stores the invalid score value for error reporting.
 */
class NegativeScore {
private:
    int score_;  // The invalid (negative) score value

public:
    /**
     * Constructor to create exception with the invalid score.
     *
     * @param s The negative score that caused the exception
     */
    NegativeScore(int s) : score_(s) { }

    /**
     * Get the invalid score value.
     *
     * @return The negative score that caused this exception
     */
    int getScore() const {
        return score_;
    }
};

#endif // NEGATIVE_SCORE_H
