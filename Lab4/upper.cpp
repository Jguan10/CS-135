/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: upper, lab 4E
*/

#include <iostream>
using namespace std;

int main() {
    int length, counter;
    cout << "Input side length: " << endl;
    cin >> length;
    counter = length;
    cout << "Shape: " << endl;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - counter; j++) {
            cout << " ";
        }
        for (int j = 0; j < counter; j++) {
            cout << "*";
        }
        counter--;
        cout << "\n";
    }
}