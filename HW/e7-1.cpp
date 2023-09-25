/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E7.1
*/

#include <iostream>

using namespace std;

void sort2(double* p, double * q){
    double holder = *p;
    if ((*p) > (*q)) {
        *p = *q;
        *q = holder;
    }
}

int main() {
    double a = 5.2, b = 3.2;
    sort2(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}