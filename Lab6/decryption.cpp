/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: decryption.cpp, lab 6
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

char shiftUpper(char c, char key){
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
            plaintext[i] = shiftUpper(plaintext[i], keyword[counter]);
            counter += 1;
        } 
        else if ((int)plaintext[i] > 96 && (int)plaintext[i] < 123) {
            plaintext[i] = shiftLower(plaintext[i], keyword[counter]);
            counter += 1;
        }
    }
    return plaintext;
}

string encryptCaesar(string plaintext, int rshift) {
    for(int i = 0; i < plaintext.length(); i++) {
        plaintext[i] = shiftChar(plaintext[i], rshift);
    }
    return plaintext;
}

string decryptCaesar(string ciphertext, int rshift) {

}

string decryptVigenere(string ciphertext, string keyword) {
    
}

int main() {
    string plaintext, keyword;
    int shift;
    cout << "Enter plaintext: " << endl;
    cin >> plaintext;
    cout << "= Caesar = " << endl;
    cout << "Enter shift    : " << endl;
    cin >> shift;
    cout << "Ciphertext     : " << encryptCaesar(plaintext, shift) << endl;
    cout << "Decrypted      : " << decryptCaesar(encryptCaesar(plaintext, shift), shift) << endl;
    cout << "= Vigenere =" << endl;
    cout << "Enter keyword  : " << endl;
    cin >> keyword;
    cout << "Ciphertext     : " << encryptVigenere(plaintext, keyword) << endl;
    cout << "Decrypted      : " << decryptVigenere(encryptVigenere(plaintext, keyword), keyword) << endl;
}