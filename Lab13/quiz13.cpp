/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: quiz13.cpp
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector(int n) {
    vector<int> positive;
    if(n > 0) {
        for(int i = 0; i < n; i++) {
            positive.push_back(n - i);
        }
        positive.push_back(0);
    }
    return positive;
}

int main() {
    return 0;
}