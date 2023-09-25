/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: valid, lab 2A
*/

#include <iostream>
using namespace std;

int main() {
    int input = 0;
    cout << "Please enter an integer between 0 and 100: ";
    cin >> input;
    while(input <= 0 || input >= 100) {
        cout << "Please re-enter: ";
        cin >> input;
    }
    cout << "Number squared is " << input * input;
    return 0;
}