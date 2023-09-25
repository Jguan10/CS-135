/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E5.15
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

void sort3(int& a, int& b, int& c) {
    sort2(a,b);
    sort2(b,c);
    sort2(a,c);
    sort2(a,b);
}

int main() {
    int a,b,c;
    cout << "Input the values for int 1: " << endl;
    cin >> a;
    cout << "Input the value for int 2: " << endl;
    cin >> b;
    cout << "Input the value for int 3: " << endl;
    cin >> c;
    sort3(a,b,c);
    cout << a << b << c << endl;

    return 0;
}