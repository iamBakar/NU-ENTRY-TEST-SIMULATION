#include "NUEntryTest.h"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <chrono>

using namespace std;

NUEntryTest::NUEntryTest() {
    srand(time(0)); // for random questions

    loadQuestionBank();
    testEndedEarly = false;
    lastAnsweredCount = 0;
}


void NUEntryTest::loadQuestionBank() { // using ai for hard coding questions
    int i = 0;

    // ---------- MATH (18) ----------
    bank[i++] = Question("12 + 15 = ?", "25", "27", "28", "26", 'B', "Math");
    bank[i++] = Question("9 * 8 = ?", "72", "64", "81", "56", 'A', "Math");
    bank[i++] = Question("144 / 12 = ?", "11", "12", "13", "14", 'B', "Math");
    bank[i++] = Question("Square root of 81 = ?", "8", "9", "7", "10", 'B', "Math");
    bank[i++] = Question("15% of 200 = ?", "20", "25", "30", "35", 'C', "Math");
    bank[i++] = Question("Solve: 3x = 21, x = ?", "6", "7", "8", "9", 'B', "Math");
    bank[i++] = Question("Perimeter of a square with side 5 = ?", "20", "25", "10", "15", 'A', "Math");
    bank[i++] = Question("Area of a rectangle 4 x 6 = ?", "20", "24", "28", "10", 'B', "Math");
    bank[i++] = Question("7^2 = ?", "14", "49", "42", "56", 'B', "Math");
    bank[i++] = Question("Average of 4, 8, 12 = ?", "6", "8", "10", "24", 'B', "Math");
    bank[i++] = Question("Simplify: 2(x + 3) = 2x + ?", "3", "5", "6", "9", 'C', "Math");
    bank[i++] = Question("A train covers 60 km in 1 hour. Its speed is ?", "30 km/h", "60 km/h", "90 km/h", "120 km/h", 'B', "Math");
    bank[i++] = Question("LCM of 4 and 6 = ?", "8", "10", "12", "24", 'C', "Math");
    bank[i++] = Question("HCF of 12 and 18 = ?", "2", "3", "6", "9", 'C', "Math");
    bank[i++] = Question("0.5 + 0.25 = ?", "0.75", "0.65", "0.85", "1.00", 'A', "Math");
    bank[i++] = Question("Convert 3/4 to a percentage: ?", "50%", "75%", "25%", "80%", 'B', "Math");
    bank[i++] = Question("Sum of angles in a triangle = ?", "90", "180", "270", "360", 'B', "Math");
    bank[i++] = Question("5! (factorial of 5) = ?", "20", "60", "120", "24", 'C', "Math");

    // ---------- ENGLISH (16) ----------
    bank[i++] = Question("Choose the synonym of 'Happy':", "Sad", "Joyful", "Angry", "Tired", 'B', "English");
    bank[i++] = Question("Choose the antonym of 'Brave':", "Courageous", "Bold", "Cowardly", "Strong", 'C', "English");
    bank[i++] = Question("Choose the correct spelling:", "Recieve", "Receive", "Receeve", "Receve", 'B', "English");
    bank[i++] = Question("He ___ to school every day.", "go", "goes", "going", "gone", 'B', "English");
    bank[i++] = Question("What is the plural of 'Child'?", "Childs", "Childes", "Children", "Childer", 'C', "English");
    bank[i++] = Question("Choose the synonym of 'Begin':", "End", "Start", "Stop", "Finish", 'B', "English");
    bank[i++] = Question("Choose the antonym of 'Ancient':", "Old", "Modern", "Historic", "Aged", 'B', "English");
    bank[i++] = Question("___ apple a day keeps the doctor away.", "A", "An", "The", "No article", 'B', "English");
    bank[i++] = Question("Choose the synonym of 'Huge':", "Tiny", "Small", "Enormous", "Short", 'C', "English");
    bank[i++] = Question("Identify the noun: 'The dog barked loudly.'", "dog", "barked", "loudly", "the", 'A', "English");
    bank[i++] = Question("What is the past tense of 'Go'?", "Goed", "Gone", "Went", "Going", 'C', "English");
    bank[i++] = Question("Choose the antonym of 'Increase':", "Raise", "Decrease", "Expand", "Grow", 'B', "English");
    bank[i++] = Question("Choose the correct sentence:", "She don't like tea", "She doesn't like tea", "She not like tea", "She didn't likes tea", 'B', "English");
    bank[i++] = Question("Choose the synonym of 'Rapid':", "Slow", "Quick", "Lazy", "Calm", 'B', "English");
    bank[i++] = Question("Identify the verb: 'They are playing football.'", "They", "are playing", "football", "the", 'B', "English");
    bank[i++] = Question("Choose the antonym of 'Generous':", "Kind", "Stingy", "Helpful", "Caring", 'B', "English");

    // ---------- ANALYTICAL / IQ (16) ----------
    bank[i++] = Question("Find the next number: 2, 4, 6, 8, ?", "9", "10", "11", "12", 'B', "Analytical");
    bank[i++] = Question("Find the next number: 1, 4, 9, 16, ?", "20", "24", "25", "27", 'C', "Analytical");
    bank[i++] = Question("All cats are animals. Tom is a cat. So Tom is:", "A dog", "An animal", "A plant", "Not living", 'B', "Analytical");
    bank[i++] = Question("Find the odd one out:", "Apple", "Banana", "Carrot", "Mango", 'C', "Analytical");
    bank[i++] = Question("Find the next number: 3, 6, 12, 24, ?", "30", "36", "48", "44", 'C', "Analytical");
    bank[i++] = Question("Find the next letter: A, C, E, G, ?", "H", "I", "J", "K", 'B', "Analytical");
    bank[i++] = Question("If today is Monday, what day is it after 3 days?", "Wednesday", "Thursday", "Friday", "Saturday", 'B', "Analytical");
    bank[i++] = Question("Pen is to Write as Knife is to:", "Cut", "Cook", "Eat", "Draw", 'A', "Analytical");
    bank[i++] = Question("Find the missing number: 5, 10, ?, 20, 25", "12", "14", "15", "16", 'C', "Analytical");
    bank[i++] = Question("A clock shows 3:00. The angle between the hands is:", "0", "90", "180", "270", 'B', "Analytical");
    bank[i++] = Question("Find the odd one out:", "Square", "Circle", "Triangle", "Sphere", 'D', "Analytical");
    bank[i++] = Question("5 workers build a wall in 10 days. How many days for 10 workers (same rate)?", "5", "10", "15", "20", 'A', "Analytical");
    bank[i++] = Question("Find the next number: 100, 90, 81, 73, ?", "64", "65", "66", "67", 'C', "Analytical");
    bank[i++] = Question("If North is up, the opposite of East is:", "West", "South", "North", "Up", 'A', "Analytical");
    bank[i++] = Question("Find the word that does NOT belong:", "Dog", "Cat", "Lion", "Car", 'D', "Analytical");
    bank[i++] = Question("Find the next number: 2, 3, 5, 7, 11, ?", "12", "13", "14", "15", 'B', "Analytical");
}

