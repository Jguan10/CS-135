/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: unindent, lab 7A
*/

#include <iostream>
#include <cctype>

using namespace std;

string removeLeadingSpaces(string line){
    int index = 0;
    string newLine;
    while (isspace(line[index])){
        index += 1;
    }
    for (index; index < line.size(); index++){
        newLine += line[index];
    }
    return newLine;
}

int main() {
    string line;
    while(getline(cin, line)) {
        cout << removeLeadingSpaces(line) << endl;
    }
}