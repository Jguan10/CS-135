/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Quiz2, lab 2
*/

#include <iostream>
using namespace std;

int main() {
    int num1 = 0;
    int num2 = 0;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    if(num1 > num2) {
        cout << num1;
    }
    else {
        cout << num2;
    }
    return 0;
}