void NUEntryTest::selectRandomQuestions() {
    bool used[BANK_SIZE];
    for (int i = 0; i < BANK_SIZE; i++) {
        used[i] = false;
    }

    int picked = 0;
    while (picked < TEST_SIZE) { // picks only 20 (TEST_SIZE)
        int idx = rand() % BANK_SIZE;
        if (!used[idx]) {
            used[idx] = true;
            selected[picked] = bank[idx];
            picked++;
        }
    }
}

void NUEntryTest::resetAttemptState() { // everything resets, a fresh start (avoids problems by ending test early)
    for (int i = 0; i < TEST_SIZE; i++) {
        userAnswers[i] = '-';
        attempted[i] = false;
    }
    testEndedEarly = false;
}

QuestionOutcome NUEntryTest::presentQuestion(int displayIndex) {
    selected[displayIndex].display(displayIndex + 1);

    int action = 0;
    while (true) {
        cout << "\n1. Choose an Option   2. Skip Question   3. End Test\n";
        cout << "Enter choice (1-3): ";
        cin >> action;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n";
            continue;
        }
        if (action >=1 && action <=3) break;

        cout << "Please enter 1, 2, or 3.\n";
    }

    if (action == 3) {
        return ENDED_TEST;
    }

    if (action == 2) {
        return SKIPPED;
    }

    // action == 1: ask for user's option 
    char ans;
    while (true) {
        cout << "Enter your answer (A/B/C/D): ";
        cin >> ans;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n";
            continue;
        }

        ans = toupper(ans);
        if (ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D') break;
        cout << "Invalid option.\n";
    }

    userAnswers[displayIndex] = ans;
    attempted[displayIndex] = true;
    return ANSWERED;
}

void NUEntryTest::revisitSkippedQuestions() {
    // Build the list of skipped question numbers first
    int skippedIndexes[TEST_SIZE];
    int skippedCount = 0;

    for (int i = 0; i < TEST_SIZE; i++) {
        if (!attempted[i]) {
            skippedIndexes[skippedCount++] = i;
        }
    }

    if (skippedCount == 0) {
        cout << "\nYou did not skip any questions.\n";
        return;
    }

    cout << "You skipped " << skippedCount << " question(s): ";
    for (int i = 0; i < skippedCount; i++) {
        cout << "Q" << (skippedIndexes[i] + 1);
        if (i != skippedCount - 1) cout << ", ";
    }

    char choice;
    cout << "Would you like to go back and attempt them now? (y/n): ";
    cin >> choice;
    if (toupper(choice) != 'Y') return;

    for (int i = 0; i < skippedCount; i++) {
        int qIndex = skippedIndexes[i];
        cout << "\n--- Revisiting Skipped Question ---";
        QuestionOutcome outcome = presentQuestion(qIndex);
        if (outcome == ENDED_TEST) {
            testEndedEarly = true;
            return;
        }
        // if outcome is SKIPPED again, it simply stays unattempted
    }
}

