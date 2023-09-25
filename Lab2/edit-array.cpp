/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: edit-array, lab 2A
*/

#include <iostream>
using namespace std;

int main() {
    int myData[10];
    int i,v;
    for(int i = 0; i < 10; i++) {
        myData[i] = 1;
    }   
    while(i >= 0 && i < 10) {
        for(int i = 0; i < 10; i++) {
            cout << myData[i] << " ";
        }
        cout << "\n";  
        cout << "Enter i: \n";
        cout << "Enter v: \n";  
        cin >> i;
        cin >> v;
        if(i >= 0 && i < 10) {
            myData[i] = v;
        }
    }
    cout << "Index out of range. Exit.";
    return 0;
}