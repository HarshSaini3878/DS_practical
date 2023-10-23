#include <iostream>

using namespace std;

const int NUM_STUDENTS = 3;
const int NUM_SUBJECTS = 5;

int main() {
    int marks[NUM_STUDENTS][NUM_SUBJECTS];

    // Taking input for marks in 5 subjects for each student
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Enter marks for Student " << i + 1 << " in 5 subjects:\n";
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            cout << "Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }


    int total[NUM_STUDENTS] = {0};
    double subjectAverage[NUM_SUBJECTS] = {0};

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            total[i] += marks[i][j];
            subjectAverage[j] += marks[i][j];
        }
    }

    for (int j = 0; j < NUM_SUBJECTS; ++j) {
        subjectAverage[j] /= NUM_STUDENTS;
    }

    // Displaying total of every student
    cout << "\nTotal marks of every student:\n";
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student " << i + 1 << ": " << total[i] << endl;
    }

    // Displaying average of every subject
    cout << "\nAverage marks of every subject:\n";
    for (int j = 0; j < NUM_SUBJECTS; ++j) {
        cout << "Subject " << j + 1 << ": " << subjectAverage[j] << endl;
    }

    return 0;
}
