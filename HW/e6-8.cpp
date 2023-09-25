/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E6.20
*/

#include <iostream>

using namespace std;

bool equals(int a[], int a_size, int b[], int b_size) {
    if(a_size == b_size) {
        for(int i = 0; i < a_size; i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}

int main() {
    return 0;
}