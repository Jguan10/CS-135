/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Quiz 10, lab 10
*/

#include <iostream>
#include <string>

using namespace std;

class Date {
public:
    int month;
    int day;
    int year;
};

string formatDate(Date * d) {
    string m;
    if(d->month == 1) {
        m = "Jan";
    }
    else if(d->month == 2) {
        m = "Feb";
    }
    else if(d->month == 3) {
        m = "Mar";
    }
    else if(d->month == 4) {
        m = "Apr";
    }
    else if(d->month == 5) {
        m = "May";
    }
    else if(d->month == 6) {
        m = "Jun";
    }
    else if(d->month == 7) {
        m = "Jul";
    }
    else if(d->month == 8) {
        m = "Aug";
    }
    else if(d->month == 9) {
        m = "Sep";
    }
    else if(d->month == 10) {
        m = "Oct";
    }
    else if(d->month == 11) {
        m = "Nov";
    }
    else if(d->month == 12) {
        m = "Dec";
    }
    int dd = d->day;
    int yy = d->year;
    string days = to_string(dd);
    string y = to_string(yy);
    string output = m + " " + days + ", " + y;
    return output;  
}

int main() {
    return 0;
}