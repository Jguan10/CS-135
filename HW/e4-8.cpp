/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW e4.8
*/

#include <iostream>
using namespace std;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;
    char letters[word.length()];
    for(int i = 0; i < word.length(); i++) {
        letters[i] = word[i];
        cout << letters[i] << "\n";
    }
    return 0;
}