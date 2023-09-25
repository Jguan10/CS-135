/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: fibonacci, lab 2A
*/

#include <iostream>
using namespace std;

int main() {
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 0; i < 60; i++) {
        if(i < 2) {
            cout << fib[i] << "\n";
        }
        if(i >= 2) {
            fib[i] = fib[i - 1] + fib[i - 2];
            cout << fib[i] << "\n";
        }
    }
    return 0;
}