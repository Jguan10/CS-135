/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: test-ascii, lab 6A
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Input: ";
    getline(cin, input);

    for(int i = 0; i < input.length(); i++) {
        cout << input[i] << " " << (int)input[i] << endl;
    }
}