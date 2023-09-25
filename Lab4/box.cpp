/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: box, lab 4A
*/

#include <iostream>
using namespace std;

int main() {
    int width, height;
    cout << "Input width: " << endl;
    cin >> width;
    cout << "Input height: " << endl;
    cin >> height;
    cout << "Shape: " << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j ++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}