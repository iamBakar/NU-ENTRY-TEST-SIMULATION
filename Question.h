#ifndef QUESTION_H
#define QUESTION_H
#include <string>

using namespace std;

class Question {
private:
    string questionText;
    string options[4];  
    char correctOption;
    string category;     // Either math, english or analytical (for subject wise result at the end)

public:
    Question();
    Question(string questionText, string optionA, string optionB, string optionC, string optionD, char correctOption, string category);

    string getQuestionText() const;
    string getOption(int index) const;
    char getCorrectOption() const;
    string getCategory() const;

    bool isCorrect(char chosenOption) const;
    void display(int displayNumber) const;
};

#endif
