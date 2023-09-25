/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 1, Task A
*/

#include <iostream>
#include <fstream>  
#include <climits>
#include <string>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename) {

    string header, word, pos, definition, holder, sub;
    int counter = 100;
    ifstream file(filename);

    if (file.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    getline(file, header);

    while(getline(file, holder)) {
        int index1 = holder.find(" "), index2 = holder.find(":");
        word = holder.substr(0, index1);
        pos = holder.substr(index1 + 1, index2 - index1 - 2);
        definition = holder.substr(index2 + 2, holder.length() - 1);
        g_words[g_word_count] = word;
        g_pos[g_word_count] = pos;
        g_definitions[g_word_count] = definition;
        g_word_count++;
    }
}

int main() {
    readWords("example.txt");
    for(int i = 0; i < 5; i++) {
        cout << g_words[i] << endl;
        cout << g_pos[i] << endl;
        cout << g_definitions[i] <<endl;
    }
    return 0;
}

