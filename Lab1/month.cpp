 /**
    @file month.cpp
    @author Jiaxiong Guan
    @date 2023-1-26
 */

#include <iostream>
using namespace std;

int main() {
    int year = 0;
    int month = 0;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter Month: ";
    cin >> month;

    if (month == 2) {
        if (year % 4 == 0 && year % 100 != 0) {
            cout << "29";
        }
        else if (year % 400 == 0) {
            cout << "29";
        }
        else {
            cout << "28";
        }
    }
    else if ((month % 2 != 0 && month < 8) || (month >= 8 && month % 2 == 0)) {
        cout << "31";
    }
    else if ((month % 2 == 0 && month < 8) || (month >= 8 && month % 2 != 0)) {
        cout << "30";
    }
    return 0;
}