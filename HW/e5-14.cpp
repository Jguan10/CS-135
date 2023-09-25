/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E5.14
*/

#include <iostream>

using namespace std;

void sort2(int& a, int& b) {
    int holder;
    if(a > b) {
        holder = b;
        b = a;
        a = holder;
    }
}

int main() {
    int a,b;
    cout << "Input the values for int 1: " << endl;
    cin >> a;
    cout << "Input the value for int 2: " << endl;
    cin >> b;
    sort2(a,b);
    cout << a << b << endl;

    return 0;
}