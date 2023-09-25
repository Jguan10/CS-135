/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: minmax, lab 3B
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {
    double max = 0, min = 100;
    double eastSt;
    string header, date;

    ifstream reservoir ("Current_Reservoir_Levels.tsv");
    if (reservoir.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    getline (reservoir, header);
    while (reservoir >> date >> eastSt) {
        reservoir.ignore(INT_MAX, '\n');
        if (eastSt > max) {
            max = eastSt;
        }
        if (eastSt < min) {
            min = eastSt;
        }
    }

    cout << "minimum storage in East basin: " << min << " billion gallons" << endl;
    cout << "MAXimum storage in East basin: " << max << " billion gallons";

    reservoir.close();
    return 0;
}