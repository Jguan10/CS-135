/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: vigenere.cpp, Lab6
*/

#include <iostream>
#include <string>

using namespace std;

char shiftLower(char c, char key){
    int shifted, rshift;
    rshift = (int)key - (int)'a';
    if ((int)c < 97 || (int)c > 122){
        shifted = c;
    } 
    else if ((int)c + rshift > 122){
        shifted = (int)c - (26 - rshift);
    } 
    else {
        shifted = (int)c + rshift;
    }
    return shifted;
}

char shiftUpperv(char c, char key){
    int shifted, rshift;
    rshift = (int)key - (int)'a';
    if ((int)c + rshift > 90){
        shifted = (int)c - (26 - rshift);
    } 
    else {
        shifted = (int)c + rshift;
    }
    return shifted;
}


string encryptVigenere(string plaintext, string keyword){
    int counter = 0;
    for (int i = 0; i < plaintext.size(); i++){
        if (counter == keyword.length()){
            counter = 0;
        }
        if ((int)plaintext[i] >= 65 && (int)plaintext[i] <= 90){
            plaintext[i] = shiftUpperv(plaintext[i], keyword[counter]);
            counter += 1;
        } 
        else if ((int)plaintext[i] > 96 && (int)plaintext[i] < 123) {
            plaintext[i] = shiftLower(plaintext[i], keyword[counter]);
            counter += 1;
        }
    }
    return plaintext;
}

int main() {
    string plaintext, keyword;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter keyword: ";
    cin >> keyword;
    cout << encryptVigenere(plaintext, keyword);
}