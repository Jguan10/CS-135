/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: indent, lab 7B
*/

#include <iostream>
#include <fstream>

using namespace std;

int countChar(string line, char c) {
    int index = 0, counter = 0;;
    while(line[index]) {
        if(line[index] == c) {
            counter++;
        }
        index++;
    }
    return counter;
}

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

int main(){
    int counter = 0;
    string line;
    while (getline(cin, line, '\n')){
        string newLine = removeLeadingSpaces(line), indents = "";
        for(int i = 0; i < (newLine[0] != '}' ? counter : counter - 1 ); i++){
            indents += '\t';
        }
        cout << indents << newLine << endl;
        counter += countChar(line, '{') - countChar(line, '}');
    }
}