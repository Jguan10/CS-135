/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: lower, lab 4D
*/

#include <iostream>
using namespace std;

int main() {
    int length, counter = 1;
    cout << "Input side length: " << endl;
    cin >> length;
    cout << "Shape: " << endl;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < counter; j++) {
            cout << "*";
        }
        counter++;
        cout << "\n";
    }
    return 0;
}