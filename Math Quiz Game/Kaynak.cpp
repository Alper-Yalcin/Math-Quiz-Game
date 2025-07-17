#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to check the user's answer
int checkAnswer(int& score, double correctAnswer) {
    double userAnswer;
    cin >> userAnswer;

    if (userAnswer == correctAnswer) {
        cout << "Correct answer!\n\n";
        score++;
        return 1;
    }
    else {
        cout << "Wrong answer!\n";
        cout << "Correct answer was: " << correctAnswer << endl;
        cout << "Your final score: " << score << endl;
        return 0;
    }
}

int main() {
    srand(time(0));
    int score = 0;

    while (true) {
        int num1 = (rand() % 10) + 1;
        int num2 = (rand() % 10) + 1;
        int operation = (rand() % 4) + 1;
        double correctAnswer = 0.0;

        switch (operation) {
        case 1: // Addition
            cout << "What is " << num1 << " + " << num2 << " ? ";
            correctAnswer = num1 + num2;
            if (checkAnswer(score, correctAnswer) == 0) return 0;
            break;

        case 2: // Subtraction
            if (num1 < num2) swap(num1, num2);
            cout << "What is " << num1 << " - " << num2 << " ? ";
            correctAnswer = num1 - num2;
            if (checkAnswer(score, correctAnswer) == 0) return 0;
            break;

        case 3: // Multiplication
            cout << "What is " << num1 << " * " << num2 << " ? ";
            correctAnswer = num1 * num2;
            if (checkAnswer(score, correctAnswer) == 0) return 0;
            break;

        case 4: // Division
            while (num2 == 0) num2 = (rand() % 9) + 1;
            if (num1 < num2) swap(num1, num2);
            cout << fixed;
            cout.precision(2);
            cout << "What is " << num1 << " / " << num2 << " ? ";
            correctAnswer = static_cast<double>(num1) / num2;
            if (checkAnswer(score, correctAnswer) == 0) return 0;
            break;
        }
    }
}