void NUEntryTest::showResults() const {
    int correct = 0, wrong = 0, skipped = 0;
    double score = 0.0;

    // for category wise result
    int mathCorrect = 0, mathWrong = 0, mathTotal = 0;
    int engCorrect = 0, engWrong = 0, engTotal = 0;
    int anaCorrect = 0, anaWrong = 0, anaTotal = 0;

    for (int i = 0; i < TEST_SIZE; i++) {
        string cat = selected[i].getCategory();
        if (cat == "Math") mathTotal++;
        else if (cat == "English") engTotal++;
        else anaTotal++;

        if (!attempted[i]) {
            skipped++;
            score += MARKS_SKIPPED;
            continue;
        }

        if (selected[i].isCorrect(userAnswers[i])) {
            correct++;
            score += MARKS_CORRECT;
            if (cat == "Math") mathCorrect++;
            else if (cat == "English") engCorrect++;
            else anaCorrect++;
        } else {
            wrong++;
            score += MARKS_WRONG;
            if (cat == "Math") mathWrong++;
            else if (cat == "English") engWrong++;
            else anaWrong++;
        }
    }

    cout << "\n=================================================\n";
    cout << "                  TEST RESULT                    \n";
    cout << "=================================================\n";
    if (testEndedEarly) {
        cout << "(Test was ended early by the candidate)\n";
    }
    cout << "Total Questions   : " << TEST_SIZE << "\n";
    cout << "Correct Answers   : " << correct << "  (+" << MARKS_CORRECT << " each)\n";
    cout << "Wrong Answers     : " << wrong << "  (" << MARKS_WRONG << " each)\n";
    cout << "Skipped Questions : " << skipped << "  (0 each)\n";
    cout << "-------------------------------------------------\n";
    cout << "Final Score       : " << score << " / " << TEST_SIZE << "\n";
    cout << "Percentage        : " << (score / TEST_SIZE) * 100 << "%\n";
    cout << "-------------------------------------------------\n";

    cout << "Category-wise:\n";
    cout << "  Math       -> Correct: " << mathCorrect << ", Wrong: " << mathWrong
         << ", Total: " << mathTotal << "\n";
    cout << "  English    -> Correct: " << engCorrect << ", Wrong: " << engWrong
         << ", Total: " << engTotal << "\n";
    cout << "  Analytical -> Correct: " << anaCorrect << ", Wrong: " << anaWrong
         << ", Total: " << anaTotal << "\n";
}

void NUEntryTest::showInstructions() {
    cout << "\n=================================================\n";
    cout << "                 TEST INSTRUCTIONS               \n";
    cout << "=================================================\n";
    cout << "1. Each correct answer carries 1 mark.\n";
    cout << "2. Each incorrect answer will deduct 0.25 marks.\n";
    cout << "3. No marks will be given or deducted for skipped questions.\n";
    cout << "4. Once you select an answer, you cannot go back to change it.\n";
    cout << "5. Total time for the test is 5 minutes.\n";
    cout << "6. Once you end the test, you cannot resume it.\n";
    cout << "7. Please read each question carefully before answering.\n";
    cout << "\nGood luck!\n";
    cout << "=================================================\n";
}

void NUEntryTest::takeTest() {
    showInstructions();
    resetAttemptState();
    selectRandomQuestions();

    cout << "Double press ENTER to start the test!" << endl;
    cin.ignore();
    cin.get();

    auto startTime = chrono::high_resolution_clock::now();
    int timeLimit = 300; // 300 seconds 

    cout << "\n*************************************************\n";
    cout << "                FAST-NU ENTRY TEST                  \n";
    cout << "*************************************************\n";

    for (int i = 0; i < TEST_SIZE; i++) {
        // Get current time
        auto currentTime = chrono::high_resolution_clock::now();

        int elapsed = chrono::duration_cast<chrono::seconds>(currentTime - startTime).count();

        if (elapsed >= timeLimit) {
            cout << "\nTime is up! Test ended.\n";
            testEndedEarly = true;
            break;
        }

        int remaining = timeLimit - elapsed;
        int minutes = remaining / 60;
        int seconds = remaining % 60;

        cout << "\nTime Left: " << minutes << "m " << seconds << "s\n";

        QuestionOutcome outcome = presentQuestion(i);
        if (outcome == ENDED_TEST) {
            testEndedEarly = true;
            break;
        }
    }

    if (!testEndedEarly) {
        revisitSkippedQuestions();
    }

    showResults();
}
