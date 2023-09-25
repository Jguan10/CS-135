/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Quiz5, lab 6
*/

int max3(int a, int b, int c) {
    if (a > b) {
        if (a > c) {
            return a;
        }
        else {
            return c;
        }
    }
    else if (b > a) {
        if (b > c) {
            return b;
        }
        else {
            return c;
        }
    }
}
