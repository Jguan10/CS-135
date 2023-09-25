/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: trapezoid, lab 4F
*/

#include <iostream>
using namespace std;

int main() {
    int width, height, spaces = 0, counter;
    cout << "Input width: " << endl;
    cin >> width;
    cout << "Input height: " << endl;
    cin >> height;
    counter = width;

    if (width - 2 * (height - 1) > 0) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < spaces; j++) {
                cout << " ";
            }
            for (int j = 0; j < counter; j++) {
                cout << "*";
            }
            spaces++;
            counter = counter - 2;  
            cout << "\n";
        }
    }
    else {
        cout << "Impossible shape!";
    }

}