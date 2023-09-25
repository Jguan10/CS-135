/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: caeser, lab 6B
*/

#include <iostream>
#include <string>

using namespace std;

char shiftChar(char c, int rshift) {
    int ascii = (int)c;
    if(ascii >= 97 && ascii <= 122) {
        if(ascii + rshift > 122) {
            ascii = rshift + ascii - 26;
        }
        else{
            ascii = rshift + ascii;
        }
    } 
    else if(ascii >= 65 && ascii <= 90) {
        if(ascii + rshift > 90) {
            ascii = rshift + ascii - 26;
        }
        else {
            ascii = rshift + ascii;
        }
    }
    return (char)ascii; 
}

string encryptCaesar(string plaintext, int rshift) {
    for(int i = 0; i < plaintext.length(); i++) {
        plaintext[i] = shiftChar(plaintext[i], rshift);
    }
    return plaintext;
}

int main() {
    string plaintext;
    int shift;
    cout << "Enter the plaintext: " << endl;
    getline(cin, plaintext);
    cout << "Enter the magnitude of shift: " << endl;
    cin >> shift;
    cout << encryptCaesar(plaintext,shift);
}