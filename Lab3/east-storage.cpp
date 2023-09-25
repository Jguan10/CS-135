/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: east-storage, lab 3A
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {
    string date, header, eastSt, dateInput;
    cout << "Enter a date in MM/DD/YY format: ";
    cin >> dateInput;
    ifstream resevoir("Current_Reservoir_Levels.tsv");
    if (resevoir.fail()) {
        cerr << "File cannot be opened for reading.";
        exit(1);
    }
    getline (resevoir, header);
    cout << "East Basin Storage: ";
    while (resevoir >> date >> eastSt) {
        resevoir.ignore(INT_MAX, '\n'); 
        if (date == dateInput) {
            cout << eastSt << "billion gallons";
        }
    }
    resevoir.close();
    
    return 0;
}