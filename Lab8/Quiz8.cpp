/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Quiz 8, lab 8
*/

#include <iostream>
#include <string>

using namespace std;

int unbalanced_brackets(string input) {
    int ocounter = 0, ccounter = 0;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '}') {
            ccounter++;
        }
        else if(input[i] == '{') {
            ocounter++;
        }
    }
    return ocounter - ccounter;
}

int main() {
    string input;
    cout << "Input a string: " << endl;
    cin >> input;
    cout << unbalanced_brackets(input) << endl;
}