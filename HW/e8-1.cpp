/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E8-1
*/


#include <iostream>
#include <fstream>

using namespace std; 

int main() {
    fstream fin;
    fin.open("hello.txt", ios::out);
    fin << "Hello, World!";
    fin.close();
    string hello;
    fin.open("hello.txt", ios::in);
    while (getline(fin,hello)){
        cout << hello << endl;
    }
    fin.close();
}