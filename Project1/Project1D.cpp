/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 1, Task D
*/

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

string maskWord(string word) {
    for(int i = 0; i < word.length(); i++) {
        if(word[i] != " ") {
            word[i] = "_";
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
        if(i <= tries) {
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