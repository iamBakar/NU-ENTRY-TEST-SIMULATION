#include "Question.h"
#include <iostream>
#include <cctype>
using namespace std;

Question::Question() {
    questionText = "";
    options[0] = options[1] = options[2] = options[3] = "";
    correctOption = 'A';
    category = "";
}

Question::Question(string questionText, string optionA, string optionB, string optionC, string optionD, char correctOption, string category) {
    this->questionText = questionText;
    options[0] = optionA;
    options[1] = optionB;
    options[2] = optionC;
    options[3] = optionD;
    this->correctOption = correctOption;
    this->category = category;
}

string Question::getQuestionText() const { 
    return questionText;
}
string Question::getOption(int index) const { 
    return options[index];
}
char Question::getCorrectOption() const {
    return correctOption; 
}
string Question::getCategory() const {
    return category; 
}

bool Question::isCorrect(char chosenOption) const {
    return toupper(chosenOption) == correctOption;
}

void Question::display(int displayNumber) const {
    cout << "\nQ" << displayNumber << ". [" << category << "]  " << questionText << "\n";
    cout << "   A) " << options[0] << "\n";
    cout << "   B) " << options[1] << "\n";
    cout << "   C) " << options[2] << "\n";
    cout << "   D) " << options[3] << "\n";
}
