/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: cross, lab 4C
*/

#include <iostream>
using namespace std;

int main() {
    int size, counter, space;
    cout << "Input size: " << endl;
    cin >> size;
    counter = size / 2;
    if (size % 2 == 0) {
        space = 0;
    }
    else if (size % 2 == 1) {
        space = 1;
    }
    cout << "Shape: " << endl;

    for (int i = 0; i < size / 2; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j < size - (2 * (i + 1)); j++) {
            cout << " ";
        }
        cout << "*" << endl;
    }

    if (size % 2 == 1) {
        for (int i = 0; i < size / 2; i++) {
        cout << " ";
        }
    cout << "*" << endl;
    }

    for (int i = 0; i < size/2; i++) {
        for(int j = 0; j < counter - 1; j++) {
            cout << " ";
        }
        cout << "*";
        for(int j = 0; j < space; j++) {
            cout << " ";
        }
        cout << "*" << endl;
        space = space + 2;
        counter--;
    }
    return 0;
}

