/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: print-interval, lab 2A
*/

#include <iostream>
using namespace std;

int main() {
    int lower = 0;
    int upper = 0;
    cout << "Enter lower bound: ";
    cin >> lower;
    cout << "Enter upper bound: ";
    cin >> upper;
    for(int i = lower; i < upper; i++) {
        cout << i << " ";
    }
    
}