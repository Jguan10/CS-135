/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: checkerboard, lab 4B
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
        for (int j = 0; j < width; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    cout << "*";
                }
                else {
                    cout << " ";
                }
            }
            else if (i % 2 == 1) {
                if (j % 2 == 0) {
                    cout << " ";
                }
                else {
                    cout << "*";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}