/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E5.6
*/

#include <iostream>
#include <string>

using namespace std;

string middle(string str) {
    int length = str.length();
    if(str.length() % 2 == 0) {
        return str.substr((length / 2) - 1, 2);
    }
    else if(str.length() % 2 == 1) {
        return str.substr((length / 2), 1);
    }
    return str;
}

int main() {
    string input;
    cout << "Input a string: " << endl;
    cin >> input;
    cout << middle(input) << endl;
    return 0;
}