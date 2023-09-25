/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E3.5
*/

#include <iostream>
using namespace std;

int main() {
    int num1,num2,num3;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the third number: ";
    cin >> num3;

    if(num1 > num2 && num2 > num3) {
        cout << "decreasing";
    }
    else if (num1 < num2 && num2 < num3) {
        cout << "increasing";
    }
    else {
        cout << "neither";
    }
    return 0;
}