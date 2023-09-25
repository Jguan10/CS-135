/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: reverse-order, lab 3D
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {
    string header, start, end, date, dateArray[365];
    double eastEl, westEl, eastArray[365], westArray[365], west, eastSt, westSt;
    int counter = 0, endCount, startCount;
    cout << "Enter start date: ";
    cin >> start;
    cout << "Enter end date: ";
    cin >> end;

    ifstream reservoir("Current_Reservoir_Levels.tsv");
    if (reservoir.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    getline(reservoir, header);

    while (reservoir >> date >> eastSt >> eastEl >> westSt >> westEl) {
        reservoir.ignore(INT_MAX, '\n');
        dateArray[counter] = date;
        westArray[counter] = westEl;
        if (date == start) {
            startCount = counter;
        }
        if (date == end) {
            endCount = counter;
        }
        counter++;
    }

    while (startCount != endCount + 1) {
        west = westArray[endCount];
        cout << dateArray[endCount] << " " << west << " ft" << endl;
        endCount--;
    }

    reservoir.close();
    return 0;
}