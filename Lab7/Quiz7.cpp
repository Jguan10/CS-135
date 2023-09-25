/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Quiz 7, lab 7
*/

#include <iostream>
#include <string>

using namespace std;

void remove_e (string &word) {
    string newWord = "";
    for(int i = 0; i < word.length(); i++) {
        if(word[i] != 'e' && word[i] != 'E') {
            newWord += word[i];
        }
    }
    word = newWord;
}

int main() {
    string word = "Super Eerie Universe";
    remove_e(word);
    cout << word;
}