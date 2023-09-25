/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 1, Task C   
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

int getIndex(string word) {
    int counter = 0, index;
    for(int i = 0; i < g_word_count; i++) {
        if(g_words[i] == word) {
            counter++;
            index = i;
        }
    }
    if(counter == 1) {
        return index;
    }
    else {
        return -1;
    }
}

bool addWord(string word, string definition, string pos) {
    int index = getIndex(word);
    if(g_word_count > 1000) {
        return false;
    }
    else if(index == -1) {
        return false;
    }
    else { 
        g_words[g_word_count] = word;
        g_definitions[g_word_count] = definition;
        g_pos[g_word_count] = pos;
        g_word_count++;
        return true;
    }
}

bool editWord(string word, string definition, string pos) {
    int index = getIndex(word);
    if(index != -1) {
        g_definitions[index] = definition;
        g_pos[index] = pos;
        return true;    
    }
    else {
        return false;
    }
}

bool removeWord(string word) {
    int index = getIndex(word);
    if(index != -1) {
        g_words[index] = g_words[g_word_count];
        g_definitions[index] = g_definitions[g_word_count];
        g_pos[index] = g_pos[g_word_count];
        g_words[g_word_count] = "";
        g_definitions[g_word_count] = "";
        g_pos[g_word_count] = "";
        g_word_count--;
        return true;
    }
    else {
        return false;
    }
}

int main() {
    addWord("Hi", "Greeting", "IDK");
    cout << g_words[0] << g_definitions[0] << g_pos[0] << endl;
    editWord("Hi", "Bye", "Still dunno");
    cout << g_words[0] << g_definitions[0] << g_pos[0] << endl;
    removeWord("Hi");
    cout << g_words[0] << g_definitions[0] << g_pos[0] << endl;
    return 0;
}
