/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 1
*/

#include <iostream>
#include <fstream>  
#include <climits>
#include <string>
#include <stdlib.h>

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
        g_word_count = g_word_count + 1;
    }
}

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

string getDefinition(string word) {
    int counter = 0, index;
    for(int i = 0; i < g_word_count; i++) {
        if(g_words[i] == word) {
            counter++;
            index = i;
        }
    }
    if(counter == 1) {
        return g_definitions[index];
    }
    else {
        return "NOT_FOUND";
    }
}

string getPOS(string word) {
    int counter = 0, index;
    for(int i = 0; i < g_word_count; i++) {
        if(g_words[i] == word) {
            counter++;
            index = i;
        }
    }
    if(counter == 1) {
        return g_pos[index];
    }
    else {
        return "NOT_FOUND";
    }
}

int countPrefix(string prefix) {
    int counter = 0;
    for(int i = 0; i < g_word_count; i++) {
        if(prefix == g_words[i].substr(0, prefix.length())) {
            counter++;
        }
    }
    return counter;
}

bool addWord(string word, string definition, string pos) {
    if(g_word_count > 1000) {
        return false;
    }
    for(int i = 0; i < g_word_count; i++) {
        if(g_words[i] == word) {
            return false;
        }
    }
    g_words[g_word_count] = word;
    g_definitions[g_word_count] = definition;
    g_pos[g_word_count] = pos;
    g_word_count++;
    return true;
}

bool editWord(string word, string definition, string pos) {
    for(int i = 0; i < g_word_count; i++) {
        if(g_words[i] == word) {
            g_definitions[i] = definition;
            g_pos[i] = pos;
            return true;
        }
    }
    return false;
}

bool removeWord(string word) {
    for (int i = 0; i < g_word_count; i++) {
        if (g_words[i] == word) {
            for (int j = i + 1; j < g_word_count; j++) {
                g_words[j - 1] = g_words[j];
                g_definitions[j - 1] = g_definitions[j];
                g_pos[j - 1] = g_pos[j];
            }
            g_words[g_word_count] = "";
            g_definitions[g_word_count] = "";
            g_pos[g_word_count] = "";
            g_word_count--;
            return true;
        }
    }
    return false;
}

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

string maskWord(string word) {
    for(int i = 0; i < word.length(); i++) {
        if(word[i] != ' ') {
            word[i] = '_';
        }
    }
    return word;
}

int getTries(int difficulty) {
    if(difficulty == 0) {
        return 9;
    }
    else if(difficulty == 1) {
        return 7;
    }
    else if(difficulty == 2) {
        return 5;
    }
}

void printAttempts(int tries, int difficulty) {
    for(int i = 0; i < getTries(difficulty); i++) {
        if(i < tries) {
            cout << "O";
        }
        else {
            cout << "X";
        }
    }
}

bool revealLetter(string word, char letter, string &current) {
    bool check;
    for(int i = 0; i < word.length(); i++) {
        if(word[i] == letter) {
            current[i] = letter;
            check = true;
        }
    }
    if(check) {
        return true;
    }
    return false;
}

void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}

int main() {
    gameLoop();
}
