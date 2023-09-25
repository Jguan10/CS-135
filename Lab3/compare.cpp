/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: compare, lab 3C
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {
    string header, start, end, date, dateArray[365];
    double eastEl, westEl, eastArray[365], westArray[365], east, west, eastSt, westSt;
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
        eastArray[counter] = eastEl;
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
        east = eastArray[startCount];
        west = westArray[startCount];
        if (east > west) {
            cout << dateArray[startCount] << " East" << endl;
        }
        else if (east < west) {
            cout << dateArray[startCount] << " West" << endl;
        }
        startCount++;
    }

    reservoir.close();
    return 0;
}
