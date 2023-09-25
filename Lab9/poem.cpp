/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: poem.cpp, lab 9
*/

#include <iostream>

using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        // assume that the poem p is not needed at this point
        delete p;
    }
}