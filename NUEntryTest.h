#ifndef NU_ENTRY_TEST_H
#define NU_ENTRY_TEST_H

#include "Question.h"

const int BANK_SIZE = 50;          // total MCQs from which the system picks randomly 
const int TEST_SIZE = 20;          // MCQs picked per attempt
const double MARKS_CORRECT = 1.0;
const double MARKS_WRONG = -0.25;  
const double MARKS_SKIPPED = 0.0;

// Result of presenting one question to the user
enum QuestionOutcome { ANSWERED, SKIPPED, ENDED_TEST };

class NUEntryTest {
private:
    Question bank[BANK_SIZE];

    Question selected[TEST_SIZE];
    char userAnswers[TEST_SIZE]; 
    bool attempted[TEST_SIZE];
    bool testEndedEarly;
    int lastAnsweredCount; // how many were attempted before ending 

    void loadQuestionBank();
    void selectRandomQuestions();
    void resetAttemptState();

    QuestionOutcome presentQuestion(int displayIndex);
    void revisitSkippedQuestions();
    void showResults() const;

public:
    NUEntryTest();
    void showInstructions();
    void takeTest();
};

#endif
